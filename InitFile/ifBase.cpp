//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifBase.cpp
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

#include <ifBase.h>

#include <fstream>
#include <iostream>

//#include <odlEnable.h>
#include <odlInclude.h>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for %InitFile values. */
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

BaseValue::BaseValue
    (const BaseValue &	NOT_USED_(other)) :
        fParent(nullptr)
{
    ODL_ENTER(); //####
    ODL_P1("other = ", &other); //####
    ODL_EXIT_P(this); //####
} // BaseValue::BaseValue

BaseValue::~BaseValue
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // BaseValue::~BaseValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

AddressValue *
BaseValue::AsAddress
	(void)
{
	return nullptr;
} // BaseValue::AsAddress

const AddressValue *
BaseValue::AsAddress
	(void)
	const
{
	return nullptr;
} // BaseValue::AsAddress

ArrayValue *
BaseValue::AsArray
	(void)
{
	return nullptr;
} // BaseValue::AsArray

const ArrayValue *
BaseValue::AsArray
	(void)
	const
{
	return nullptr;
} // BaseValue::AsArray

BooleanValue *
BaseValue::AsBoolean
	(void)
{
	return nullptr;
} // BaseValue::AsBoolean

const BooleanValue *
BaseValue::AsBoolean
	(void)
	const
{
	return nullptr;
} // BaseValue::AsBoolean

DoubleValue *
BaseValue::AsDouble
	(void)
{
	return nullptr;
} // BaseValue::AsDouble

const DoubleValue *
BaseValue::AsDouble
	(void)
	const
{
	return nullptr;
} // BaseValue::AsDouble

IntegerValue *
BaseValue::AsInteger
	(void)
{
	return nullptr;
} // BaseValue::AsInteger

const IntegerValue *
BaseValue::AsInteger
	(void)
	const
{
	return nullptr;
} // BaseValue::AsInteger

NullValue *
BaseValue::AsNull
	(void)
{
	return nullptr;
} // BaseValue::AsNull

const NullValue *
BaseValue::AsNull
	(void)
	const
{
	return nullptr;
} // BaseValue::AsNull

ObjectValue *
BaseValue::AsObject
	(void)
{
	return nullptr;
} // BaseValue::AsObject

const ObjectValue *
BaseValue::AsObject
	(void)
	const
{
	return nullptr;
} // BaseValue::AsObject

StringValue *
BaseValue::AsString
	(void)
{
	return nullptr;
} // BaseValue::AsString

const StringValue *
BaseValue::AsString
	(void)
	const
{
	return nullptr;
} // BaseValue::AsString

std::ostream &
BaseValue::outputChars
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
} // BaseValue::outputChars

std::ostream &
BaseValue::outputEscapedString
	(std::ostream &			output,
	 const std::string &	aString)
	const
{
	output << MakeWrappedString(aString);
	return output;
} // BaseValue::outputEscapedString

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)

/*! @brief Convert an arbitrary string into a correctly formatted string.
 @param[in] inString The string to be formatted.
 @result A string with correctly escaped characters and delimiters. */
std::string
InitFile::MakeWrappedString
    (const std::string &    inString)
{
    std::string result;
	size_t		foundDouble = inString.find('"');
	size_t		foundSingle = inString.find('\'');
	char		quoteChar;
	const char	escape = '\\';

	if (inString.npos == foundDouble)
	{
		// No double quotes present in the string.
		// Use double quotes.
		quoteChar = '"';
	}
	else if (inString.npos == foundSingle)
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
    result = quoteChar;
	for (auto walker = inString.cbegin(); walker != inString.cend(); ++walker)
	{
		const char	aChar = *walker;

		if (aChar == quoteChar)
		{
			result += escape;
            result += aChar;
		}
		else
		{
			switch (aChar)
			{
				case '\b' :
					result += escape;
                    result += 'b';
					break;

				case '\f' :
					result += escape;
					result += 'f';
					break;

				case '\n' :
					result += escape;
					result += 'n';
					break;

				case '\r' :
					result += escape;
					result += 'r';
					break;

				case '\t' :
					result += escape;
					result += 't';
					break;

				case '\v' :
					result += escape;
					result += 'v';
					break;

				case escape :
					result += escape;
					result += aChar;
					break;

				default :
					result += aChar;
					break;

			}
		}
	}
	result += quoteChar;
    return result;
} // BaseValue::MakeWrappedString
