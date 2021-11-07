#pragma once
#include "stdafx.h"
#include <JtNode_Base.hxx>
#include <JtNode_Group.hxx>
#include <JtNode_Shape_TriStripSet.hxx>
#include <JtElement_ShapeLOD_TriStripSet.hxx>
#include <JtNode_Part.hxx>
#include <experimental/filesystem>
#include <JtData_Reader.hxx>
#include <SdkInclude.h>
#include <SdkModelManager.h>


#include <Eigen/Core> 
using namespace Eigen;


class JtFileExchange {
public:
	JtFileExchange(md::ModelManager& mgr);
	~JtFileExchange();

	bool Run(const std::string& inputFileName);
	
private:
	void AddMDMesh(int idx,Handle(JtNode_Shape_TriStripSet JSTNode));
	void  PushNode(Handle(JtNode_Base)& theNodeRecord);
	void FillGroup(Handle(JtNode_Group)& theGroupRecord);
	void AddMaterial(int idx, Handle(JtNode_Shape_TriStripSet JSTNode));

private:
	const std::string m_outdir;
	md::ModelManager& m_Manager;
	std::shared_ptr<md::Scene> m_Scene;

	int m_MeshCount;
	
};