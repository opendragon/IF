#--------------------------------------------------------------------------------------------------
#
#  File:       non-iOS/CMakeLists.txt
#
#  Project:    IF
#
#  Contains:   The non-iOS CMAKE definitions for the InitFile library.
#
#  Written by: Norman Jaffe
#
#  Copyright:  (c) 2020 by OpenDragon.
#
#              All rights reserved. Redistribution and use in source and binary forms, with or
#              without modification, are permitted provided that the following conditions are met:
#                * Redistributions of source code must retain the above copyright notice, this list
#                  of conditions and the following disclaimer.
#                * Redistributions in binary form must reproduce the above copyright notice, this
#                  list of conditions and the following disclaimer in the documentation and / or
#                  other materials provided with the distribution.
#                * Neither the name of the copyright holders nor the names of its contributors may
#                  be used to endorse or promote products derived from this software without
#                  specific prior written permission.
#
#              THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
#              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
#              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
#              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
#              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
#              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
#              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
#              ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
#              DAMAGE.
#
#  Created:    2020-09-22
#
#--------------------------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "IF")

if(APPLE)
    execute_process(COMMAND uname -m
                    OUTPUT_VARIABLE CPU_TYPE
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(COMMAND sw_vers -productVersion
                    OUTPUT_VARIABLE SYS_VERSION
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

    set(CMAKE_OSX_ARCHITECTURES ${CPU_TYPE} CACHE STRING "Build architectures for Mac OSX")
    set(CMAKE_OSX_DEPLOYMENT_TARGET ${SYS_VERSION} CACHE STRING "Deployment target for Mac OSX")
endif()

project(${PROJECT_NAME}
        HOMEPAGE_URL "https://github.com/opendragon/IF")

include(../ifCommonSettings.cmake NO_POLICY_SCOPE)

if(WIN32)
    set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE INTERNAL "" FORCE)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Make some flags to control the build flags visibilities
mark_as_advanced(CLEAR BUILD_SHARED_LIBS)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(LINUX ON)
    if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "unknown")
        set(UNKNOWN_CPU ON)
    else()
        set(UNKNOWN_CPU OFF)
    endif()
else()
    set(LINUX OFF)
    set(UNKNOWN_CPU OFF)
endif()

if(APPLE)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra" CACHE STRING "Fixes linking error for InitFile" FORCE)
    set(CMAKE_INSTALL_PREFIX "/opt/if" CACHE STRING "Fixes install path for InitFile" FORCE)
# 'rpath' warning
#    cmake_policy(SET CMP0042 OLD)
elseif(LINUX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra" CACHE STRING "Fixes linking error for InitFile" FORCE)
    set(CMAKE_INSTALL_PREFIX "/opt/if" CACHE STRING "Fixes install path for InitFile" FORCE)
endif()

set(CMAKE_USE_RELATIVE_PATHS ON CACHE BOOL "Always set file paths as relative")

if(WIN32)
    option(WIN64 "Build 64-bit binaries" ON)
else()
    set(WIN64 OFF)
endif()

option(IF_ChattyStart "Report the version numbers when launching an executable")

option(IF_DoExplicitCheckForOK "Check OK responses for validity")

option(IF_DO_SWIG "Build the SWIG files" OFF)

# Add the IF target path so that IF can be found
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

# Find SWIG
if(IF_DO_SWIG)
    find_package(SWIG REQUIRED)
    include(${SWIG_USE_FILE})
    set(CMAKE_SWIG_FLAGS "")
endif()

list(APPEND CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH})

# Find ANTLR4
find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

configure_file(${IF_CONFIG_DIR}/ifConfigVersion.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/ifConfigVersion.cmake @ONLY)
configure_file("${IF_SOURCE_DIR}/initFileConfig.h.in" "${IF_SOURCE_DIR}/initFileConfig.h")

# The following is to help CMake find ODL...
if(WIN32)
    set(ODL_DIR "C:/Program Files/ODL/lib")
else()
    set(ODL_DIR "/opt/odl/lib")
