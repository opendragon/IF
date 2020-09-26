//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifObject.cpp
//
//  Project:    IF
//
//  Contains:   The class definition for InitFile Object values.
//
//  Written by: Norman Jaffe
//
//  Copyright:  (c) 2020 by OpenDragon.
//
//              All rights reserved. Redistribution and use in source and binary forms, with or
//              without modification, are permitted provided that the following conditions are met:
//                * Redistributions of source code must retain the above copyright notice, this list
//                  of conditions and the following disclaimer.
//                * Redistributions in binary form must reproduce the above copyright notice, this
//                  list of conditions and the following disclaimer in the documentation and / or
//                  other materials provided with the distribution.
//                * Neither the name of the copyright holders nor the names of its contributors may
//                  be used to endorse or promote products derived from this software without
//                  specific prior written permission.
//
//              THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//              ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//              DAMAGE.
//
//  Created:    2020-09-22
//
//--------------------------------------------------------------------------------------------------

#include <ifObject.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for %InitFile Object values. */
#if defined(__APPLE__)
# pragma clang diagnostic pop
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Namespace references
#endif // defined(__APPLE__)

using namespace InitFile;

#if defined(__APPLE__)
# pragma mark Private structures, constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Class methods
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Constructors and Destructors
#endif // defined(__APPLE__)

ObjectValue::~ObjectValue
    (void)
{
	ODL_OBJENTER(); //####
	fValue.clear();
	ODL_OBJEXIT(); //####
} // ObjectValue::~ObjectValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

ObjectValue &
ObjectValue::AddValue
	(const std::string &	key,
	 SpBase            		aValue)
{
	fValue.insert(value_type(key, aValue));
	return *this;
} // ObjectValue::AddValue

ObjectValue *
ObjectValue::AsObject
	(void)
{
	return this;
} // ObjectValue::AsObject

SpBase
ObjectValue::GetValue
	(const std::string &    key)
	const
{
	SpBase		result;
	const_iterator  match(fValue.find(key));

	if (fValue.end() == match)
	{
		result = nullptr;
	}
	else
	{
		result = match->second;
	}
	return result;
} // ObjectValue::GetValue

size_t
ObjectValue::HowManyValues
	(void)
	const
{
	return fValue.size();
} // ObjectValue::HowManyValues

bool
ObjectValue::IsKeyPresent
	(const std::string &    key)
	const
{
	bool			result;
	const_iterator	match = fValue.find(key);

	if (fValue.end() == match)
	{
		result = false;
	}
	else
	{
		result = true;
	}
	return result;
} // ObjectValue::IsKeyPresent

std::ostream &
ObjectValue::Print
	(std::ostream &	output,
	 const size_t	indentStep,
	 const char		indentChar,
	 const size_t	indentLevel,
	 const bool		squished)
	const
{
	const_iterator	walker(fValue.begin());

	output << '{';
	if (squished)
	{
		if (fValue.end() != walker)
		{
			outputEscapedString(output, walker->first);
			walker->second->Print(output << ':', indentStep, indentChar, indentLevel + indentStep, squished);
			for ( ; fValue.end() != walker; ++walker)
			{
				outputEscapedString(output << ',', walker->first);
				walker->second->Print(output << ':', indentStep, indentChar, indentLevel + indentStep, squished);
			}
		}
	}
	else
	{
		if (fValue.end() != walker)
		{
			outputEscapedString(output << ' ', walker->first);
			walker->second->Print(output << " : ", indentStep, indentChar, indentLevel + indentStep, squished);
			for ( ; fValue.end() != walker; ++walker)
			{
				outputChars(output << ',' << std::endl, indentChar, indentLevel);
				outputEscapedString(output, walker->first);
				walker->second->Print(output << " : ", indentStep, indentChar, indentLevel + indentStep, squished);
			}
		}
		output << ' ';
	}
	output << '}';
	return output;
} // BaseValue::Print

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
