#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <experimental/filesystem>
//#include <boost/program_options.hpp>

//#include "Exchange/GeometryTools.h"
//#include "Exchange/GeometryExchange.h"
//#include "Exchange/ShapeTools.h"
//#include "Exchange/Exchange.h"

//--
//#include <TestWriteLines.h>
//#include <MdCommandManager.h>
#include <SdkInclude.h>
#include <SdkModelManager.h>


#include "Exchange/JtFileExchange.h"

using namespace model_drive;

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	std::string fileName;
	//fileName = "C:\\Users\\hongzc\\Desktop\\JTFilesForTest\\conrod.jt"; //ver8.0
	fileName = "C:\\Users\\hongzc\\Desktop\\JTFilesForTest\\butterflyvalve.jt";//8.0
	//fileName = "C:\\Users\\hongzc\\Desktop\\JTFilesForTest\\littercar.jt";//9.5
	//fileName = "C:\\Users\\hongzc\\Desktop\\JTFilesForTest\\harting.jt";//ver9.5
	const std::string strInputPath = fileName;
	const std::string outdir = "d:\\JtOutDir";
	*/

	const std::string OPTION_INPUT = "input";
	const std::string OPTION_OUTDIR = "output";
	const std::string MODEL_UP = "model_up";

	std::unordered_map<std::string, std::string> options;
	options[OPTION_INPUT] = "";
	options[OPTION_OUTDIR] = "";
	options[MODEL_UP] = "z";


	if (!SdkUtil::ParseCommandLine(argc, argv, options))
	{
		return -1;
	}

	if (options[OPTION_INPUT].empty() || options[OPTION_OUTDIR].empty())//属性里命令行加入
	{
		std::cout << "Need --input src.obj --output ourdir --model_up z|y" << std::endl;
		return -1;
	}

	//////////////////////////////////////////////////////////////////////////
	// Parse input file
	const std::string strInputPath = options[OPTION_INPUT];

	std::string modelUp = options[MODEL_UP];//=z
	//boost::algorithm::to_lower(modelUp);
	std::transform(modelUp.begin(), modelUp.end(), modelUp.begin(), ::tolower);//转小写，因为boost库没法用
	const bool zUp = modelUp == "z";
	std::cout << "Model Up: " << modelUp << std::endl;


	ModelManager modelManager;

	auto outDir = options[OPTION_OUTDIR];
	std::experimental::filesystem::path pathOut(outDir);
	std::experimental::filesystem::path outputDir = pathOut.append("/resource/model/");
	if (!std::experimental::filesystem::exists(outputDir))
	{
		std::experimental::filesystem::create_directories(outputDir);
	}
	if (!std::experimental::filesystem::is_directory(outputDir))
		return -1;

	modelManager.Initialize(outputDir.string());
	bool bResult = false;
	try
	{

		auto ext = std::experimental::filesystem::path(strInputPath).extension().string();

		//std::experimental::algorithm::to_lower(ext);
		std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);//转小写，因为boost库没法用
		if (ext == ".jt")
		{
			modelManager.SetWorkerId("jt");
			JtFileExchange exporter(modelManager);
			bResult = exporter.Run(strInputPath);
		}
		else
		{
			std::cout << "not support file format: " << ext << std::endl;
		}
	}
	catch (std::exception ex)
	{
		SdkUtil::LogInfo(ex.what());
		return -1;
	}
	catch (...)
	{
		SdkUtil::LogInfo("Got exception!");
		return -1;
	}
	SdkUtil::LogInfo("Done!");
	return bResult ? 0 : -1;

}