endif()
find_package(ODL 1.0.0 REQUIRED)
if(ODL_FOUND)
    include_directories(${ODL_INCLUDE_DIRS})
endif()

if(APPLE)
    macro(ADD_FRAMEWORK fwname appname)
        find_library(FRAMEWORK_${fwname}
                    NAMES ${fwname}
                    PATHS ${CMAKE_OSX_SYSROOT}/System/Library
                    PATH_SUFFIXES Frameworks
                    NO_DEFAULT_PATH)
        if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
            MESSAGE(ERROR ": Framework ${fwname} not found")
        else()
            TARGET_LINK_LIBRARIES(${appname} "${FRAMEWORK_${fwname}}")
            MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
        endif()
    endmacro(ADD_FRAMEWORK)
endif()

set(TARGET initfile)

if(APPLE)
    set(DO_SHARED "SHARED")
elseif(LINUX)
    set(DO_SHARED "SHARED")
else()
    set(DO_SHARED "")
endif()

# ANTLR source code generation
set(ANTLR4_JAR_LOCATION $ENV{ANTLR4_JAR_LOCATION})

antlr4_generate(init_lexer
                ${IF_SOURCE_DIR}/InitFileLexer.g4
                LEXER
                FALSE
                FALSE
                "InitParser")
antlr4_generate(init_parser
                ${IF_SOURCE_DIR}/InitFileParser.g4
                PARSER
                TRUE
                FALSE
                "InitParser"
                "${ANTLR4_TOKEN_FILES_init_lexer}"
                "${ANTLR4_TOKEN_DIRECTORY_init_lexer}")
### use $ENV{ANTLR4_INC}, $ENV{ANTLR4_JAR_LOCATION}, $ENV{ATLR4_LIB}

if(WIN32)
    set(ANTLR4_RUNTIME ${ANTLR4_LIB_DIR}/libantlr4-runtime.a)
elseif(APPLE)
    set(ANTLR4_RUNTIME ${ANTLR4_LIB_DIR}/libantlr4-runtime.a)
elseif(LINUX)
    set(ANTLR4_RUNTIME ${ANTLR4_LIB_DIR}/libantlr4-runtime.a)
else()
    set(ANTLR4_RUNTIME "TBD")
endif()

include_directories(${ANTLR4_INCLUDE_DIR}
                    ${ANTLR4_INCLUDE_DIR_init_lexer}
                    ${ANTLR4_INCLUDE_DIR_init_parser})

add_library(${TARGET}
            ${DO_SHARED}
            ${IF_SOURCE_DIR}/initFile.cpp
            ${IF_SOURCE_DIR}/initFileAddress.cpp
            ${IF_SOURCE_DIR}/initFileArray.cpp
            ${IF_SOURCE_DIR}/initFileBase.cpp
            ${IF_SOURCE_DIR}/initFileBoolean.cpp
            ${IF_SOURCE_DIR}/initFileCompareWithoutCase.cpp
            ${IF_SOURCE_DIR}/initFileDouble.cpp
            ${IF_SOURCE_DIR}/initFileInteger.cpp
            ${IF_SOURCE_DIR}/initFileNull.cpp
            ${IF_SOURCE_DIR}/initFileObject.cpp
            ${IF_SOURCE_DIR}/initFileString.cpp
            ${IF_SOURCE_DIR}/initFileValueListener.cpp
            "${ANTLR4_SRC_FILES_init_parser}"
            "${ANTLR4_SRC_FILES_init_lexer}")

target_link_libraries(${TARGET}
                        ${ANTLR4_RUNTIME})

add_dependencies(${TARGET}
                    antlr4_static)

target_include_directories(${TARGET} PUBLIC
                            $<BUILD_INTERFACE:${IF_SOURCE_DIR}> # for headers when building
                            $<INSTALL_INTERFACE:${INCLUDE_DEST}> # for client in install mode
                            )

install(TARGETS ${TARGET}
        EXPORT ${PROJECT_NAME}
        DESTINATION ${LIB_DEST}
        COMPONENT libraries)

