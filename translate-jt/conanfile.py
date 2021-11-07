import os
from conans import ConanFile, CMake, tools

class MyConan(ConanFile):
    name = "translate-jt"
    #version = "1.0.0"
    url = "xxxxxxxxxxxxxxxxxxxxxx"
    description = "translate-jt"
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"

 # 可在此拷贝文件到自己的工程目录，例如SDK的dll文件
    def imports(self):
        path = "../../bin/vc{0}/x64/{1}".format(self.settings.compiler.version, self.settings.build_type)
        self.copy("*.dll", dst=path, src="bin", root_package="modeldrive", excludes="xxxxxxxx")
        if self.settings.build_type == "Debug":
        	self.copy("PocoData64d.dll", dst=path, src="bin", root_package="Poco")
        	self.copy("PocoDataSQLite64d.dll", dst=path, src="bin", root_package="Poco")
        	self.copy("PocoFoundation64d.dll", dst=path, src="bin", root_package="Poco")
        else:
        	self.copy("PocoData64.dll", dst=path, src="bin", root_package="Poco")
        	self.copy("PocoDataSQLite64.dll", dst=path, src="bin", root_package="Poco")
        	self.copy("PocoFoundation64.dll", dst=path, src="bin", root_package="Poco")
        
        
        self.copy("opennurbs_public.dll", dst=path, src="bin", root_package="opennurbs")

     ##   occDlls = ['TKHLR.dll', 'TKCDF.dll', 'TKCAF.dll', 'TKService.dll', 'TKV3d.dll', 'TKVCAF.dll', 'TKLCAF.dll', 'TKXCAF.dll', 'TKXDESTEP.dll', 
     ##   'TKernel.dll','TKMath.dll','TKBRep.dll','TKGeomBase.dll','TKGeomAlgo.dll','TKG3d.dll','TKG2d.dll','TKShHealing.dll','TKTopAlgo.dll','TKMesh.dll','TKPrim.dll','TKBool.dll','TKBO.dll','TKFillet.dll','TKSTEP.dll','TKSTEPBase.dll','TKSTEPAttr.dll','TKXSBase.dll','TKSTEP209.dll','TKIGES.dll','TKOffset.dll']
      ##  for dll in occDlls:
   ##         self.copy(dll, dst=path, src="bin", root_package="opencascade")
        
       

    def requirements(self):
        ##self.requires("xxx")
        self.requires("xxx")
        self.requires("modeldrive/xxx")
        #self.requires("boost/xxx")
        self.requires("Poco/xxx")
        


    def build(self):
        cmake = CMake(self)
        cmake.definitions["CONAN_CXX_FLAGS"] = ""
        cmake.configure()
        cmake.build()