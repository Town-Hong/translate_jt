cmake_minimum_required(VERSION 2.8.11)


project(Translate.jt)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup(TARGETS NO_OUTPUT_DIRS)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
MACRO( OPTION_WITH_DEFAULT OPTION_NAME OPTION_STRING OPTION_DEFAULT )

	IF( NOT DEFINED ${OPTION_NAME} )
		SET( ${OPTION_NAME} ${OPTION_DEFAULT} )
	ENDIF( NOT DEFINED ${OPTION_NAME} )
	OPTION( ${OPTION_NAME} "${OPTION_STRING}" ${${OPTION_NAME}} )

ENDMACRO( OPTION_WITH_DEFAULT OPTION_NAME OPTION_STRING OPTION_DEFAULT )

############################
# Check 32/64 bit platform #
if (${CMAKE_SIZEOF_VOID_P} MATCHES "8") # It is 64bit, otherwise 32 bit systems match 4
	set(PlatformName x64)
else (${CMAKE_SIZEOF_VOID_P} MATCHES "8")
	set(PlatformName x86)
endif(${CMAKE_SIZEOF_VOID_P} MATCHES "8")

message(STATUS "Build ${PlatformName}")


############################
# restore path #
set (COMPILER "vc15" CACHE STRING "vc15")
set (BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/${COMPILER}/${PlatformName}" CACHE PATH "BIN DIR")
set (TBB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/tbb" CACHE PATH "TBB DIR")
set (OTHERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/others" CACHE PATH "OTHERS DIR")#
set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "INSTALL DIR")

####添加第三方库engin
set(CMAKE_MODULE_PATH
  "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Eigen3/CMake"
  ${CMAKE_MODULE_PATH}
)
set (EIGEN_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Eigen3" CACHE PATH "Path to \"Eigen\" library.")
set (CMAKE_PREFIX_PATH "${EIGEN_ROOT_DIR}" ${CMAKE_PREFIX_PATH})
###engin


message(STATUS "${BIN_DIR}")

LINK_DIRECTORIES(
	${BIN_DIR}
	)
INCLUDE_DIRECTORIES(${BOOST_DIR})

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
MACRO(SOURCE_GROUP_BY_DIR source_files)
    if(MSVC)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
			
            if(sgbd_nogroup)
                set(sgbd_group_name "\\")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
    endif(MSVC)
ENDMACRO(SOURCE_GROUP_BY_DIR)

add_subdirectory(src) 