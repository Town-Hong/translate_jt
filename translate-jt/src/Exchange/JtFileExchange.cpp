#include <experimental/filesystem>
#include <JtData_Reader.hxx>
#include <JtData_Model.hxx>

#include <JtNode_Part.hxx>
#include <JtNode_RangeLOD.hxx>
#include <JtNode_Instance.hxx>
#include <JtNode_Partition.hxx>
#include <JtNode_Shape_TriStripSet.hxx>
#include <JtElement_ShapeLOD_TriStripSet.hxx>
#include <JtAttribute_GeometricTransform.hxx>
#include <JtAttribute_Material.hxx>
#include <JtNode_Partition.hxx>
#include <JtData_FileReader.hxx>
#include <JtNode_Part.hxx>
#include <typeinfo>
#include <iostream>
#include <JtNode_Shape_TriStripSet.hxx>
#include <JtElement_ShapeLOD_TriStripSet.hxx>
#include <vector>


#include "JtFileExchange.h"


JtFileExchange::JtFileExchange(md::ModelManager& mgr)
	:m_Manager(mgr) 
	, m_MeshCount(0)
{
}
JtFileExchange::~JtFileExchange()
{
}


std::vector<Handle(JtNode_Shape_TriStripSet)> JSTvec;//遍历后存每个三角面片，即JtNode_Shape_TriStripSet叶子结点


//节点类型识别,每一个node在jt二进制文件中都有一个特定的十六进制id，可见jt 官方文档v8 p277
//
static Handle(Standard_Type) TypeOf_JtNode_Partition = STANDARD_TYPE(JtNode_Partition);
static Handle(Standard_Type) TypeOf_JtNode_Part = STANDARD_TYPE(JtNode_Part);
static Handle(Standard_Type) TypeOf_JtNode_RangeLOD = STANDARD_TYPE(JtNode_RangeLOD);
static Handle(Standard_Type) TypeOf_JtNode_LOD = STANDARD_TYPE(JtNode_LOD);
static Handle(Standard_Type) TypeOf_JtNode_Group = STANDARD_TYPE(JtNode_Group);
static Handle(Standard_Type) TypeOf_JtNode_Instance = STANDARD_TYPE(JtNode_Instance);
static Handle(Standard_Type) TypeOf_JtNode_Shape_Vertex = STANDARD_TYPE(JtNode_Shape_Vertex);
static Handle(Standard_Type) TypeOf_JtNode_Shape_TriStripSet = STANDARD_TYPE(JtNode_Shape_TriStripSet);
static Handle(Standard_Type) TypeOf_JtAttribute_Material = STANDARD_TYPE(JtAttribute_Material);
static Handle(Standard_Type) TypeOf_JtAttribute_GeometricTransform = STANDARD_TYPE(JtAttribute_GeometricTransform);
//---end


