//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileObject.cpp
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

#include <initFileObject.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#include <iostream>

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

ObjectValue::ObjectValue
    (const ObjectValue &    other) :
        inherited{other}
{
    ODL_ENTER(); //####
    ODL_P1("other = ", &other); //####
	// copy elements
    for (auto & walker : other.fValue)
    {
        AddValue(walker.first, walker.second);
    }
    ODL_EXIT_P(this); //####
} // ObjectValue::ObjectValue

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

ObjectValue &
ObjectValue::AddValue
	(const std::string &	key,
	 SpBaseValue       		aValue)
{
	fValue.insert({key, aValue});
	return *this;
} // ObjectValue::AddValue

ObjectValue *
ObjectValue::AsObject
	(void)
{
	return this;
} // ObjectValue::AsObject

const ObjectValue *
ObjectValue::AsObject
	(void)
	const
{
	return this;
} // ObjectValue::AsObject

UpBaseValue
ObjectValue::Clone
	(void)
	const
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
    return std::make_unique<ObjectValue>(*this);
} // ObjectValue::Clone

std::set<std::string>
ObjectValue::GetTags
	(void)
	const
{
	std::set<std::string>	result;
	
	for (auto & walker : fValue)
	{
		result.insert(walker.first);
	}
	return result;
} // ObjectValue::GetTags

SpBaseValue
ObjectValue::GetValue
	(const std::string &    tag)
	const
{
	SpBaseValue	result;
	auto	    match{fValue.find(tag)};

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
ObjectValue::IsTagPresent
	(const std::string &    tag)
	const
{
	bool	result;
	auto	match{fValue.find(tag)};

	if (fValue.end() == match)
	{
		result = false;
	}
	else
	{
		result = true;
	}
	return result;
} // ObjectValue::IsTagPresent

bool
ObjectValue::operator ==
	(const BaseValue &	other)
	const
{
    ODL_OBJENTER(); //####
    ODL_P1("other = ", &other); //####
	bool	result = false;

	if (&other == this)
	{
		result = true;
	}
	else
	{
        auto	asValue{other.AsObject()};

		if (nullptr != asValue)
		{
            size_t	otherSize{asValue->HowManyValues()};

			if (HowManyValues() == otherSize)
			{
				result = true;
				for (auto & walker : fValue)
				{
					std::string	key{walker.first};
					SpBaseValue	thisValue{walker.second};
					SpBaseValue	otherValue{asValue->GetValue(key)};

					if (nullptr == otherValue)
                    {
                        result = false;
                    }
                    else
					{
						result = (*thisValue == *otherValue);
					}
				}
			}
		}
	}
	ODL_OBJEXIT_B(result); //####
	return result;
} // ObjectValue::operator ==

std::ostream &
ObjectValue::Print
	(std::ostream &	output,
	 const size_t	indentStep,
	 const char		indentChar,
	 const size_t	indentLevel,
	 const bool		squished)
	const
{
	auto	walker{fValue.begin()};

	output << '{';
	if (squished)
	{
		if (fValue.end() != walker)
		{
			outputEscapedString(output, walker->first);
			walker->second->Print(output << ':', indentStep, indentChar, indentLevel + indentStep, squished);
			for (++walker; fValue.end() != walker; ++walker)
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
			for (++walker; fValue.end() != walker; ++walker)
			{
				outputChars(output << ",\n", indentChar, indentLevel);
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
