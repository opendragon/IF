//--------------------------------------------------------------------------------------------------
//
//  File:       Tests/ifContainersTest.cpp
//
//  Project:    IF
//
//  Contains:   The test driver for the unit tests of the InitFile common library.
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
//  Created:    2020-09-27
//
//--------------------------------------------------------------------------------------------------

#include "ifTestSupport.h"

#include <initFileAddress.h>
#include <initFileArray.h>
#include <initFileBoolean.h>
#include <initFileDouble.h>
#include <initFileInteger.h>
#include <initFileNull.h>
#include <initFileObject.h>
#include <initFileString.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#include <iomanip>
#include <iostream>
#include <sstream>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The test driver for the unit tests of the %InitFile common library. */
#if defined(__APPLE__)
# pragma clang diagnostic pop
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Namespace references
#endif // defined(__APPLE__)

using namespace InitFile;
using std::cerr;
using std::endl;

#if defined(__APPLE__)
# pragma mark Private structures, constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

/*! @brief The signal handler to catch requests to stop the service.
 @param[in] signal The signal being handled. */
[[noreturn]]
static void
catchSignal
    (int signal)
{
    ODL_ENTER(); //####
    ODL_I1("signal = ", signal); //####
    std::string message{"Exiting due to signal "};

    message += std::to_string(signal);
    message += " = ";
    message += NameOfSignal(signal);
#if 0
    IF_ERROR_(message.c_str());
#endif//0
    ODL_EXIT_EXIT(1); //####
    exit(1);
} // catchSignal

#if defined(__APPLE__)
# pragma mark *** Test Case 01 ***
#endif // defined(__APPLE__)

/*! @brief Perform a test case.
 @param[in] launchPath The command-line name used to launch the service.
 @param[in] subSelector The subtest to perform.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used for the test.
 @return @c 0 on success and @c 1 on failure. */
