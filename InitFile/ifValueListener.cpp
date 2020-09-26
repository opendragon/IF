//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifValueListener.cpp
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

#include "ifValueListener.h"

#include <ifAddress.h>
#include <ifArray.h>
#include <ifBoolean.h>
#include <ifDouble.h>
#include <ifInteger.h>
#include <ifNull.h>
#include <ifObject.h>
#include <ifString.h>
#include <ifBase.h>
#include <iostream>

//#include <odlEnable.h>
#include <odlInclude.h>

#include "InitFileLexer.h"
#include "InitFileParser.h"

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

BaseValueListener::BaseValueListener
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // BaseValueListener::BaseValueListener

BaseValueListener::~BaseValueListener
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // BaseValueListener::~BaseValueListener

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

void
BaseValueListener::enterEmptyObject
    (InitParser::InitFileParser::EmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushContainer(fCurrentContainer);
    fCurrentContainer.reset(new ObjectValue(fCurrentContainer));
    ODL_OBJEXIT(); //####
} // BaseValueListener::enterEmptyObject

void
BaseValueListener::enterNonEmptyArray
    (InitParser::InitFileParser::NonEmptyArrayContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushContainer(fCurrentContainer);
    fCurrentContainer.reset(new ArrayValue(fCurrentContainer));
    ODL_OBJEXIT(); //####
} // BaseValueListener::enterNonEmptyArray

void
BaseValueListener::enterNonEmptyObject
    (InitParser::InitFileParser::NonEmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushContainer(fCurrentContainer);
    fCurrentContainer.reset(new ObjectValue(fCurrentContainer));
    ODL_OBJEXIT(); //####
} // BaseValueListener::enterNonEmptyObject

void
BaseValueListener::exitAddressValue
    (InitParser::InitFileParser::AddressValueContext *  ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    std::string addressString;
    uint32_t    address = 0;

    ODL_OBJENTER(); //####
    if (ctx->add)
    {
        addressString = ctx->add->getText();
        addressString = addressString.substr(1, addressString.length() - 1);
// std::cout << "address=" << addressString << std::endl;
        for (size_t ii = 0, lastPos = 0; ii < 4; ++ii)
        {
            size_t      jj = addressString.find_first_of('.', lastPos);
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
            // Note that the following doesn't check if the segment value is greater than 255!
            address += std::stoul(segment);
        }
// char oldFill = std::cout.fill('0');

// std::cout << std::hex << "0x";
// std::cout.width(8);
// std::cout << address << std::dec << "<" << address << ">" << std::endl;
// std::cout.fill(oldFill);
    }
    pushValue(SpBase(new AddressValue(fCurrentContainer, address)));
    ODL_OBJEXIT(); //####
} /// BaseValueListener::exitAddressValue

