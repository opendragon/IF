#--------------------------------------------------------------------------------------------------
#
#  File:       IFConfig.cmake
#
#  Project:    IF
#
#  Contains:   The configuration CMAKE settings for the InitFile library.
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

get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/IF.cmake)

get_filename_component(PARENT_DIR "${SELF_DIR}" PATH)
set(IF_INCLUDE_DIRS "${PARENT_DIR}/include")
if(WIN32)
    set(IF_LIBRARY "${SELF_DIR}/initfile.lib")
elseif(APPLE)
    set(IF_LIBRARY "${SELF_DIR}/libinitfile.dylib")
    set(IF_LIBRARY_ROOT "libinitfile.dylib")
elseif(UNIX)
    set(IF_LIBRARY "${SELF_DIR}/libinitfile.so")
else()
    set(IF_LIBRARY "${SELF_DIR}/libinitfile.a")
endif()

message(STATUS "IF version: ${IF_VERSION}")