static int
doTestArrayValue
    (const char *   NOT_USED_(launchPath),
     const int      subSelector,
     const bool     expected,
     const int      NOT_USED_(argc),
     char **        NOT_USED_(argv))
{
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result = 1;

    try
    {
        SpArray aValue;
        bool    okSoFar;

        // 1) test that array values are distinct.
        // 2) test that an empty array value can be created.
        // 3) test that an empty array value is described correctly.
        // 4) test that an empty array value can be cloned.
        // 5) test that an empty array value is considered equal to itself.
        // 6) test that an empty array value and another empty array value are considered equal.
        // 7) test that an empty array value and another value type are not considered equal.
        // 8) test that an empty array value and its clone are considered equal.
        // 9) test that an array with a NULL value can be created.
        // 10) test that an array with a NULL value is described correctly.
        // 11) test that an array with a Boolean value can be created.
        // 12) test that an array with a Boolean value is described correctly.
        // 13) test that an array with a Integer value can be created.
        // 14) test that an array with a Integer value is described correctly.
        // 15) test that an array with a String value can be created.
        // 16) test that an array with a String value is described correctly.
        // 17) test that an array with two NULL values can be created.
        // 18) test that an array with two NULL value is described correctly.
        // 19) test that an array with two Boolean values can be created.
        // 20) test that an array with two Boolean value is described correctly.
        // 21) test that an array with two Integer values can be created.
        // 22) test that an array with two Integer value is described correctly.
        // 23) test that an array with two String values can be created.
        // 24) test that an array with two String value is described correctly.
        // 25) test that an array with a NULL value is different from an array with a Boolean value.
        // 26) test that an array with a Boolean value is different from an array with an Integer value.
        // 27) test that an array with an Integer value is different from an array with a Double value.
        // 28) test that an array with a Double value is different from an array with a String value.
        // 29) test that an array with a String value is different from an array with an Address value.
        // 30) test that an array with an Address value is different from an array with a NULL value.
        // 31) test that an array value with a NULL value can be cloned and is considered to be equal.
        // 32) test that an array value with a Boolean value can be cloned and is considered to be equal.
        // 33) test that an array value with an integer value can be cloned and is considered to be equal.
        // 34) test that an array value with a string value can be cloned and is considered to be equal.
        // 35) test that an array value with a double value can be cloned and is considered to be equal.
        // 36) test that an array value with an address value can be cloned and is considered to be equal.
        // 37) test that an array value with an empty array value can be cloned and is considered to be equal.
        // 38) test that an array value with an empty object value can be cloned and is considered to be equal.
        // 39) test that an array value with two NULL values can be cloned and is considered to be equal.
        // 40) test that an array value with two Boolean values can be cloned and is considered to be equal.
        // 41) test that an array value with two integer values can be cloned and is considered to be equal.
        // 42) test that an array value with two string values can be cloned and is considered to be equal.
        // 43) test that an array value with two double values can be cloned and is considered to be equal.
        // 44) test that an array value with two address values can be cloned and is considered to be equal.
        // 45) test that an array value with two empty array values can be cloned and is considered to be equal.
        // 46) test that an array value with two empty object values can be cloned and is considered to be equal.
        // 47) test that an array value with a NULL value and a Boolean value can be cloned and is considered to be equal.
        // 48) test that an array value with a Boolean value and an integer value can be cloned and is considered to be equal.
        // 49) test that an array value with an integer value and a string value can be cloned and is considered to be equal.
        // 50) test that an array value with a string value and an address value can be cloned and is considered to be equal.
        // 51) test that an array value with an address value and a double value can be cloned and is considered to be equal.
        // 52) test that an array value with a double value and a NULL value can be cloned and is considered to be an equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray() && (! aValue->AsAddress()) && (! aValue->AsBoolean()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) &&
                            (! aValue->AsObject()) && (! aValue->AsString()));
                break;

            case 2 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray() && (0 == aValue->HowManyValues()));
                break;

            case 3 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("[ ]" == buffer.str());
                }
                break;

            case 4 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsArray() && (0 == otherValue->AsArray()->HowManyValues()));
                }
                break;

            case 5 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray() && (*aValue == *aValue));
                break;

            case 6 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::ArrayValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsArray() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpNull  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsArray() && (*aValue == *otherValue));
                }
                break;

            case 9 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  gotValue{aValue->GetValue(0)};

                    okSoFar = (gotValue && gotValue->AsNull());
                }
                break;

            case 10 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    std::ostringstream  buffer;
                    std::string         expectedString{"[ null ]"};

                    aValue->Print(buffer);
                    okSoFar = (expectedString == buffer.str());
                }
                break;

            case 11 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value = (0.5 <= RandomDouble());
                    SpBase  otherValue{new InitFile::BooleanValue(nullptr, value)};

                    okSoFar = (otherValue && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBase  gotValue{aValue->GetValue(0)};

                        okSoFar = (gotValue && gotValue->AsBoolean() && (value == gotValue->AsBoolean()->GetValue()));
                    }
                }
                break;

            case 12 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value = (0.5 <= RandomDouble());
                    SpBase  otherValue{new InitFile::BooleanValue(nullptr, value)};

                    okSoFar = (otherValue && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString{"[ "};

                        expectedString += (value ? "true" : "false");
                        expectedString += " ]";
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 13 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    SpBase  otherValue{new InitFile::IntegerValue(nullptr, number)};

                    okSoFar = (otherValue && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBase  gotValue{aValue->GetValue(0)};

                        okSoFar = (gotValue && gotValue->AsInteger() && (number == gotValue->AsInteger()->GetValue()));
                    }
                }
                break;

            case 14 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    SpBase  otherValue{new InitFile::IntegerValue(nullptr, number)};

                    okSoFar = (otherValue && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString{"[ "};

                        expectedString += std::to_string(number);
                        expectedString += " ]";
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 15 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString{std::to_string(RandomDouble(-1000, 1000))};
                    SpBase      otherValue{new InitFile::StringValue(nullptr, testString)};

                    okSoFar = (otherValue && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBase  gotValue{aValue->GetValue(0)};

                        okSoFar = (gotValue && gotValue->AsString() && (testString == gotValue->AsString()->GetValue()));
                    }
                }
                break;

            case 16 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString{std::to_string(RandomDouble(-1000, 1000))};
                    SpBase      otherValue{new InitFile::StringValue(nullptr, testString)};

                    okSoFar = (otherValue && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString;

                        expectedString = "[ " + kDQ + testString + kDQ + " ]";
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 17 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::NullValue(nullptr)};
                    SpBase  otherValue2{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue1 && otherValue1->AsNull() && otherValue2 && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  gotValue1{aValue->GetValue(0)};
                    SpBase  gotValue2{aValue->GetValue(1)};

                    okSoFar = (gotValue1 && gotValue1->AsNull() && gotValue2 && gotValue2->AsNull());
                }
                break;

            case 18 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::NullValue(nullptr)};
                    SpBase  otherValue2{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue1 && otherValue1->AsNull() && otherValue2 && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    std::ostringstream  buffer;
                    std::string         expectedString{"[ null,\nnull ]"};

                    aValue->Print(buffer);
                    okSoFar = (expectedString == buffer.str());
                }
                break;

            case 19 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value1 = (0.5 <= RandomDouble());
                    bool    value2 = (0.5 <= RandomDouble());
                    SpBase  otherValue1{new InitFile::BooleanValue(nullptr, value1)};
                    SpBase  otherValue2{new InitFile::BooleanValue(nullptr, value2)};

                    okSoFar = (otherValue1 && otherValue1->AsBoolean() && otherValue2 && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBase  gotValue1{aValue->GetValue(0)};
                        SpBase  gotValue2{aValue->GetValue(1)};

                        okSoFar = (gotValue1 && gotValue1->AsBoolean() && (value1 == gotValue1->AsBoolean()->GetValue()) &&
                                    gotValue2 && gotValue2->AsBoolean() && (value2 == gotValue2->AsBoolean()->GetValue()));
                    }
                }
                break;

            case 20 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value1 = (0.5 <= RandomDouble());
                    bool    value2 = (0.5 <= RandomDouble());
                    SpBase  otherValue1{new InitFile::BooleanValue(nullptr, value1)};
                    SpBase  otherValue2{new InitFile::BooleanValue(nullptr, value2)};

                    okSoFar = (otherValue1 && otherValue1->AsBoolean() && otherValue2 && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString{"[ "};

                        expectedString += (value1 ? "true" : "false");
                        expectedString += ",\n";
                        expectedString += (value2 ? "true" : "false");
                        expectedString += " ]";
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 21 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number1 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    int64_t number2 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    SpBase  otherValue1{new InitFile::IntegerValue(nullptr, number1)};
                    SpBase  otherValue2{new InitFile::IntegerValue(nullptr, number2)};

                    okSoFar = (otherValue1 && otherValue1->AsInteger() && otherValue2 && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBase  gotValue1{aValue->GetValue(0)};
                        SpBase  gotValue2{aValue->GetValue(1)};

                        okSoFar = (gotValue1 && gotValue1->AsInteger() && (number1 == gotValue1->AsInteger()->GetValue()) &&
                                    gotValue2 && gotValue2->AsInteger() && (number2 == gotValue2->AsInteger()->GetValue()));
                    }
                }
                break;

            case 22 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number1 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    int64_t number2 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    SpBase  otherValue1{new InitFile::IntegerValue(nullptr, number1)};
                    SpBase  otherValue2{new InitFile::IntegerValue(nullptr, number2)};

                    okSoFar = (otherValue1 && otherValue1->AsInteger() && otherValue2 && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString{"[ "};

                        expectedString += std::to_string(number1);
                        expectedString += ",\n";
                        expectedString += std::to_string(number2);
                        expectedString += " ]";
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 23 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString1{std::to_string(RandomDouble(-1000, 1000))};
                    std::string testString2{std::to_string(RandomDouble(-1000, 1000))};
                    SpBase      otherValue1{new InitFile::StringValue(nullptr, testString1)};
                    SpBase      otherValue2{new InitFile::StringValue(nullptr, testString2)};

                    okSoFar = (otherValue1 && otherValue1->AsString() && otherValue2 && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBase  gotValue1{aValue->GetValue(0)};
                        SpBase  gotValue2{aValue->GetValue(1)};

                        okSoFar = (gotValue1 && gotValue1->AsString() && (testString1 == gotValue1->AsString()->GetValue()) &&
                                    gotValue2 && gotValue2->AsString() && (testString2 == gotValue2->AsString()->GetValue()));
                    }
                }
                break;

            case 24 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString1{std::to_string(RandomDouble(-1000, 1000))};
                    std::string testString2{std::to_string(RandomDouble(-1000, 1000))};
                    SpBase      otherValue1{new InitFile::StringValue(nullptr, testString1)};
                    SpBase      otherValue2{new InitFile::StringValue(nullptr, testString2)};

                    okSoFar = (otherValue1 && otherValue1->AsString() && otherValue2 && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString;

                        expectedString = "[ " + kDQ + testString1 + kDQ + ",\n" + kDQ + testString2 + kDQ + " ]";
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 25:
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpArray     otherArray{new InitFile::ArrayValue(nullptr)};
                    SpBoolean   otherValue{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = (otherArray && otherArray->AsArray() && otherValue && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        otherArray->AddValueAtBack(otherValue);
                        okSoFar = (1 == otherArray->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        okSoFar = (*aValue == *otherArray);
                    }
                }
                break;

            case 26:
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value = (0.5 <= RandomDouble());
                    SpBase  otherValue{new InitFile::BooleanValue(nullptr, value)};

                    okSoFar = (otherValue && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpArray     otherArray{new InitFile::ArrayValue(nullptr)};
                    SpInteger   otherValue{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherArray && otherArray->AsArray() && otherValue && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        otherArray->AddValueAtBack(otherValue);
                        okSoFar = (1 == otherArray->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        okSoFar = (*aValue == *otherArray);
                    }
                }
                break;

            case 27:
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpArray     otherArray{new InitFile::ArrayValue(nullptr)};
                    SpDouble    otherValue{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = (otherArray && otherArray->AsArray() && otherValue && otherValue->AsDouble());
                    if (okSoFar)
                    {
                        otherArray->AddValueAtBack(otherValue);
                        okSoFar = (1 == otherArray->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        okSoFar = (*aValue == *otherArray);
                    }
                }
                break;

            case 28:
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = (otherValue && otherValue->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpArray     otherArray{new InitFile::ArrayValue(nullptr)};
                    SpString    otherValue{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherArray && otherArray->AsArray() && otherValue && otherValue->AsString());
                    if (okSoFar)
                    {
                        otherArray->AddValueAtBack(otherValue);
                        okSoFar = (1 == otherArray->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        okSoFar = (*aValue == *otherArray);
                    }
                }
                break;

            case 29:
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpArray     otherArray{new InitFile::ArrayValue(nullptr)};
                    SpAddress   otherValue{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = (otherArray && otherArray->AsArray() && otherValue && otherValue->AsAddress());
                    if (okSoFar)
                    {
                        otherArray->AddValueAtBack(otherValue);
                        okSoFar = (1 == otherArray->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        okSoFar = (*aValue == *otherArray);
                    }
                }
                break;

            case 30 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpBase      otherValue{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = (otherValue && otherValue->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpArray otherArray{new InitFile::ArrayValue(nullptr)};
                    SpNull  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherArray && otherArray->AsArray() && otherValue && otherValue->AsNull());
                    if (okSoFar)
                    {
                        otherArray->AddValueAtBack(otherValue);
                        okSoFar = (1 == otherArray->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        okSoFar = (*aValue == *otherArray);
                    }
                }
                break;

            case 31 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 32 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = (otherValue && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 33 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 34 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 35 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = (otherValue && otherValue->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 36 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpBase      otherValue{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = (otherValue && otherValue->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 37 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::ArrayValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsArray());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 38 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::ObjectValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsObject());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 39 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::NullValue(nullptr)};
                    SpBase  otherValue2{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue1 && otherValue1->AsNull() && otherValue2 && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 40 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};
                    SpBase  otherValue2{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = (otherValue1 && otherValue1->AsBoolean() && otherValue2 && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 41 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    SpBase  otherValue2{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue1 && otherValue1->AsInteger() && otherValue2 && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 42 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    SpBase  otherValue2{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue1 && otherValue1->AsString() && otherValue2 && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 43 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};
                    SpBase  otherValue2{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = (otherValue1 && otherValue1->AsDouble() && otherValue2 && otherValue2->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 44 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpBase      otherValue1{new InitFile::AddressValue(nullptr, inValue)};
                    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    SpBase      otherValue2{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = (otherValue1 && otherValue1->AsAddress() && otherValue2 && otherValue2->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 45 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::ArrayValue(nullptr)};
                    SpBase  otherValue2{new InitFile::ArrayValue(nullptr)};

                    okSoFar = (otherValue1 && otherValue1->AsArray() && otherValue2 && otherValue2->AsArray());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 46 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::ObjectValue(nullptr)};
                    SpBase  otherValue2{new InitFile::ObjectValue(nullptr)};

                    okSoFar = (otherValue1 && otherValue1->AsObject() && otherValue2 && otherValue2->AsObject());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 47 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::NullValue(nullptr)};
                    SpBase  otherValue2{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = (otherValue1 && otherValue1->AsNull() && otherValue2 && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 48 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};
                    SpBase  otherValue2{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue1 && otherValue1->AsBoolean() && otherValue2 && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 49 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    SpBase  otherValue2{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = (otherValue1 && otherValue1->AsInteger() && otherValue2 && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 50 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpBase      otherValue1{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    SpBase      otherValue2{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = (otherValue1 && otherValue1->AsString() && otherValue2 && otherValue2->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 51 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpBase      otherValue1{new InitFile::AddressValue(nullptr, inValue)};
                    SpBase      otherValue2{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = (otherValue1 && otherValue1->AsAddress() && otherValue2 && otherValue2->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            case 52 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                okSoFar = (aValue && aValue->AsArray());
                if (okSoFar)
                {
                    SpBase  otherValue1{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};
                    SpBase  otherValue2{new InitFile::NullValue(nullptr)};

                    okSoFar = (otherValue1 && otherValue1->AsDouble() && otherValue2 && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBase  clonedValue{aValue->Clone()};

                    okSoFar = (clonedValue && (*clonedValue == *aValue));
                }
                break;

            default :
                okSoFar = false;
                break;

        }
        result = ((expected == okSoFar) ? 0 : 1);
    }
    catch (...)
    {
        ODL_LOG("Exception caught"); //####
        throw;
    }
    ODL_EXIT_I(result); //####
    return result;
} // doTestArrayValue

#if defined(__APPLE__)
# pragma mark *** Test Case 02 ***
#endif // defined(__APPLE__)

/*! @brief Perform a test case.
 @param[in] launchPath The command-line name used to launch the service.
 @param[in] subSelector The subtest to perform.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used for the test.
 @return @c 0 on success and @c 1 on failure. */
static int
doTestObjectValue
    (const char *   NOT_USED_(launchPath),
     const int      subSelector,
     const bool     expected,
     const int      NOT_USED_(argc),
     char **        NOT_USED_(argv))
{
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result = 1;

    try
    {
        SpObject    aValue;
        bool        okSoFar;

        // 1) test that object values are distinct.
        // 2) test that an empty object value can be created.
        // 3) test that an empty object value is described correctly.
        // 4) test that an empty object value can be cloned.
        // 5) test that an empty object value is considered equal to itself.
        // 6) test that an empty object value and another empty object value are considered equal.
        // 7) test that an empty object value and another value type are not considered equal.
        // 8) test that an empty object value and its clone are considered equal.
        // 9) test that an object value with a NULL value can be created and has the correct value.
        // 10) test that an object value with a NULL value has the correct tag.
        // 11) test that an object value with a NULL value can be created and describes itself correctly.
        // 12) test that an object value with a Boolean value can be created and has the correct value.
        // 13) test that an object value with a Boolean value can be created and describes itself correctly.
        // 14) test that an object value with an integer value can be created and has the correct value.
        // 15) test that an object value with an integer value can be created and describes itself correctly.
        // 16) test that an object value with an string value can be created and has the correct value.
        // 17) test that an object value with an string value can be created and describes itself correctly.
        // 18) test that an object value with two NULL values can be created and has the correct value.
        // 19) test that an object value with two NULL values can be created and has the correct tags.
        // 20) test that an object value with two NULL values can be created and describes itself correctly.
        // 21) test that an object value with two Boolean values can be created and has the correct value.
        // 22) test that an object value with two Boolean values can be created and describes itself correctly.
        // 23) test that an object value with two integer values can be created and has the correct value.
        // 24) test that an object value with two integer values can be created and describes itself correctly.
        // 25) test that an object value with two string values can be created and has the correct value.
        // 26) test that an object value with two string values can be created and describes itself correctly.
        // 27) test that an object value with a NULL value is different from an object value with a Boolean value.
        // 28) test that an object value with a Boolean value is different from an object value with an integer value.
        // 29) test that an object value with an integer value is different from an object value with a double value.
        // 30) test that an object value with a double value is different from an object value with a string value.
        // 31) test that an object value with a string value is different from an object value with an address value.
        // 32) test that an object value with an address value is different from an objectvalue with a NULL value.
        // 33) test that an object value with a NULL value can be cloned and is considered to be equal.
        // 34) test that an object value with a Boolean value can be cloned and is considered to be equal.
        // 35) test that an object value with an integer value can be cloned and is considered to be equal.
        // 36) test that an object value with a string value can be cloned and is considered to be equal.
        // 37) test that an object value with a double value can be cloned and is considered to be equal.
        // 38) test that an object value with an address value can be cloned and is considered to be equal.
        // 39) test that an object value with an empty array value can be cloned and is considered to be equal.
        // 40) test that an object value with an empty object value can be cloned and is considered to be equal.
        // 41) test that an object value with two NULL values can be cloned and is considered to be equal.
        // 42) test that an object value with two Boolean values can be cloned and is considered to be equal.
        // 43) test that an object value with two integer values can be cloned and is considered to be equal.
        // 44) test that an object value with two string values can be cloned and is considered to be equal.
        // 45) test that an object value with two double values can be cloned and is considered to be equal.
        // 46) test that an object value with two address values can be cloned and is considered to be equal.
        // 47) test that an object value with two empty array values can be cloned and is considered to be equal.
        // 48) test that an object value with two empty object values can be cloned and is considered to be equal.
        // 49) test that an object value with a NULL value and a Boolean value can be cloned and is considered to be equal.
        // 50) test that an object value with a Boolean value and an integer value can be cloned and is considered to be equal.
        // 51) test that an object value with an integer value and a string value can be cloned and is considered to be equal.
        // 52) test that an object value with a string value and an address value can be cloned and is considered to be equal.
        // 53) test that an object value with an address value and a double value can be cloned and is considered to be equal.
        // 54) test that an object value with a double value and a NULL value can be cloned and is considered to be equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject() && (! aValue->AsArray()) && (! aValue->AsAddress()) &&
                            (! aValue->AsBoolean()) && (! aValue->AsDouble()) && (! aValue->AsInteger()) &&
                            (! aValue->AsNull()) && (! aValue->AsString()));
                break;

            case 2 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject() && (0 == aValue->HowManyValues()));
                break;

            case 3 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("{ }" == buffer.str());
                }
                break;

            case 4 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsObject() && (0 == otherValue->AsObject()->HowManyValues()));
                }
                break;

            case 5 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject() && (*aValue == *aValue));
                break;

            case 6 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    SpBase  otherValue{new InitFile::ObjectValue(nullptr)};

                    okSoFar = (otherValue && otherValue->AsObject() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    SpNull  otherValue{new InitFile::NullValue(nullptr)};

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsObject() && (*aValue == *otherValue));
                }
                break;

            case 9 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved{aValue->GetValue(tagForAdd)};

                        okSoFar = (valueRetrieved && valueRetrieved->AsNull() && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 10 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::set<std::string>   tags{aValue->GetTags()};

                        if (1 == tags.size())
                        {
                            okSoFar = (tags.end() != tags.find(tagForAdd));
                        }
                    }
                }
                break;

            case 11 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd + kDQ + " : null }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 12 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved(aValue->GetValue(tagForAdd));

                        okSoFar = (valueRetrieved && valueRetrieved->AsBoolean() && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 13 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd + kDQ + " : " + (valueToAdd->GetValue() ? "true" : "false") + " }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 14 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved(aValue->GetValue(tagForAdd));

                        okSoFar = (valueRetrieved && valueRetrieved->AsInteger() && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 15 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd + kDQ + " : " + std::to_string(valueToAdd->GetValue()) + " }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 16 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved(aValue->GetValue(tagForAdd));

                        okSoFar = (valueRetrieved && valueRetrieved->AsString() && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 17 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd + kDQ + " : " + kDQ + valueToAdd->GetValue() + kDQ + " }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 18 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd1{new InitFile::NullValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd2{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved1(aValue->GetValue(tagForAdd1));

                        okSoFar = (valueRetrieved1 && valueRetrieved1->AsNull() && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBase  valueRetrieved2(aValue->GetValue(tagForAdd2));

                            okSoFar = (valueRetrieved2 && valueRetrieved2->AsNull() && (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 19 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd1{new InitFile::NullValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd2{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::set<std::string>   tags{aValue->GetTags()};

                        if (2 == tags.size())
                        {
                            okSoFar = ((tags.end() != tags.find(tagForAdd1)) && (tags.end() != tags.find(tagForAdd2)));
                        }
                    }
                }
                break;

            case 20 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd1{new InitFile::NullValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd2{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd1 + kDQ + " : null,\n" + kDQ + tagForAdd2 + kDQ + " : null }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ " + kDQ + tagForAdd2 + kDQ + " : null,\n" + kDQ + tagForAdd1 + kDQ + " : null }";
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 21 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd1{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd2{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved1(aValue->GetValue(tagForAdd1));

                        okSoFar = (valueRetrieved1 && valueRetrieved1->AsBoolean() && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBase  valueRetrieved2(aValue->GetValue(tagForAdd2));

                            okSoFar = (valueRetrieved2 && valueRetrieved2->AsBoolean() && (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 22 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd1{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd2{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd1 + kDQ + " : " + (valueToAdd1->GetValue() ? "true" : "false") + ",\n" +
                                    kDQ + tagForAdd2 + kDQ + " : " + (valueToAdd2->GetValue() ? "true" : "false") + " }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ " + kDQ + tagForAdd2 + kDQ + " : " + (valueToAdd2->GetValue() ? "true" : "false") +
                                        ",\n" + kDQ + tagForAdd1 + kDQ + " : " + (valueToAdd1->GetValue() ? "true" : "false") + " }";
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 23 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd1{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd2{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved1(aValue->GetValue(tagForAdd1));

                        okSoFar = (valueRetrieved1 && valueRetrieved1->AsInteger() && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBase  valueRetrieved2(aValue->GetValue(tagForAdd2));

                            okSoFar = (valueRetrieved2 && valueRetrieved2->AsInteger() && (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 24 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd1{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd2{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd1 + kDQ + " : " + std::to_string(valueToAdd1->GetValue()) + ",\n" +
                                    kDQ + tagForAdd2 + kDQ + " : " + std::to_string(valueToAdd2->GetValue()) + " }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ " + kDQ + tagForAdd2 + kDQ + " : " + std::to_string(valueToAdd2->GetValue()) + ",\n" +
                                        kDQ + tagForAdd1 + kDQ + " : " + std::to_string(valueToAdd1->GetValue()) + " }";
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 25 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd1{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd2{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  valueRetrieved1(aValue->GetValue(tagForAdd1));

                        okSoFar = (valueRetrieved1 && valueRetrieved1->AsString() && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBase  valueRetrieved2(aValue->GetValue(tagForAdd2));

                            okSoFar = (valueRetrieved2 && valueRetrieved2->AsString() && (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 26 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd1{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd2{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ " + kDQ + tagForAdd1 + kDQ + " : " + kDQ + valueToAdd1->GetValue() + kDQ + ",\n" +
                                    kDQ + tagForAdd2 + kDQ + " : " + kDQ + valueToAdd2->GetValue() + kDQ + " }";
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ " + kDQ + tagForAdd2 + kDQ + " : " + kDQ + valueToAdd2->GetValue() + kDQ + ",\n" +
                                        kDQ + tagForAdd1 + kDQ + " : " + kDQ + valueToAdd1->GetValue() + kDQ + " }";
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 27 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpObject    anotherValue{new InitFile::ObjectValue(nullptr)};

                        if (anotherValue && anotherValue->AsObject())
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            SpBoolean   anotherValueToAdd{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                            anotherValue->AddValue(anotherTag, anotherValueToAdd);
                            if (1 == anotherValue->HowManyValues())
                            {
                                okSoFar = (*aValue == *anotherValue);
                            }
                        }
                    }
                }
                break;

            case 28 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpObject    anotherValue{new InitFile::ObjectValue(nullptr)};

                        if (anotherValue && anotherValue->AsObject())
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            SpInteger   anotherValueToAdd{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                            anotherValue->AddValue(anotherTag, anotherValueToAdd);
                            if (1 == anotherValue->HowManyValues())
                            {
                                okSoFar = (*aValue == *anotherValue);
                            }
                        }
                    }
                }
                break;

            case 29 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpObject    anotherValue{new InitFile::ObjectValue(nullptr)};

                        if (anotherValue && anotherValue->AsObject())
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            SpDouble    anotherValueToAdd{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                            anotherValue->AddValue(anotherTag, anotherValueToAdd);
                            if (1 == anotherValue->HowManyValues())
                            {
                                okSoFar = (*aValue == *anotherValue);
                            }
                        }
                    }
                }
                break;

            case 30 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpDouble    valueToAdd{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpObject    anotherValue{new InitFile::ObjectValue(nullptr)};

                        if (anotherValue && anotherValue->AsObject())
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            SpString    anotherValueToAdd{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                            anotherValue->AddValue(anotherTag, anotherValueToAdd);
                            if (1 == anotherValue->HowManyValues())
                            {
                                okSoFar = (*aValue == *anotherValue);
                            }
                        }
                    }
                }
                break;

            case 31 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpObject    anotherValue{new InitFile::ObjectValue(nullptr)};

                        if (anotherValue && anotherValue->AsObject())
                        {
                            uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                            uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                            uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                            uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                            uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            SpAddress   anotherValueToAdd{new InitFile::AddressValue(nullptr, inValue)};

                            anotherValue->AddValue(anotherTag, anotherValueToAdd);
                            if (1 == anotherValue->HowManyValues())
                            {
                                okSoFar = (*aValue == *anotherValue);
                            }
                        }
                    }
                }
                break;

            case 32 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpAddress   valueToAdd{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpObject    anotherValue{new InitFile::ObjectValue(nullptr)};

                        if (anotherValue && anotherValue->AsObject())
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            SpNull      anotherValueToAdd{new InitFile::NullValue(nullptr)};

                            anotherValue->AddValue(anotherTag, anotherValueToAdd);
                            if (1 == anotherValue->HowManyValues())
                            {
                                okSoFar = (*aValue == *anotherValue);
                            }
                        }
                    }
                }
                break;

            case 33 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 34 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 35 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 36 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 37 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpDouble    valueToAdd{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 38 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    SpAddress   valueToAdd{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 39 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpArray     valueToAdd{new InitFile::ArrayValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 40 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    SpObject    valueToAdd{new InitFile::ObjectValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 41 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd1{new InitFile::NullValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd2{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 42 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd1{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd2{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 43 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd1{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd2{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 44 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd1{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd2{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 45 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpDouble    valueToAdd1{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpDouble    valueToAdd2{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 46 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpAddress   valueToAdd1{new InitFile::AddressValue(nullptr, inValue)};
                    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpAddress   valueToAdd2{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 47 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpArray     valueToAdd1{new InitFile::ArrayValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpArray     valueToAdd2{new InitFile::ArrayValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 48 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpObject    valueToAdd1{new InitFile::ObjectValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpObject    valueToAdd2{new InitFile::ObjectValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 49 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd1{new InitFile::NullValue(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd2{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 50 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpBoolean   valueToAdd1{new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd2{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 51 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpInteger   valueToAdd1{new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd2{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 52 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpString    valueToAdd1{new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpAddress   valueToAdd2{new InitFile::AddressValue(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 53 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpAddress   valueToAdd1{new InitFile::AddressValue(nullptr, inValue)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpDouble    valueToAdd2{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            case 54 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                okSoFar = (aValue && aValue->AsObject());
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    SpDouble    valueToAdd1{new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    SpNull      valueToAdd2{new InitFile::NullValue(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBase  clonedValue{aValue->Clone()};

                        okSoFar = (clonedValue && (*clonedValue == *aValue));
                    }
                }
                break;

            default :
                okSoFar = false;
                break;

        }
        result = ((expected == okSoFar) ? 0 : 1);
    }
    catch (...)
    {
        ODL_LOG("Exception caught"); //####
        throw;
    }
    ODL_EXIT_I(result); //####
    return result;
} // doTestObjectValue

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
/*! @brief The entry point for unit tests of the %InitFile common classes.

 The first argument is the test number, the second argument is the name of the channel to be used
 with the test, the optional third argument is the machine to connect to and the optional fourth
 argument is the port number to be used. Output depends on the test being run.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used with the unit tests.
 @return @c 0 on a successful test and @c 1 on failure. */
int
main
    (int        argc,
     char **    argv)
{
    std::string progName{*argv};

    ODL_INIT(progName.c_str(), kODLoggingOptionIncludeProcessID | //####
             kODLoggingOptionIncludeThreadID | kODLoggingOptionEnableThreadSupport | //####
             kODLoggingOptionWriteToStderr); //####
    ODL_ENTER(); //####
#if 0
#if MAC_OR_LINUX_
    SetUpLogger(progName);
#endif // MAC_OR_LINUX_
#endif//0
    int result = 1;

    try
    {
        Initialize(progName);
        if (2 < --argc)
        {
            int64_t selector;
            int64_t subSelector;
            bool    expected = (('t' == *argv[2]) || ('T' == *argv[2]));

            ODL_B1("expected <- ", expected); //####
            if (ConvertToInt64(argv[1], selector) && (0 < selector) &&
                ConvertToInt64(argv[3], subSelector) && (0 < subSelector))
            {
                SetSignalHandlers(catchSignal);
                switch (selector)
                {

                    case 1 :
                        // Array value
                        result = doTestArrayValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 2 :
                        // Object value
                        result = doTestObjectValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    default :
                        break;

                }
                if (result)
                {
                    ODL_I1("%%%%%%% unit test failure = ", result); //####
                }
            }
            else
            {
                ODL_LOG("! (ConvertToInt64(argv[1], selector) && (0 < selector) && " //####
                        "ConvertToInt64(argv[3], subSelector) && (0 < subSelector))"); //####
            }
        }
        else
        {
            ODL_LOG("! (2 < --argc)"); //####
        }
    }
    catch (...)
    {
        ODL_LOG("Exception caught"); //####
        throw;
    }
    ODL_EXIT_I(result); //####
    return result;
} // main
