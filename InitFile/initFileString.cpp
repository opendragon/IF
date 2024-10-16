//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileString.cpp
//
//  Project:    IF
//
//  Contains:   The class definition for InitFile String values.
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

#include <initFileString.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for %InitFile String values. */
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

StringValue::StringValue
    (const StringValue &    other) :
        inherited{other}, fValue{other.fValue}
{
    ODL_ENTER(); //####
    ODL_P1(&other); //####
    ODL_EXIT_P(this); //####
} // StringValue::StringValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

StringValue *
StringValue::AsString
	(void)
{
	return this;
} // StringValue::AsString

const StringValue *
StringValue::AsString
	(void)
	const
{
	return this;
} // StringValue::AsString

UpBaseValue
StringValue::Clone
	(void)
	const
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
    return std::make_unique<StringValue>(*this);
} // StringValue::Clone

bool
StringValue::operator ==
	(const BaseValue &	other)
	const
{
    ODL_OBJENTER(); //####
    ODL_P1(&other); //####
    bool	result{false};

	if (&other == this)
	{
		result = true;
	}
	else
	{
        auto	asValue{other.AsString()};

		if (nullptr != asValue)
		{
			result = (fValue == asValue->GetValue());
		}
	}
	ODL_OBJEXIT_B(result); //####
	return result;
} // StringValue::operator ==

std::ostream &
StringValue::Print
	(std::ostream &	output,
	 const size_t	/*indentStep*/,
	 const char		/*indentChar*/,
	 const size_t	/*indentLevel*/,
	 const bool		/*squished*/)
	const
{
	return outputEscapedString(output, fValue);
} // BaseValue::Print

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
