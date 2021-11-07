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


std::vector<Handle(JtNode_Shape_TriStripSet)> JSTvec;//�������ÿ��������Ƭ����JtNode_Shape_TriStripSetҶ�ӽ��


//�ڵ�����ʶ��,ÿһ��node��jt�������ļ��ж���һ���ض���ʮ������id���ɼ�jt �ٷ��ĵ�v8 p277
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

	//------------------------�ļ��Ķ�ȡ-----------------------
	//��inputFileNameת��Ϊ����TCollection_ExtendedString
	TCollection_ExtendedString my_theFile_TEstring = TCollection_ExtendedString(inputFileName.data(), 1);

	Handle(JtData_Model) my_model = new JtData_Model(my_theFile_TEstring);

	Handle(JtNode_Partition) my_RootNode = my_model->Init();//��ȡlsg�ṹ���ĸ��ڵ�

	std::ifstream my_theFile(inputFileName, ios::binary || ios::in);

	const std::ifstream::pos_type theOffset = -1;
	
	JtData_FileReader myFileReader(my_theFile, my_model, theOffset);
	//���캯������ʼ��ʵ��my_theFile���JtData_FileReader��Ա* myFile.
	//Ҳ��jtdata reader�����˳�ʼ��JtData_Reader (my_model)


	//---------------------------��ȵݹ����������JtNode_Shape_TriStripSet*---------------------------

	PushNode(my_RootNode);//�ݹ���������Handle(JtNode_Shape_TriStripSet)��JSTvec


	//---ת��---
	auto defaultMaterial = std::make_shared<md::Material>(std::to_string(-1));
	defaultMaterial->SetDoubleSide(true);
	m_Manager.AddMaterial(defaultMaterial);


	m_Scene = std::make_shared<md::Scene>("jt");

	for (int i=0;i<JSTvec.size();i++)//����ÿ���������ݼ��ϣ���ӵ�md��node
	{	    
		AddMaterial(i, JSTvec[i]);

		AddMDMesh(i,JSTvec[i]);	
		
	}

	//���scene������manager
	m_Scene->ComputeTransform();

	m_Manager.AddScene(m_Scene);

	m_Manager.Save();

	m_Scene = nullptr;
	return true;

}//run ����
     
		
    //---------------------------Ϊ��һ���ṩmyshape----------------------------------------

	void  JtFileExchange::PushNode(Handle(JtNode_Base)& theNodeRecord)
	{
		
		//jt�涨��һ���ڵ���JtNode_Partition����
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

			//�ݹ飡
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


		//һ���ڵ������ڵ�����ã����ĵ�˵������ã�JT ass����Ҳ��ֱ���Թ�
		else if (theNodeRecord->IsKind(TypeOf_JtNode_Instance))
		{
			Handle(JtNode_Instance) anInstance = Handle(JtNode_Instance)::DownCast(theNodeRecord);
			Handle(JtNode_Base) aNode = Handle(JtNode_Base)::DownCast(anInstance->Object());
			PushNode(aNode);
		
		}


		//����Ž���-------------theNodeRecord����Ϊ-JtNode_Shape_Vertex
		//��Ϊ��Ҷ�ӽ�㣬û��fillgroup��
		else if (theNodeRecord->IsKind(TypeOf_JtNode_Shape_Vertex))
		{
			Handle(JtNode_Shape_Vertex) aShapeRecord = Handle(JtNode_Shape_Vertex)::DownCast(theNodeRecord);

			if (aShapeRecord->IsKind(TypeOf_JtNode_Shape_TriStripSet))//��Ϊjt��ֻ��������Ƭ����
			{
				//Handle(JtNode_Shape_TriStripSet)�ĳ�ʼ��
				Handle(JtNode_Shape_TriStripSet) aMeshRecord = Handle(JtNode_Shape_TriStripSet)::DownCast(aShapeRecord);

				JSTvec.push_back(aMeshRecord);
				
			}
		}
		return;

	}//pushnode����


	//-------------��PushNode������ϣ���ÿ�ֽڵ����͵ĺ��Ӷ���������-----------
	void JtFileExchange::FillGroup(Handle(JtNode_Group)& theGroupRecord)
	{
		if (theGroupRecord->Children().IsEmpty())//�ݹ���ֹ����
			return;

		for (Standard_Integer aChildIdx = 0; aChildIdx < (Standard_Integer)theGroupRecord->Children().Count(); ++aChildIdx)
		{
			//������ת��������PushNode
			Handle(JtNode_Base) aChildRecord = Handle(JtNode_Base)::DownCast(theGroupRecord->Children()[aChildIdx]);

			if (aChildRecord.IsNull())
			{
				continue;
			}
			PushNode(aChildRecord);
		}
	}



	//-----------------��JtNode_Shape_TriStripSetҶ�ӽ��ת��Ϊmd������--------------------------
	void JtFileExchange::AddMDMesh(int idx,Handle(JtNode_Shape_TriStripSet JSTNode))
	{
		Handle(JtNode_Shape_TriStripSet) myShape = JSTNode;


		const JtData_Object::VectorOfLateLoads& aLateLoaded = myShape->LateLoads();
		if (aLateLoaded.IsEmpty())
		{
			md::SdkUtil::LogError("[Error] no late-loaded data. return");
			return;
		}

			
		//aLateLoaded[0]->Read(myFileReader);//������һ����read���Ѿ�����mySegModel��mySegOffset������ʡ��

		//ͨ���ϵ�debug��anobjectû���سɹ�Ϊnull��û��lateload����jtass ����������˶��̣߳�
		aLateLoaded[0]->Load();//���д�����lateload����
		


		Handle(JtData_Object) anObject = aLateLoaded[0]->DefferedObject();

		Handle(JtElement_ShapeLOD_TriStripSet) aLOD = Handle(JtElement_ShapeLOD_TriStripSet)::DownCast(anObject);

		auto vercnt = aLOD->Vertices().Count();
		auto indcnt = aLOD->Indices().Count();
		auto norcnt = aLOD->Normals().Count();

		auto ver1 = aLOD->Vertices().Data();
		auto ind1 = aLOD->Indices().Data();
		auto nor1 = aLOD->Normals().Data();


		auto ver = aLOD->Vertices();//������[i]���������xyz��[i][j]
		auto ind = aLOD->Indices();//����
		auto nor = aLOD->Normals();//������


		 //--------------˵��md������--------------
		md::Vector3List positions;
		md::Vector3List pb;
		md::Vector3List nb;
		md::UIntList ib;
		md::BBox3f bbox;

		//--------------------д���ظ���position------------------------

		for (int i = 0; i < vercnt; i++)
		{
			auto vertex = md::Vector3(ver[i][0], ver[i][1], ver[i][2]);//ÿ�������xyz
			positions.push_back(vertex);
		}

		//------------------------��ʼ��pb,ib------------------------------

		auto facecnt = indcnt / 3;//�����������
		for (int i = 0; i < facecnt; i++)//����ÿ����
		{

			// a b c��ÿ��������Ķ��㣬����xyz	

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


		//---------------�浽md��meshnode--------

		auto mesh = std::make_shared<md::Mesh>(pb, nb, ib, bbox);

		m_Manager.AddMesh(mesh->GetId(), mesh);

		auto meshNode = std::make_shared<md::MeshNode>();
		meshNode->SetBoundingBox(bbox);
		meshNode->SetMeshId(mesh->GetId());

		//����ɫ��
		meshNode->SetMaterialId(std::to_string(idx));

		auto pNode = meshNode;
		if (pNode)
		{
			m_Scene->AddNode(pNode);
			pNode->SetUserId(std::to_string(++m_MeshCount));
		}

	}



	//-------------------------��ȡMaterial---------------
	    //����������������������������������������������������������������������������������
		/*
		��ÿһ�ڵ�(����theNodeRecord�Ѿ���Ҷ�ӽ��JST node��)�����Ե���ȡ��JST�ڵ㼴ÿһ��������Ƭ��
		��CAD exchanger�ɼ����Ƕ�ÿ��JST�ڵ�����Ժ���ɫ����Щjstnode���е�һ�����ԣ�����ת��������Щ���еڶ������ԣ���ɫ��
		�������ص���Ҫ�޸���ӵĵط����ɲο�jt ass��pushnode������jt ass��Ҫ�������价��������һ���readme�ĵ�˵��
		*/
		//����������������������������������������������������������������������������������

	void JtFileExchange::AddMaterial(int idx, Handle(JtNode_Shape_TriStripSet JSTNode)) {

		//��������Ե�mat
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

			//ÿ��Ҷ�ӽ����ܻ��ж��anattribute��������ͬ�Ķ��������


			//-------------------���Եĵ�һ��type-����任----------------------
			//��ȡת������4*4����ѧ�˹���Ҳ���������ˣ�����tkjt��֧��v10�汾��Ȼ��Ͳ���һ����
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
				
				//Eigen::Matrix4f myTransformInversed = aMatrix.inverse();//����


				//!!!!!!!!���õ�4*4���󣬵���һֱû����jt assistant���ҵ���ôȥ��
				//��jt v8.1�ٷ���ʽ�ĵ�p99��˵��p`=p*A*M
			}



			//-------------���Եĵڶ���type-��ɫ---------------
			
			else if (anAttrib->IsKind(TypeOf_JtAttribute_Material))
			{

				Handle(JtAttribute_Material) aMaterial =
					Handle(JtAttribute_Material)::DownCast(anAttrib);

				//�������������ĸ�ֵ,�����Ҫ�ο�jt ass��������,������ֻȡǰ����ֵ
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

		//ע�⣺��������Ȼһ��jst�ж��type2 color���������ǵ�colorֵ����һ���ģ�����������ֻȡ���һ��
		mat->SetColor(DiffuseColor);
		
		mat->SetSpecular(SpecularColor);
		mat->SetShininess(Shininess);

		mat->SetEmissive(EmissionColor);
		mat->SetEnvironment(AmbientColor);
		mat->SetReflectivity(Reflectivity);

		mat->SetDoubleSide(true);

	
		m_Manager.AddMaterial(mat);


	}