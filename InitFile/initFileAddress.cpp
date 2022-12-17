//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileAddress.cpp
//
//  Project:    IF
//
//  Contains:   The class definition for InitFile Address values.
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

#include <initFileAddress.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for %InitFile Address values. */
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

AddressValue::AddressValue
    (const AddressValue &    other) :
        inherited(other), fValue(other.fValue)
{
    ODL_ENTER(); //####
    ODL_P1("other = ", &other); //####
    ODL_EXIT_P(this); //####
} // AddressValue::AddressValue

AddressValue::~AddressValue
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // AddressValue::~AddressValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

AddressValue *
AddressValue::AsAddress
	(void)
{
	return this;
} // AddressValue::AsAddress

const AddressValue *
AddressValue::AsAddress
	(void)
	const
{
	return this;
} // AddressValue::AsAddress

SpBaseValue
AddressValue::Clone
	(void)
	const
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
	return SpBaseValue(new AddressValue(*this));	
} // AddressValue::Clone

bool
AddressValue::operator ==
	(const BaseValue &	other)
	const
{
	bool	result = false;

	ODL_OBJENTER(); //####
    ODL_P1("other = ", &other); //####
	if (&other == this)
	{
		result = true;
	}
	else
	{
		const AddressValue *	asValue = other.AsAddress();

		if (asValue)
		{
			result = (fValue == asValue->GetValue());
		}
	}
	ODL_OBJEXIT_B(result); //####
	return result;
} // AddressValue::operator ==

std::ostream &
AddressValue::Print
	(std::ostream &	output,
	 const size_t	/*indentStep*/,
	 const char		/*indentChar*/,
	 const size_t	/*indentLevel*/,
	 const bool		/*squished*/)
	const
{
	return (output << ((fValue >> 24) & 0x0FF) << '.' << ((fValue >> 16) & 0x0FF) << '.' << ((fValue >> 8) & 0x0FF) << '.' << (fValue & 0x0FF));
} // BaseValue::Print

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