void
BaseValueListener::exitConfiguration
    (InitParser::InitFileParser::ConfigurationContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    fRootObject = popValue();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitConfiguration

void
BaseValueListener::exitDoubleValue
    (InitParser::InitFileParser::DoubleValueContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
// std::cout << "number=" << ctx->nu->getText() << std::endl;
    pushValue(SpBase(new DoubleValue(fCurrentContainer, std::stod(ctx->nu->getText(), NULL))));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitDoubleValue

void
BaseValueListener::exitEmptyArray
    (InitParser::InitFileParser::EmptyArrayContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushValue(SpBase(new ArrayValue(fCurrentContainer)));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitEmptyArray

void
BaseValueListener::exitEmptyObject
    (InitParser::InitFileParser::EmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitEmptyObject

void
BaseValueListener::exitIntegerValue
    (InitParser::InitFileParser::IntegerValueContext *  ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushValue(SpBase(new IntegerValue(fCurrentContainer, std::stol(ctx->nu->getText(), NULL))));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitIntegerValue

void
BaseValueListener::exitLiteralValue
    (InitParser::InitFileParser::LiteralValueContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    if (ctx->tv)
    {
        pushValue(SpBase(new BooleanValue(fCurrentContainer, true)));
    }
    else if (ctx->fv)
    {
        pushValue(SpBase(new BooleanValue(fCurrentContainer, false)));
    }
    else if (ctx->nv)
    {
        pushValue(SpBase(new NullValue(fCurrentContainer)));
    }
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitLiteralValue

void
BaseValueListener::exitNonEmptyArray
    (InitParser::InitFileParser::NonEmptyArrayContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
// std::cout << "#values=" << ctx->value().size() << std::endl;
    ODL_OBJENTER(); //####
    ArrayValue *    currentArray = fCurrentContainer->AsArray();
    size_t          numValues = ctx->value().size();

    // Pull the number of values that were pushed and put them in the correct order.
    for (size_t ii = 0; ii < numValues; ++ii)
    {
        SpBase aValue = popValue();

        currentArray->AddValueAtFront(aValue);
    }
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitNonEmptyArray

void
BaseValueListener::exitNonEmptyObject
    (InitParser::InitFileParser::NonEmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
// std::cout << "#pairs=" << ctx->pair().size() << std::endl;
    ODL_OBJENTER(); //####
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitNonEmptyObject

void
BaseValueListener::exitPair
    (InitParser::InitFileParser::PairContext * /*ctx*/)
{
    std::string     tag = popTag();
    SpBase          value = popValue();
    ObjectValue *   currentObject = fCurrentContainer->AsObject();

    ODL_OBJENTER(); //####
// std::cout << __FUNCTION__ << std::endl;
// std::cout << "tag=" << tag << " : value=" << value->Describe() << std::endl;
    currentObject->AddValue(tag, value);
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitPair

void
BaseValueListener::exitStringValue
    (InitParser::InitFileParser::StringValueContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    std::string actualValue;

    ODL_OBJENTER(); //####
    if (ctx->dq)
    {
        actualValue = ctx->dq->getText();
        actualValue = actualValue.substr(1, actualValue.length() - 2);
    }
    else if (ctx->sq)
    {
        actualValue = ctx->sq->getText();
        actualValue = actualValue.substr(1, actualValue.length() - 2);
    }
    else if (ctx->na)
    {
        actualValue = ctx->na->getText();
    }
    //std::cout << "value -> " << actualValue << std::endl;
    pushValue(SpBase(new StringValue(fCurrentContainer, actualValue)));
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitStringValue

void
BaseValueListener::exitTag
    (InitParser::InitFileParser::TagContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    std::string actualTag;

    ODL_OBJENTER(); //####
    if (ctx->dq)
    {
        actualTag = ctx->dq->getText();
        actualTag = actualTag.substr(1, actualTag.length() - 2);
    }
    else if (ctx->sq)
    {
        actualTag = ctx->sq->getText();
        actualTag = actualTag.substr(1, actualTag.length() - 2);
    }
    else if (ctx->na)
    {
        actualTag = ctx->na->getText();
    }
    pushTag(actualTag);
    ODL_OBJEXIT(); //####
} // BaseValueListener::exitTag

SpBase
BaseValueListener::GetValue
	(const std::string &    input)
{
    try
    {
        fRootObject.reset();
        antlr4::ANTLRInputStream                            inStream(input);
        InitParser::InitFileLexer                           lexer(&inStream);
        antlr4::CommonTokenStream                           tokens(&lexer);
        InitParser::InitFileParser                          parser(&tokens);
        InitParser::InitFileParser::ConfigurationContext *  tree = parser.configuration();
        antlr4::tree::ParseTreeWalker                       walker;

        walker.walk(this, tree);
    }
    catch (const antlr4::RuntimeException & ee)
    {
        std::cerr << "ANTLR4 RuntimeException: " << ee.what() << std::endl;
    }
    catch (const std::exception & ee)
    {
        std::cerr << ee.what() << std::endl;
    }
	return fRootObject;
} // BaseValueListener::GetValue

SpBase
BaseValueListener::GetValue
	(std::istream & input)
{
    try
    {
        fRootObject.reset();
        antlr4::ANTLRInputStream                            inStream(input);
        InitParser::InitFileLexer                           lexer(&inStream);
        antlr4::CommonTokenStream                           tokens(&lexer);
        InitParser::InitFileParser                          parser(&tokens);
        InitParser::InitFileParser::ConfigurationContext *  tree = parser.configuration();
        antlr4::tree::ParseTreeWalker                       walker;

        walker.walk(this, tree);
    }
    catch (const antlr4::RuntimeException & ee)
    {
        std::cerr << "ANTLR4 RuntimeException: " << ee.what() << std::endl;
    }
    catch (const std::exception & ee)
    {
        std::cerr << ee.what() << std::endl;
    }
	return fRootObject;
} // BaseValueListener::GetValue

SpBase
BaseValueListener::popContainer
    (void)
{
    SpBase result;

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

SpBase
BaseValueListener::popValue
    (void)
{
    SpBase result;

    if (fValueStack.empty())
    {
        //result = NULL;
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
    (SpBase  value)
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
    (SpBase  value)
{
    fValueStack.push_back(value);
    return *this;
} // BaseValueListener::pushValue

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