bool JtFileExchange::Run(const std::string & inputFileName)
{

	//------------------------文件的读取-----------------------
	//将inputFileName转换为类型TCollection_ExtendedString
	TCollection_ExtendedString my_theFile_TEstring = TCollection_ExtendedString(inputFileName.data(), 1);

	Handle(JtData_Model) my_model = new JtData_Model(my_theFile_TEstring);

	Handle(JtNode_Partition) my_RootNode = my_model->Init();//获取lsg结构树的根节点

	std::ifstream my_theFile(inputFileName, ios::binary || ios::in);

	const std::ifstream::pos_type theOffset = -1;
	
	JtData_FileReader myFileReader(my_theFile, my_model, theOffset);
	//构造函数，初始化实例my_theFile变成JtData_FileReader成员* myFile.
	//也对jtdata reader进行了初始化JtData_Reader (my_model)


	//---------------------------深度递归遍历树，存JtNode_Shape_TriStripSet*---------------------------

	PushNode(my_RootNode);//递归遍历，添加Handle(JtNode_Shape_TriStripSet)到JSTvec


	//---转换---
	auto defaultMaterial = std::make_shared<md::Material>(std::to_string(-1));
	defaultMaterial->SetDoubleSide(true);
	m_Manager.AddMaterial(defaultMaterial);


	m_Scene = std::make_shared<md::Scene>("jt");

	for (int i=0;i<JSTvec.size();i++)//遍历每个三角数据集合，添加到md的node
	{	    
		AddMaterial(i, JSTvec[i]);

		AddMDMesh(i,JSTvec[i]);	
		
	}

	//添加scene，启动manager
	m_Scene->ComputeTransform();

	m_Manager.AddScene(m_Scene);

	m_Manager.Save();

	m_Scene = nullptr;
	return true;

}//run 结束
     
		
    //---------------------------为上一步提供myshape----------------------------------------

	void  JtFileExchange::PushNode(Handle(JtNode_Base)& theNodeRecord)
	{
		
		//jt规定第一个节点是JtNode_Partition类型
		if (theNodeRecord->IsKind(TypeOf_JtNode_Partition))
		{
			Handle(JtNode_Partition) aPartitionRecord =
				Handle(JtNode_Partition)::DownCast(theNodeRecord);

			/*
			if (aPartitionRecord->FileName().Length() <= 0)
			{
				std::cout<<"PushNode,Error! Failed to create partition node"<<std::endl;
			}
			*/

			//递归！
			FillGroup(aPartitionRecord);
		}



		else if (theNodeRecord->IsKind(TypeOf_JtNode_Part))
		{
					
			FillGroup(Handle(JtNode_Group)::DownCast(theNodeRecord));
		}



		else if (theNodeRecord->IsKind(TypeOf_JtNode_RangeLOD))
		{
		
			Handle(JtNode_RangeLOD) aRangeLODRecord =Handle(JtNode_RangeLOD)::DownCast(theNodeRecord);

			FillGroup(aRangeLODRecord);

			/*
			aRangeLODRecord->Center() = Eigen::Vector4f(
				static_cast<Standard_ShortReal> (aRangeLODRecord->Center().X),
				static_cast<Standard_ShortReal> (aRangeLODRecord->Center().Y),
				static_cast<Standard_ShortReal> (aRangeLODRecord->Center().Z),
				1.0);
				vector vector1;
			if (!aRangeLODRecord->RangeLimits().IsEmpty())
			{
				for (Standard_Integer anIdx = 1; anIdx <= aRangeLODRecord->RangeLimits().Count(); ++anIdx)
				{
					vector1.push_back(aRangeLODRecord->RangeLimits()[anIdx]->Ranges());
				}
			}
			else
			{
				vector1.push_back(std::numeric_limits<Standard_ShortReal>::max());

				for (Standard_Integer anIdx = 1; anIdx < (Standard_Integer)aRangeLODRecord->Children().Count(); ++anIdx)
				{
					vector.push_back(0.0);
				}
			}
			*/
		}


		else if (theNodeRecord->IsKind(TypeOf_JtNode_LOD))
		{
			FillGroup(Handle(JtNode_Group)::DownCast(theNodeRecord));
		}


		else if (theNodeRecord->IsKind(TypeOf_JtNode_Group))
		{
			FillGroup(Handle(JtNode_Group)::DownCast(theNodeRecord));
		}


		//一个节点对另外节点的引用，但文档说这个不用，JT ass代码也是直接略过
		else if (theNodeRecord->IsKind(TypeOf_JtNode_Instance))
		{
			Handle(JtNode_Instance) anInstance = Handle(JtNode_Instance)::DownCast(theNodeRecord);
			Handle(JtNode_Base) aNode = Handle(JtNode_Base)::DownCast(anInstance->Object());
			PushNode(aNode);
		
		}


		//这里才讲到-------------theNodeRecord必须为-JtNode_Shape_Vertex
		//因为是叶子结点，没有fillgroup了
		else if (theNodeRecord->IsKind(TypeOf_JtNode_Shape_Vertex))
		{
			Handle(JtNode_Shape_Vertex) aShapeRecord = Handle(JtNode_Shape_Vertex)::DownCast(theNodeRecord);

			if (aShapeRecord->IsKind(TypeOf_JtNode_Shape_TriStripSet))//因为jt不只有三角面片这种
			{
				//Handle(JtNode_Shape_TriStripSet)的初始化
				Handle(JtNode_Shape_TriStripSet) aMeshRecord = Handle(JtNode_Shape_TriStripSet)::DownCast(aShapeRecord);

				JSTvec.push_back(aMeshRecord);
				
			}
		}
		return;

	}//pushnode结束


	//-------------与PushNode函数配合，把每种节点类型的孩子都遍历完整-----------
	void JtFileExchange::FillGroup(Handle(JtNode_Group)& theGroupRecord)
	{
		if (theGroupRecord->Children().IsEmpty())//递归终止条件
			return;

		for (Standard_Integer aChildIdx = 0; aChildIdx < (Standard_Integer)theGroupRecord->Children().Count(); ++aChildIdx)
		{
			//做类型转换，传入PushNode
			Handle(JtNode_Base) aChildRecord = Handle(JtNode_Base)::DownCast(theGroupRecord->Children()[aChildIdx]);

			if (aChildRecord.IsNull())
			{
				continue;
			}
			PushNode(aChildRecord);
		}
	}



	//-----------------将JtNode_Shape_TriStripSet叶子结点转换为md的数据--------------------------
	void JtFileExchange::AddMDMesh(int idx,Handle(JtNode_Shape_TriStripSet JSTNode))
	{
		Handle(JtNode_Shape_TriStripSet) myShape = JSTNode;


		const JtData_Object::VectorOfLateLoads& aLateLoaded = myShape->LateLoads();
		if (aLateLoaded.IsEmpty())
		{
			md::SdkUtil::LogError("[Error] no late-loaded data. return");
			return;
		}

			
		//aLateLoaded[0]->Read(myFileReader);//不用这一步的read就已经有了mySegModel和mySegOffset，所以省略

		//通过断点debug，anobject没加载成功为null，没有lateload，在jtass 中这个是用了多线程，
		aLateLoaded[0]->Load();//这行代码解决lateload问题
		


		Handle(JtData_Object) anObject = aLateLoaded[0]->DefferedObject();

		Handle(JtElement_ShapeLOD_TriStripSet) aLOD = Handle(JtElement_ShapeLOD_TriStripSet)::DownCast(anObject);

		auto vercnt = aLOD->Vertices().Count();
		auto indcnt = aLOD->Indices().Count();
		auto norcnt = aLOD->Normals().Count();

		auto ver1 = aLOD->Vertices().Data();
		auto ind1 = aLOD->Indices().Data();
		auto nor1 = aLOD->Normals().Data();


		auto ver = aLOD->Vertices();//顶点用[i]，具体各个xyz用[i][j]
		auto ind = aLOD->Indices();//索引
		auto nor = aLOD->Normals();//法向量


		 //--------------说明md的数据--------------
		md::Vector3List positions;
		md::Vector3List pb;
		md::Vector3List nb;
		md::UIntList ib;
		md::BBox3f bbox;

		//--------------------写不重复的position------------------------

		for (int i = 0; i < vercnt; i++)
		{
			auto vertex = md::Vector3(ver[i][0], ver[i][1], ver[i][2]);//每个顶点的xyz
			positions.push_back(vertex);
		}

		//------------------------初始化pb,ib------------------------------

		auto facecnt = indcnt / 3;//三角面的数据
		for (int i = 0; i < facecnt; i++)//遍历每个面
		{

			// a b c是每个三角面的顶点，包含xyz	

			const auto& a = positions[ind[3 * i]];
			const auto& b = positions[ind[3 * i + 1]];
			const auto& c = positions[ind[3 * i + 2]];

			pb.push_back(a);
			pb.push_back(b);
			pb.push_back(c);

			bbox.MergeBox(a);
			bbox.MergeBox(b);
			bbox.MergeBox(c);

			md::Vector3 normal = (c - b).CrossProduct(a - b);
			//normal = transform3x3(normal, trf);
			normal.Normalize();

			nb.push_back(normal);
			nb.push_back(normal);
			nb.push_back(normal);


			ib.push_back(3 * i);
			ib.push_back(3 * i + 1);
			ib.push_back(3 * i + 2);


			//tb.push_back();


		}


		//---------------存到md的meshnode--------

		auto mesh = std::make_shared<md::Mesh>(pb, nb, ib, bbox);

		m_Manager.AddMesh(mesh->GetId(), mesh);

		auto meshNode = std::make_shared<md::MeshNode>();
		meshNode->SetBoundingBox(bbox);
		meshNode->SetMeshId(mesh->GetId());

		//绑定颜色？
		meshNode->SetMaterialId(std::to_string(idx));

		auto pNode = meshNode;
		if (pNode)
		{
			m_Scene->AddNode(pNode);
			pNode->SetUserId(std::to_string(++m_MeshCount));
		}

	}



	//-------------------------获取Material---------------
	    //！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
		/*
		对每一节点(到这theNodeRecord已经是叶子结点JST node了)做属性的提取，JST节点即每一个三角面片集
		由CAD exchanger可见，是对每个JST节点加属性和颜色，有些jstnode具有第一种属性（矩阵转换），有些具有第二种属性（颜色）
		下面是重点需要修改添加的地方，可参考jt ass的pushnode函数，jt ass需要在重新配环境，这个我会在readme文档说明
		*/
		//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

	void JtFileExchange::AddMaterial(int idx, Handle(JtNode_Shape_TriStripSet JSTNode)) {

		//搞个存属性的mat
		auto mat = std::make_shared<md::Material>(std::to_string(idx));
		model_drive::ColorValue SpecularColor;
		model_drive::ColorValue DiffuseColor;
		model_drive::ColorValue AmbientColor;
		model_drive::ColorValue EmissionColor;
		float Shininess;
		float Reflectivity;


		Handle(JtNode_Shape_TriStripSet) theNodeRecord = JSTNode;

		if (theNodeRecord->Attributes().IsEmpty())
			return;

		for (Standard_Integer anIdx = 0; anIdx < (Standard_Integer)theNodeRecord->Attributes().Count(); ++anIdx)
		{
			const Handle(JtData_Object)& anObject = theNodeRecord->Attributes()[anIdx];

			if (anObject.IsNull())
				continue;

			Handle(JtAttribute_Base) anAttrib = Handle(JtAttribute_Base)::DownCast(anObject);

			//每个叶子结点可能会有多个anattribute，包含不同的多个的属性


			//-------------------属性的第一种type-矩阵变换----------------------
			//获取转换矩阵！4*4，开学了工作也就做到这了，除了tkjt不支持v10版本，然后就差这一步了
			if (anAttrib->IsKind(TypeOf_JtAttribute_GeometricTransform))
			{
				Handle(JtAttribute_GeometricTransform) aTransform =
					Handle(JtAttribute_GeometricTransform)::DownCast(anAttrib);

				Eigen::Matrix4f aMatrix;

				for (Standard_Integer aX = 0; aX < 4; ++aX)
				{
					for (Standard_Integer aY = 0; aY < 4; ++aY)
					{
						aMatrix(aX, aY) = static_cast<Standard_ShortReal> (aTransform->GetTrsf()[aY * 4 + aX]);
					}
				}

				if (aMatrix(3, 3) == 0.f)
				{
					aMatrix(3, 3) = 1.f; // fix problem with homogeneous coordinates
				}
				
				//Eigen::Matrix4f myTransformInversed = aMatrix.inverse();//求逆


				//!!!!!!!!能拿到4*4矩阵，但是一直没有在jt assistant中找到怎么去乘
				//在jt v8.1官方格式文档p99有说到p`=p*A*M
			}



			//-------------属性的第二种type-颜色---------------
			
			else if (anAttrib->IsKind(TypeOf_JtAttribute_Material))
			{

				Handle(JtAttribute_Material) aMaterial =
					Handle(JtAttribute_Material)::DownCast(anAttrib);

				//很奇怪最后是有四个值,因该需要参考jt ass做操作的,最后好像只取前三个值
				DiffuseColor = md::ColorValue(aMaterial->DiffuseColor()[0] * 255,
					aMaterial->DiffuseColor()[1] * 255,
					aMaterial->DiffuseColor()[2] * 255);

				SpecularColor = md::ColorValue(aMaterial->SpecularColor()[0] * 255,
					aMaterial->SpecularColor()[1] * 255,
					aMaterial->SpecularColor()[2] * 255);

				Shininess = aMaterial->Shininess();

				
				AmbientColor=md::ColorValue(aMaterial->AmbientColor()[0] * 255,
						aMaterial->AmbientColor()[1] * 255,
						aMaterial->AmbientColor()[2] * 255);
				
			    EmissionColor = md::ColorValue(aMaterial->EmissionColor()[0] * 255,
						aMaterial->EmissionColor()[1] * 255,
						aMaterial->EmissionColor()[2] * 255);

				Reflectivity = aMaterial->Reflectivity();

			}
		}

		//注意：！！！虽然一个jst有多个type2 color，但是他们的color值都是一样的！！！，所以只取最后一次
		mat->SetColor(DiffuseColor);
		
		mat->SetSpecular(SpecularColor);
		mat->SetShininess(Shininess);

		mat->SetEmissive(EmissionColor);
		mat->SetEnvironment(AmbientColor);
		mat->SetReflectivity(Reflectivity);

		mat->SetDoubleSide(true);

	
		m_Manager.AddMaterial(mat);


	}