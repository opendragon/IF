//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileValueListener.cpp
//
//  Project:    IF
//
//  Contains:   The class definition for a listener for InitFile streams.
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
//  Created:    2020-09-24
//
//--------------------------------------------------------------------------------------------------

#include "initFileValueListener.h"

#include <initFileAddress.h>
#include <initFileArray.h>
#include <initFileBoolean.h>
#include <initFileDouble.h>
#include <initFileInteger.h>
#include <initFileNull.h>
#include <initFileObject.h>
#include <initFileString.h>
#include <initFileBase.h>
#include "InitFileLexer.h"
#include "InitFileParser.h"

#include <iostream>
#include <string>

//#include <odlEnable.h>
#include <odlInclude.h>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for a listener for %InitFile streams. */
#if defined(__APPLE__)
# pragma clang diagnostic pop
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Namespace references
#endif // defined(__APPLE__)

using namespace InitFile;
using namespace std::string_literals;

#if defined(__APPLE__)
# pragma mark Private structures, constants and variables
#endif // defined(__APPLE__)

//#define TRACE_PARSING_

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

BaseValueListener::BaseValueListener
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // BaseValueListener::BaseValueListener

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

void
BaseValueListener::enterEmptyObject
    (InitParser::InitFileParser::EmptyObjectContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    pushContainer(fCurrentContainer);
    fCurrentContainer = std::make_shared<ObjectValue>(fCurrentContainer);
    ODL_OBJEXIT(); //####
} // BaseValueListener::enterEmptyObject

void
BaseValueListener::enterNonEmptyArray
    (InitParser::InitFileParser::NonEmptyArrayContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    pushContainer(fCurrentContainer);
    fCurrentContainer = std::make_shared<ArrayValue>(fCurrentContainer);
    ODL_OBJEXIT(); //####
} // BaseValueListener::enterNonEmptyArray

void
BaseValueListener::enterNonEmptyObject
    (InitParser::InitFileParser::NonEmptyObjectContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    pushContainer(fCurrentContainer);
    fCurrentContainer = std::make_shared<ObjectValue>(fCurrentContainer);
    ODL_OBJEXIT(); //####
} // BaseValueListener::enterNonEmptyObject

void
BaseValueListener::exitAddressValue
    (InitParser::InitFileParser::AddressValueContext *  ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    std::string addressString;
    uint32_t    address{0};

    if (nullptr != ctx->add)
    {
        addressString = ctx->add->getText();
        if ('@' == addressString[0])
        {
            addressString = addressString.substr(1, addressString.length());
        }
#if defined(TRACE_PARSING_)
        std::cerr << "address=" << addressString << "\n";
#endif // defined(TRACE_PARSING_)
        for (size_t ii = 0, lastPos = 0; ii < 4; ++ii)
        {
            size_t      jj{addressString.find_first_of('.', lastPos)};
            std::string segment;

            address <<= 8;
            if (std::string::npos == jj)
            {
                segment = addressString.substr(lastPos, addressString.length());
            }
            else
            {
                segment = addressString.substr(lastPos, jj - lastPos);
                lastPos = jj + 1;
            }
            size_t  nextPos;
            size_t  segmentValue{std::stoul(segment, &nextPos)};

            if ((255 < segmentValue) || (nextPos < segment.length()))
            {
                throw antlr4::RuntimeException("address contains invalid byte ("s + segment + ")"s);

            }
            address += segmentValue;
        }
#if defined(TRACE_PARSING_)
        char oldFill{std::cout.fill('0')};

        std::cerr << std::hex << "0x";
        std::cerr.width(8);
        std::cerr << address << std::dec << "<" << address << ">\n";
        std::cerr.fill(oldFill);
#endif // defined(TRACE_PARSING_)
    }
    pushValue(std::make_shared<AddressValue>(fCurrentContainer, address));
    ODL_OBJEXIT(); //####
} /// BaseValueListener::exitAddressValue

