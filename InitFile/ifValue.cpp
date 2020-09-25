//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifValue.cpp
//
//  Project:    IF
//
//  Contains:   The class definition for InitFile values.
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

#include <ifValue.h>

#include <fstream>
#include <iostream>

//#include <odlEnable.h>
#include <odlInclude.h>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class definition for %InitFile values. */
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

InitValue::~InitValue
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // InitValue::~InitValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

const AddressValue *
InitValue::AsAddress
	(void)
	const
{
	return nullptr;
} // InitValue::AsAddress

AddressValue *
InitValue::AsAddress
	(void)
{
	return nullptr;
} // InitValue::AsAddress

const ArrayValue *
InitValue::AsArray
	(void)
	const
{
	return nullptr;
} // InitValue::AsArray

ArrayValue *
InitValue::AsArray
	(void)
{
	return nullptr;
} // InitValue::AsArray

const BooleanValue *
InitValue::AsBoolean
	(void)
	const
{
	return nullptr;
} // InitValue::AsBoolean

BooleanValue *
InitValue::AsBoolean
	(void)
{
	return nullptr;
} // InitValue::AsBoolean

const DoubleValue *
InitValue::AsDouble
	(void)
	const
{
	return nullptr;
} // InitValue::AsDouble

DoubleValue *
InitValue::AsDouble
	(void)
{
	return nullptr;
} // InitValue::AsDouble

const IntegerValue *
InitValue::AsInteger
	(void)
	const
{
	return nullptr;
} // InitValue::AsInteger

IntegerValue *
InitValue::AsInteger
	(void)
{
	return nullptr;
} // InitValue::AsInteger

const NullValue *
InitValue::AsNull
	(void)
	const
{
	return nullptr;
} // InitValue::AsNull

NullValue *
InitValue::AsNull
	(void)
{
	return nullptr;
} // InitValue::AsNull

const ObjectValue *
InitValue::AsObject
	(void)
	const
{
	return nullptr;
} // InitValue::AsObject

ObjectValue *
InitValue::AsObject
	(void)
{
	return nullptr;
} // InitValue::AsObject

const StringValue *
InitValue::AsString
	(void)
	const
{
	return nullptr;
} // InitValue::AsString

StringValue *
InitValue::AsString
	(void)
{
	return nullptr;
} // InitValue::AsString

std::ostream &
InitValue::outputChars
	(std::ostream &	output,
	 const char		aChar,
	 const size_t	howMany)
	const
{
	for (size_t ii = 0; ii < howMany; ++ii)
	{
		output << aChar;
	}
	return output;
} // InitValue::outputChars

std::ostream &
InitValue::outputEscapedString
	(std::ostream &			output,
	 const std::string &	aString)
	const
{
	size_t		foundDouble = aString.find('"');
	size_t		foundSingle = aString.find('\'');
	char		quoteChar;
	const char	escape = '\\';

	if (aString.npos == foundDouble)
	{
		// No double quotes present in the string.
		// Use double quotes.
		quoteChar = '"';
	}
	else if (aString.npos == foundSingle)
	{
		// No single quotes present in the string.
		// Double quotes present in the string.
		// Use single quotes.
		quoteChar = '\'';
	}
	else
	{
		// Both single quotes and double quotes present in the string.
		// Use double quotes.
		quoteChar = '"';
	}
	output << quoteChar;
	for (auto walker = aString.cbegin(); walker != aString.cend(); ++walker)
	{
		const char	aChar = *walker;

		if (aChar == quoteChar)
		{
			output << escape << aChar;
		}
		else
		{
			switch (aChar)
			{
				case '\b' :
					output << escape << 'b';
					break;

				case '\f' :
					output << escape << 'f';
					break;

				case '\n' :
					output << escape << 'n';
					break;

				case '\r' :
					output << escape << 'r';
					break;

				case '\t' :
					output << escape << 't';
					break;

				case '\v' :
					output << escape << 'v';
					break;

				case escape :
					output << escape << aChar;
					break;

				default :
					output << aChar;
					break;

			}
		}
	}
	output << quoteChar;
	return output;
} // InitValue::outputEscapedString

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