install(FILES
        ${IF_SOURCE_DIR}/initFile.h
        ${IF_SOURCE_DIR}/initFileAddress.h
        ${IF_SOURCE_DIR}/initFileArray.h
        ${IF_SOURCE_DIR}/initFileBase.h
        ${IF_SOURCE_DIR}/initFileBoolean.h
        ${IF_SOURCE_DIR}/initFileCompareWithoutCase.h
        ${IF_SOURCE_DIR}/initFileConfig.h
        ${IF_SOURCE_DIR}/initFileDouble.h
        ${IF_SOURCE_DIR}/initFileInteger.h
        ${IF_SOURCE_DIR}/initFileNull.h
        ${IF_SOURCE_DIR}/initFileObject.h
        ${IF_SOURCE_DIR}/initFileString.h
        DESTINATION ${INCLUDE_DEST}
        COMPONENT headers)

if(WIN32)
    set(OTHER_LIBS "ws2_32.lib")
else()
    set(OTHER_LIBS "")
endif()

set(IF_LINK_LIBRARIES initfile ${ODL_LIBRARY} ${OTHER_LIBS})

if(APPLE)
    function(fix_dynamic_libs target)
        add_custom_command(TARGET ${THIS_TARGET} POST_BUILD COMMAND install_name_tool -change
                            libinitfile.dylib "@rpath/libinitfile.dylib" ${target})

        add_custom_command(TARGET ${THIS_TARGET} POST_BUILD COMMAND install_name_tool -change
                            ${ODL_LIBRARY_ROOT} "@rpath/${ODL_LIBRARY_ROOT}" ${target})

    endfunction()
else()
# Do nothing
    function(fix_dynamic_libs target)
    endfunction()
endif()

install(FILES
        ${IF_CONFIG_DIR}/ifConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/ifConfigVersion.cmake
        DESTINATION ${LIB_DEST}
        COMPONENT scripts)

install(EXPORT ${PROJECT_NAME}
        DESTINATION ${LIB_DEST})

if(IF_DO_SWIG)
    set(IF_SWIG_SOURCES ${IF_SOURCE_DIR}/swig_if_in/ifCommon.i)

    set_source_files_properties(swig_if_in/ifCommon.i PROPERTIES CPLUSPLUS ON)
    set_source_files_properties(swig_if_in/ifCommon.i PROPERTIES SWIG_FLAGS "-includeall")

    set(CMAKE_SWIG_OUTDIR "${IF_SOURCE_DIR}/swig_if_out_csharp")

    swig_add_module(${OTHER_TARGET_CSHARP} csharp ${IF_SWIG_SOURCES})

    swig_link_libraries(${OTHER_TARGET_CSHARP}
                        ${TARGET}
                        ${ODL_LIBRARY})

    install(TARGETS ${OTHER_TARGET_CSHARP}
            EXPORT ${PROJECT_NAME}
            DESTINATION ${LIB_DEST}
            COMPONENT libraries)

    install(FILES
            swig_nImO_out_csharp/if.cs
            swig_nImO_out_csharp/ifPINVOKE.cs
            DESTINATION csharp/nImO
            COMPONENT headers)

    set(CMAKE_SWIG_OUTDIR "${IF_SOURCE_DIR}/swig_if_out_python")

    find_package(PythonLibs)
    include_directories(${PYTHON_INCLUDE_PATH})

    swig_add_module(${OTHER_TARGET_PYTHON} python ${IF_SWIG_SOURCES})

    swig_link_libraries(${OTHER_TARGET_PYTHON}
                        ${TARGET}
                        ${ODL_LIBRARY}
                        ${PYTHON_LIBRARIES})

# Note the modified target name!
    install(TARGETS _${OTHER_TARGET_PYTHON}
            EXPORT ${PROJECT_NAME}
            DESTINATION ${LIB_DEST}
            COMPONENT libraries)

    install(FILES
            swig_if_out_python/if.py
            swig_if_out_python/ifCommonPYTHON_wrap.cxx
            DESTINATION python/if
            COMPONENT headers)

endif()

add_subdirectory(CPack)
add_subdirectory(Tests)

enable_testing()
