PROJECT(translateJT)

MESSAGE("------------------------translatejt--------------------------")


###½¨寻找engin .cmake文件
find_package(Eigen3 3.2.0 REQUIRED)
###½¨engin

INCLUDE_DIRECTORIES(
	${CONAN_INCLUDE_DIRS_BOOST_RELEASE}
	${CONAN_INCLUDE_DIRS_MODELDRIVE_RELEASE}/ggp
##	${CONAN_INCLUDE_DIRS_OPENCASCADE_RELEASE}
#	${CONAN_INCLUDE_DIRS_OPENNURBS_RELEASE}
	.
    )

INCLUDE_DIRECTORIES(
	.
	Standard
##ÐÞ¸Ä£¬¼ÓÈë#includeÄ¿Â¼Â·¾¶
#TKJT/src/JtAttribute
#TKJT/src/JtData
#TKJT/src/JtNode
#TKJT/src/JtDecode
#TKJT/src/JtElement
#TKJT/src/JtProperty
#TKJT/src/JtToTopoDS

${OTHERS_DIR}/TKJT/src/JtAttribute
${OTHERS_DIR}/TKJT/src/JtData
${OTHERS_DIR}/TKJT/src/JtNode
${OTHERS_DIR}/TKJT/src/JtDecode
${OTHERS_DIR}/TKJT/src/JtElement
${OTHERS_DIR}/TKJT/src/JtProperty
${OTHERS_DIR}/TKJT/src/JtToTopoDS

${OTHERS_DIR}/OCCTinc

##change
${TBB_DIR}/tbb/internal
${TBB_DIR}/tbb
##！
#！tbb/internal
#！tbb
##


###¼ÓÈëeigin
${EIGEN3_INCLUDE_DIR}
###¼ÓÈëeigin
    )

LINK_DIRECTORIES(${CONAN_LIB_DIRS_BOOST_DEBUG})	
LINK_DIRECTORIES(${CONAN_LIB_DIRS_BOOST_RELEASE})

LINK_DIRECTORIES(
	${BIN_DIR}
##	${CONAN_LIB_DIRS_OPENCASCADE_RELEASE}
	)

FILE(GLOB PROJECT_SOURCE_FILES *.txt)
FILE(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES}
	Standard/*.cpp
    Standard/*.h
	Exchange/*.cpp
	Exchange/*.h
##！
#TKJT/src/JtAttribute/*
#TKJT/src/JtData/*
#TKJT/src/JtDecode/*
#TKJT/src/JtElement/*
#TKJT/src/JtNode/*
#TKJT/src/JtProperty/*
#TKJT/src/JtToTopoDS/*

CMake/*.cmake
#!inc/*


##！
#！tbb/*.h
#！tbb/internal/*
##


    )


ADD_EXECUTABLE(translatejt ${PROJECT_SOURCE_FILES})

#################################ÐÞ¸Ä
#¼Ótbb_debug.lib£¬tbb.lib£¬tbbmolloc.lib

LINK_LIBRARIES(${TBB_DIR}/bin/tbb_debug.lib )
TARGET_LINK_LIBRARIES(translatejt ${TBB_DIR}/bin/tbb_debug.lib)

LINK_LIBRARIES(${TBB_DIR}/bin/tbb.lib )
TARGET_LINK_LIBRARIES(translatejt ${TBB_DIR}/bin/tbb.lib)

LINK_LIBRARIES(${TBB_DIR}/bin/tbbmalloc.lib )
TARGET_LINK_LIBRARIES(translatejt ${TBB_DIR}/bin/tbbmalloc.lib)


#¼ÓocctµÄÁ½¸ölib£¬³¢ÊÔ½â¾ölnk 2001 error
LINK_LIBRARIES(${OTHERS_DIR}/bin/TKernel.lib )
TARGET_LINK_LIBRARIES(translatejt ${OTHERS_DIR}/bin/TKernel.lib)

LINK_LIBRARIES(${OTHERS_DIR}/bin/TKMath.lib )
TARGET_LINK_LIBRARIES(translatejt ${OTHERS_DIR}/bin/TKMath.lib)

#¼ÓTKJT
LINK_LIBRARIES(${OTHERS_DIR}/bin/TKJT.lib )
TARGET_LINK_LIBRARIES(translatejt ${OTHERS_DIR}/bin/TKJT.lib)
#######################



TARGET_LINK_LIBRARIES(translatejt CONAN_PKG::Poco)
TARGET_LINK_LIBRARIES(translatejt CONAN_PKG::modeldrive)
##TARGET_LINK_LIBRARIES(translatejt CONAN_PKG::opencascade)
#TARGET_LINK_LIBRARIES(translatejt rpcrt4 shlwapi) 
#TARGET_LINK_LIBRARIES(translatejt debug ${CONAN_BIN_DIRS_OPENNURBS_DEBUG}/opennurbs_public_staticlib.lib)
#TARGET_LINK_LIBRARIES(translatejt optimized ${CONAN_BIN_DIRS_OPENNURBS_RELEASE}/opennurbs_public_staticlib.lib)

SET(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})


##¼Ótbb_debug.dll
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${TBB_DIR}/bin\\tbb_debug.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
##¼ÓTKMathºÍTKernel
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\TKMath.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\TKernel.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
##¼ÓTKJT.dll
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\TKJT.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)

#####

add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\OCC691bin\\*.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)


#####



add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\zlibd.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)


add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${TBB_DIR}/bin\\tbb.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${TBB_DIR}/bin\\tbbmalloc.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\freetype.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\FreeImage.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\avcodec-57.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\avformat-57.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\avutil-55.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\swscale-4.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)
add_custom_command(TARGET translatejt POST_BUILD COMMAND xcopy \"${OTHERS_DIR}/bin\\swresample-2.dll\"  \"${EXECUTABLE_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}\" /y)

SOURCE_GROUP_BY_DIR(PROJECT_SOURCE_FILES)

SET_PROPERTY(TARGET translatejt  PROPERTY FOLDER "Tool")

install (TARGETS translatejt DESTINATION bin)
