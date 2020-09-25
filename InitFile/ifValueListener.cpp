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
#include <ifValue.h>
//#include <fstream>
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

InitValueListener::InitValueListener
    (void) :
        fCurrentContainer(nullptr), fRootObject(nullptr)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // InitValueListener::InitValueListener

InitValueListener::~InitValueListener
    (void)
{
    ODL_OBJENTER(); //####
    ODL_OBJEXIT(); //####
} // InitValueListener::~InitValueListener

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

void
InitValueListener::enterEmptyObject
    (InitParser::InitFileParser::EmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushContainer(fCurrentContainer);
    fCurrentContainer = new ObjectValue(fCurrentContainer);
    ODL_OBJEXIT(); //####
} // InitValueListener::enterEmptyObject

void
InitValueListener::enterNonEmptyArray
    (InitParser::InitFileParser::NonEmptyArrayContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushContainer(fCurrentContainer);
    fCurrentContainer = new ArrayValue(fCurrentContainer);
    ODL_OBJEXIT(); //####
} // InitValueListener::enterNonEmptyArray

void
InitValueListener::enterNonEmptyObject
    (InitParser::InitFileParser::NonEmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushContainer(fCurrentContainer);
    fCurrentContainer = new ObjectValue(fCurrentContainer);
    ODL_OBJEXIT(); //####
} // InitValueListener::enterNonEmptyObject

void
InitValueListener::exitAddressValue
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
    pushValue(new AddressValue(fCurrentContainer, address));
    ODL_OBJEXIT(); //####
} /// InitValueListener::exitAddressValue

void
InitValueListener::exitConfiguration
    (InitParser::InitFileParser::ConfigurationContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    fRootObject = popValue();
    ODL_OBJEXIT(); //####
} // InitValueListener::exitConfiguration

void
InitValueListener::exitDoubleValue
    (InitParser::InitFileParser::DoubleValueContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
// std::cout << "number=" << ctx->nu->getText() << std::endl;
    pushValue(new DoubleValue(fCurrentContainer, std::stod(ctx->nu->getText(), NULL)));
    ODL_OBJEXIT(); //####
} // InitValueListener::exitDoubleValue

void
InitValueListener::exitEmptyArray
    (InitParser::InitFileParser::EmptyArrayContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushValue(new ArrayValue(fCurrentContainer));
    ODL_OBJEXIT(); //####
} // InitValueListener::exitEmptyArray

void
InitValueListener::exitEmptyObject
    (InitParser::InitFileParser::EmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // InitValueListener::exitEmptyObject

void
InitValueListener::exitIntegerValue
    (InitParser::InitFileParser::IntegerValueContext *  ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    pushValue(new IntegerValue(fCurrentContainer, std::stol(ctx->nu->getText(), NULL)));
    ODL_OBJEXIT(); //####
} // InitValueListener::exitIntegerValue

void
InitValueListener::exitLiteralValue
    (InitParser::InitFileParser::LiteralValueContext * ctx)
{
// std::cout << __FUNCTION__ << std::endl;
    ODL_OBJENTER(); //####
    if (ctx->tv)
    {
        pushValue(new BooleanValue(fCurrentContainer, true));
    }
    else if (ctx->fv)
    {
        pushValue(new BooleanValue(fCurrentContainer, false));
    }
    else if (ctx->nv)
    {
        pushValue(new NullValue(fCurrentContainer));
    }
    ODL_OBJEXIT(); //####
} // InitValueListener::exitLiteralValue

void
InitValueListener::exitNonEmptyArray
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
        InitValue * aValue = popValue();

        currentArray->AddValueAtFront(aValue);
    }
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // InitValueListener::exitNonEmptyArray

void
InitValueListener::exitNonEmptyObject
    (InitParser::InitFileParser::NonEmptyObjectContext * /*ctx*/)
{
// std::cout << __FUNCTION__ << std::endl;
// std::cout << "#pairs=" << ctx->pair().size() << std::endl;
    ODL_OBJENTER(); //####
    pushValue(fCurrentContainer);
    fCurrentContainer = popContainer();
    ODL_OBJEXIT(); //####
} // InitValueListener::exitNonEmptyObject

void
InitValueListener::exitPair
    (InitParser::InitFileParser::PairContext * /*ctx*/)
{
    std::string     tag = popTag();
    InitValue *     value = popValue();
    ObjectValue *   currentObject = fCurrentContainer->AsObject();

    ODL_OBJENTER(); //####
// std::cout << __FUNCTION__ << std::endl;
// std::cout << "tag=" << tag << " : value=" << value->Describe() << std::endl;
    currentObject->AddValue(tag, value);
    ODL_OBJEXIT(); //####
} // InitValueListener::exitPair

void
InitValueListener::exitStringValue
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
    pushValue(new StringValue(fCurrentContainer, actualValue));
    ODL_OBJEXIT(); //####
} // InitValueListener::exitStringValue

void
InitValueListener::exitTag
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
} // InitValueListener::exitTag

InitValue *
InitValueListener::GetValue
	(const std::string &    input)
{
    try
    {
        delete fRootObject;
        fRootObject = nullptr;
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
} // InitValueListener::GetValue

InitValue *
InitValueListener::GetValue
	(std::istream & input)
{
    try
    {
        delete fRootObject;
        fRootObject = nullptr;
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
} // InitValueListener::GetValue

InitValue *
InitValueListener::popContainer
    (void)
{
    InitValue * result;

    if (fContainerStack.empty())
    {
        result = NULL;
    }
    else
    {
        result = fContainerStack.back();
        fContainerStack.pop_back();
    }
    return result;
} // InitValueListener::popContainer

std::string
InitValueListener::popTag
    (void)
{
  std::string result;

  if (! fTagStack.empty())
  {
    result = fTagStack.back();
    fTagStack.pop_back();
  }
  return result;
} // InitValueListener::popTag

InitValue *
InitValueListener::popValue
    (void)
{
    InitValue * result;

    if (fValueStack.empty())
    {
        result = NULL;
    }
    else
    {
        result = fValueStack.back();
        fValueStack.pop_back();
    }
    return result;
} // InitValueListener::popValue

InitValueListener &
InitValueListener::pushContainer
    (InitValue *  value)
{
    fContainerStack.push_back(value);
    return *this;
} // InitValueListener::pushContainer

InitValueListener &
InitValueListener::pushTag
    (const std::string  tag)
{
	fTagStack.push_back(tag);
    return *this;
} /* pushTag */

InitValueListener &
InitValueListener::pushValue
    (InitValue *  value)
{
    fValueStack.push_back(value);
    return *this;
} // InitValueListener::pushValue

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
