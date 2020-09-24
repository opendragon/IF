//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifArray.cpp
//
//  Project:    IF
//
//  Contains:   The class definition for InitFile Array values.
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

#include <ifArray.h>

//#include <odlEnable.h>
#include <odlInclude.h>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class definition for %InitFile Array values. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

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

ArrayValue::~ArrayValue
    (void)
{
    ODL_OBJENTER(); //####
	for (auto elem : fValue)
	{
		delete elem;
	}
	fValue.clear();
    ODL_OBJEXIT(); //####
} // ArrayValue::~ArrayValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

void
ArrayValue::AddValueAtBack
	(InitValue *    aValue)
{
	if (aValue)
	{
		fValue.push_back(aValue);
	}
} // ArrayValue::AddValueAtBack

void
ArrayValue::AddValueAtFront
	(InitValue *    aValue)
{
	if (aValue)
	{
		fValue.push_front(aValue);
	}
} // ArrayValue::AddValueAtFront

const ArrayValue *
ArrayValue::AsArray
	(void)
	const
{
	return this;
} // ArrayValue::AsArray

InitValue *
ArrayValue::GetValue
	(const size_t   index)
	const
{
	InitValue *	result;

	if (index < fValue.size())
	{
		result = fValue[index];
	}
	else
	{
		result = nullptr;
	}
	return result;
} // ArrayValue::GetValue

size_t
ArrayValue::HowManyValues
	(void)
	const
{
	return fValue.size();
} // ArrayValue::HowManyValues

std::ostream &
ArrayValue::Print
	(std::ostream &	output,
	 const size_t	indentStep,
	 const char		indentChar,
	 const size_t	indentLevel,
	 const bool		squished)
	const
{
	size_t	count = fValue.size();

	output << '[';
	if (squished)
	{
		if (0 != count)
		{
			fValue[0]->Print(output, indentStep, indentChar, indentLevel + indentStep, squished);
			for (size_t ii = 1; ii < count; ++ii)
			{
				fValue[ii]->Print(output << ',', indentStep, indentChar, indentLevel + indentStep, squished);
			}
		}
	}
	else
	{
		if (0 != count)
		{
			fValue[0]->Print(output << ' ', indentStep, indentChar, indentLevel + indentStep, squished);
			for (size_t ii = 1; ii < count; ++ii)
			{
				outputChars(output << ',' << std::endl, indentChar, indentLevel);
				fValue[ii]->Print(output, indentStep, indentChar, indentLevel + indentStep, squished);
			}
		}
		output << ' ';
	}
	output << ']';
	return output;
} // InitValue::Print

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