void
BaseValueListener::exitConfiguration
    (InitParser::InitFileParser::ConfigurationContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    fRootObject = popValue();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitConfiguration

void
BaseValueListener::exitDoubleValue
    (InitParser::InitFileParser::DoubleValueContext * ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
#if defined(TRACE_PARSING_)
    std::cerr << "number=" << ctx->nu->getText() << "\n";
#endif // defined(TRACE_PARSING_)
    pushValue(std::make_shared<DoubleValue>(fCurrentContainer, std::stod(ctx->nu->getText(), nullptr)));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitDoubleValue

void
BaseValueListener::exitEmptyArray
    (InitParser::InitFileParser::EmptyArrayContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    pushValue(std::make_shared<ArrayValue>(fCurrentContainer));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitEmptyArray

void
BaseValueListener::exitEmptyObject
    (InitParser::InitFileParser::EmptyObjectContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitEmptyObject

void
BaseValueListener::exitIntegerValue
    (InitParser::InitFileParser::IntegerValueContext *  ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    pushValue(std::make_shared<IntegerValue>(fCurrentContainer, std::stod(ctx->nu->getText(), nullptr)));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitIntegerValue

void
BaseValueListener::exitLiteralValue
    (InitParser::InitFileParser::LiteralValueContext * ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    if (ctx->tv)
    {
        pushValue(std::make_shared<BooleanValue>(fCurrentContainer, true));
    }
    else
    {
        if (ctx->fv)
        {
            pushValue(std::make_shared<BooleanValue>(fCurrentContainer, false));
        }
        else
        {
            if (ctx->nv)
            {
                pushValue(std::make_shared<NullValue>(fCurrentContainer));
            }
        }
    }
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitLiteralValue

void
BaseValueListener::exitNonEmptyArray
    (InitParser::InitFileParser::NonEmptyArrayContext * ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
    std::cerr << "#values=" << ctx->value().size() << "\n";
#endif // defined(TRACE_PARSING_)
    auto    currentArray{fCurrentContainer->AsArray()};
    size_t  numValues{ctx->value().size()};

    // Pull the number of values that were pushed and put them in the correct order.
    for (size_t ii = 0; ii < numValues; ++ii)
    {
        SpBaseValue aValue{popValue()};

        currentArray->AddValueAtFront(aValue);
    }
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitNonEmptyArray

void
BaseValueListener::exitNonEmptyObject
#if defined(TRACE_PARSING_)
    (InitParser::InitFileParser::NonEmptyObjectContext * ctx)
#else // not defined(TRACE_PARSING_)
    (InitParser::InitFileParser::NonEmptyObjectContext * /*ctx*/)
#endif // not defined(TRACE_PARSING_)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
    std::cerr << "#pairs=" << ctx->pair().size() << "\n";
#endif // defined(TRACE_PARSING_)
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitNonEmptyObject

void
BaseValueListener::exitPair
    (InitParser::InitFileParser::PairContext * /*ctx*/)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    std::string tag{popTag()};
    SpBaseValue value{popValue()};

#if defined(TRACE_PARSING_)
    std::cerr << "tag=" << tag << " : value=";
    if (nullptr == value)
    {
        std::cerr << "<<broken>>";
    }
    else
    {
        value->Print(std::cerr);
    }
    std::cerr << "\n";
#endif // defined(TRACE_PARSING_)
    auto   currentObject{fCurrentContainer->AsObject()};

    currentObject->AddValue(tag, value);
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitPair

void
BaseValueListener::exitStringValue
    (InitParser::InitFileParser::StringValueContext * ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    std::string actualValue;

    if (nullptr != ctx->dq)
    {
        actualValue = ctx->dq->getText();
        actualValue = actualValue.substr(1, actualValue.length() - 2);
    }
    else
    {
        if (nullptr != ctx->sq)
        {
            actualValue = ctx->sq->getText();
            actualValue = actualValue.substr(1, actualValue.length() - 2);
        }
        else
        {
            if (nullptr != ctx->na)
            {
                actualValue = ctx->na->getText();
            }
        }
    }
    pushValue(std::make_shared<StringValue>(fCurrentContainer, actualValue));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitStringValue

void
BaseValueListener::exitTag
    (InitParser::InitFileParser::TagContext * ctx)
{
    ODL_OBJENTER(); //####
#if defined(TRACE_PARSING_)
    std::cerr << __FUNCTION__ << "\n";
#endif // defined(TRACE_PARSING_)
    std::string actualTag;

    if (nullptr != ctx->dq)
    {
        actualTag = ctx->dq->getText();
        actualTag = actualTag.substr(1, actualTag.length() - 2);
    }
    else
    {
        if (nullptr != ctx->sq)
        {
            actualTag = ctx->sq->getText();
            actualTag = actualTag.substr(1, actualTag.length() - 2);
        }
        else
        {
            if (nullptr != ctx->na)
            {
                actualTag = ctx->na->getText();
            }
        }
    }
    pushTag(actualTag);
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitTag

SpBaseValue
BaseValueListener::GetValue
	(const std::string &    input)
{
    try
    {
        fRootObject.reset();
        antlr4::ANTLRInputStream        inStream{input};
        InitParser::InitFileLexer       lexer{&inStream};
        antlr4::CommonTokenStream       tokens{&lexer};
        InitParser::InitFileParser      parser{&tokens};
        auto                            tree{parser.configuration()};
        antlr4::tree::ParseTreeWalker   walker;

        walker.walk(this, tree);
    }
    catch (const antlr4::RuntimeException & ee)
    {
        std::cerr << "ANTLR4 RuntimeException: " << ee.what() << "\n";
        fRootObject.reset();
    }
    catch (const std::exception & ee)
    {
        std::cerr << ee.what() << "\n";
        fRootObject.reset();
    }
	return fRootObject;
} // BaseValueListener::GetValue

SpBaseValue
BaseValueListener::GetValue
	(std::istream & input)
{
    try
    {
        fRootObject.reset();
        antlr4::ANTLRInputStream        inStream{input};
        InitParser::InitFileLexer       lexer{&inStream};
        antlr4::CommonTokenStream       tokens{&lexer};
        InitParser::InitFileParser      parser{&tokens};
        auto                            tree{parser.configuration()};
        antlr4::tree::ParseTreeWalker   walker;

        walker.walk(this, tree);
    }
    catch (const antlr4::RuntimeException & ee)
    {
        std::cerr << "ANTLR4 RuntimeException: " << ee.what() << "\n";
        fRootObject.reset();
    }
    catch (const std::exception & ee)
    {
        std::cerr << ee.what() << "\n";
        fRootObject.reset();
    }
	return fRootObject;
} // BaseValueListener::GetValue

SpBaseValue
BaseValueListener::popContainer
    (void)
{
    SpBaseValue result;

    if (fContainerStack.empty())
    {
        //result.reset();
    }
    else
    {
        result = fContainerStack.back();
        fContainerStack.pop_back();
    }
    return result;
} // BaseValueListener::popContainer

std::string
BaseValueListener::popTag
    (void)
{
  std::string result;

  if (! fTagStack.empty())
  {
    result = fTagStack.back();
    fTagStack.pop_back();
  }
  return result;
} // BaseValueListener::popTag

SpBaseValue
BaseValueListener::popValue
    (void)
{
    SpBaseValue result;

    if (fValueStack.empty())
    {
        //result = nullptr;
    }
    else
    {
        result = fValueStack.back();
        fValueStack.pop_back();
    }
    return result;
} // BaseValueListener::popValue

BaseValueListener &
BaseValueListener::pushContainer
    (SpBaseValue  value)
{
    fContainerStack.push_back(value);
    return *this;
} // BaseValueListener::pushContainer

BaseValueListener &
BaseValueListener::pushTag
    (const std::string  tag)
{
	fTagStack.push_back(tag);
    return *this;
} /* pushTag */

BaseValueListener &
BaseValueListener::pushValue
    (SpBaseValue  value)
{
    fValueStack.push_back(value);
    return *this;
} // BaseValueListener::pushValue

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
