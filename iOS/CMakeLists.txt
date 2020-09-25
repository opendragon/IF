#--------------------------------------------------------------------------------------------------
#
#  File:       iOS/CMakeLists.txt
#
#  Project:    IF
#
#  Contains:   The iOS CMAKE definitions for the InitFile library.
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

include(iOS.cmake)

project(${PROJECT_NAME}
        HOMEPAGE_URL "https://github.com/opendragon/IF")

include(../ifCommonSettings.cmake NO_POLICY_SCOPE)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Make some flags to control the build flags visibilities
mark_as_advanced(CLEAR BUILD_SHARED_LIBS)

set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 9.0)
set(CMAKE_C_FLAGS "-miphoneos-version-min=9.0" CACHE STRING "Make sure version is supportable" FORCE)

set(CMAKE_CXX_FLAGS "-Wall -Wextra" CACHE STRING "Fixes linking error for InitFile" FORCE)
set(CMAKE_INSTALL_PREFIX "/opt/if" CACHE STRING "Fixes install path for InitFile" FORCE)
# 'rpath' warning
cmake_policy(SET CMP0042 OLD)

set(CMAKE_USE_RELATIVE_PATHS ON CACHE BOOL "Always set file paths as relative")

# Add the IF target path so that IF can be found
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

list(APPEND CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH})

# Find ANTLR4
find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime REQUIRED)

configure_file(${IF_CONFIG_DIR}/IFConfigVersion.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/IFConfigVersion.cmake @ONLY)
configure_file("${IF_SOURCE_DIR}/ifConfig.h.in" "${IF_SOURCE_DIR}/ifConfig.h")

# The following is to help CMake find ODL...
set(ODL_DIR "/opt/odl/lib")
find_package(ODL 1.0.0 REQUIRED)
if(ODL_FOUND)
    include_directories(${ODL_INCLUDE_DIRS})
endif()

macro(ADD_FRAMEWORK fwname appname)
    find_library(FRAMEWORK_${fwname}
                NAMES ${fwname}
                PATHS ${CMAKE_OSX_SYSROOT}/System/Library
                PATH_SUFFIXES Frameworks
                NO_DEFAULT_PATH)
    if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
        MESSAGE(ERROR ": Framework ${fwname} not found")
    else()
        TARGET_LINK_LIBRARIES(${appname} ${FRAMEWORK_${fwname}})
        MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
    endif()
endmacro(ADD_FRAMEWORK)

set(TARGET initfile)

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

set(ANTLR4_RUNTIME ${ANTLR4_LIB_DIR}/libantlr4-runtime.a)

include_directories(${ANTLR4_INCLUDE_DIR}
                    ${ANTLR4_INCLUDE_DIR_init_lexer}
                    ${ANTLR4_INCLUDE_DIR_init_parser})

add_library(${TARGET}
            ${DO_SHARED}
            ${IF_SOURCE_DIR}/ifAddress.cpp
            ${IF_SOURCE_DIR}/ifArray.cpp
            ${IF_SOURCE_DIR}/ifBoolean.cpp
            ${IF_SOURCE_DIR}/ifCompareWithoutCase.cpp
            ${IF_SOURCE_DIR}/ifDouble.cpp
            ${IF_SOURCE_DIR}/ifInteger.cpp
            ${IF_SOURCE_DIR}/ifNull.cpp
            ${IF_SOURCE_DIR}/ifObject.cpp
            ${IF_SOURCE_DIR}/ifString.cpp
            ${IF_SOURCE_DIR}/ifValue.cpp
            ${IF_SOURCE_DIR}/ifValueListener.cpp
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
        ${IF_SOURCE_DIR}/ifAddress.h
        ${IF_SOURCE_DIR}/ifArray.h
        ${IF_SOURCE_DIR}/ifBoolean.h
        ${IF_SOURCE_DIR}/ifCompareWithoutCase.h
        ${IF_SOURCE_DIR}/ifConfig.h
        ${IF_SOURCE_DIR}/ifDouble.h
        ${IF_SOURCE_DIR}/ifInteger.h
        ${IF_SOURCE_DIR}/ifNull.h
        ${IF_SOURCE_DIR}/ifObject.h
        ${IF_SOURCE_DIR}/ifString.h
        ${IF_SOURCE_DIR}/ifValue.h
        DESTINATION ${INCLUDE_DEST}
        COMPONENT headers)

install(EXPORT ${PROJECT_NAME}
        DESTINATION ${LIB_DEST})
