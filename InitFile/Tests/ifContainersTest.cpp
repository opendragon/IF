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

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

//#include <odlEnable.h>
#include <odlInclude.h>

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
using namespace std::string_literals;

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
    ODL_I1(signal); //####
    std::string message{"Exiting due to signal "s + std::to_string(signal) + " = "s + NameOfSignal(signal)};

    INITFILE_UNUSED_VAR_(message);
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
    (const char *   launchPath,
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    INITFILE_UNUSED_VAR_(launchPath);
    INITFILE_UNUSED_VAR_(argc);
    INITFILE_UNUSED_VAR_(argv);
    ODL_ENTER(); //####
    //ODL_S1(launchPath); //####
    ODL_I2(subSelector, argc); //####
    ODL_B1(expected); //####
    ODL_P1(argv); //####
    int result{1};

    try
    {
        SpArrayValue    aValue;
        bool            okSoFar;

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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (nullptr == aValue->AsAddress()) && (nullptr == aValue->AsBoolean()) &&
                            (nullptr == aValue->AsDouble()) && (nullptr == aValue->AsInteger()) && (nullptr == aValue->AsNull()) &&
                            (nullptr == aValue->AsObject()) && (nullptr == aValue->AsString()));
                break;

            case 2 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray() && (0 == aValue->HowManyValues()));
                break;

            case 3 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("[ ]" == buffer.str());
                }
                break;

            case 4 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    UpBaseValue  otherValue{aValue->Clone()};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsArray() && (0 == otherValue->AsArray()->HowManyValues()));
                }
                break;

            case 5 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray() && (*aValue == *aValue));
                break;

            case 6 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::ArrayValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsArray() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    UpBaseValue  otherValue{aValue->Clone()};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsArray() && (*aValue == *otherValue));
                }
                break;

            case 9 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBaseValue  gotValue{aValue->GetValue(0)};

                    okSoFar = ((nullptr != gotValue) && gotValue->AsNull());
                }
                break;

            case 10 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsNull());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value = (0.5 <= RandomDouble());
                    auto    otherValue{std::make_shared<InitFile::BooleanValue>(nullptr, value)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBaseValue  gotValue{aValue->GetValue(0)};

                        okSoFar = ((nullptr != gotValue) && gotValue->AsBoolean() && (value == gotValue->AsBoolean()->GetValue()));
                    }
                }
                break;

            case 12 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value = (0.5 <= RandomDouble());
                    auto    otherValue{std::make_shared<InitFile::BooleanValue>(nullptr, value)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsBoolean());
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
                        expectedString += " ]"s;
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 13 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    auto    otherValue{std::make_shared<InitFile::IntegerValue>(nullptr, number)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBaseValue  gotValue{aValue->GetValue(0)};

                        okSoFar = ((nullptr != gotValue) && gotValue->AsInteger() && (number == gotValue->AsInteger()->GetValue()));
                    }
                }
                break;

            case 14 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    auto    otherValue{std::make_shared<InitFile::IntegerValue>(nullptr, number)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString{"[ "s + std::to_string(number) + " ]"s};

                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 15 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString{std::to_string(RandomDouble(-1000, 1000))};
                    auto        otherValue{std::make_shared<InitFile::StringValue>(nullptr, testString)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBaseValue  gotValue{aValue->GetValue(0)};

                        okSoFar = ((nullptr != gotValue) && gotValue->AsString() && (testString == gotValue->AsString()->GetValue()));
                    }
                }
                break;

            case 16 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString{std::to_string(RandomDouble(-1000, 1000))};
                    auto        otherValue{std::make_shared<InitFile::StringValue>(nullptr, testString)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString;

                        expectedString = "[ "s + kDQ + testString + kDQ + " ]"s;
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 17 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::NullValue>(nullptr)};
                    auto    otherValue2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsNull() && (nullptr != otherValue2) && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    SpBaseValue  gotValue1{aValue->GetValue(0)};
                    SpBaseValue  gotValue2{aValue->GetValue(1)};

                    okSoFar = ((nullptr != gotValue1) && gotValue1->AsNull() && (nullptr != gotValue2) && gotValue2->AsNull());
                }
                break;

            case 18 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::NullValue>(nullptr)};
                    auto    otherValue2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsNull() && (nullptr != otherValue2) && otherValue2->AsNull());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value1 = (0.5 <= RandomDouble());
                    bool    value2 = (0.5 <= RandomDouble());
                    auto    otherValue1{std::make_shared<InitFile::BooleanValue>(nullptr, value1)};
                    auto    otherValue2{std::make_shared<InitFile::BooleanValue>(nullptr, value2)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsBoolean() && (nullptr != otherValue2) && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBaseValue  gotValue1{aValue->GetValue(0)};
                        SpBaseValue  gotValue2{aValue->GetValue(1)};

                        okSoFar = ((nullptr != gotValue1) && gotValue1->AsBoolean() && (value1 == gotValue1->AsBoolean()->GetValue()) &&
                                    (nullptr != gotValue2) && gotValue2->AsBoolean() && (value2 == gotValue2->AsBoolean()->GetValue()));
                    }
                }
                break;

            case 20 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value1 = (0.5 <= RandomDouble());
                    bool    value2 = (0.5 <= RandomDouble());
                    auto    otherValue1{std::make_shared<InitFile::BooleanValue>(nullptr, value1)};
                    auto    otherValue2{std::make_shared<InitFile::BooleanValue>(nullptr, value2)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsBoolean() && (nullptr != otherValue2) && otherValue2->AsBoolean());
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
                        expectedString += ",\n"s;
                        expectedString += (value2 ? "true" : "false");
                        expectedString += " ]"s;
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 21 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number1 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    int64_t number2 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    auto    otherValue1{std::make_shared<InitFile::IntegerValue>(nullptr, number1)};
                    auto    otherValue2{std::make_shared<InitFile::IntegerValue>(nullptr, number2)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsInteger() && (nullptr != otherValue2) && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBaseValue  gotValue1{aValue->GetValue(0)};
                        SpBaseValue  gotValue2{aValue->GetValue(1)};

                        okSoFar = ((nullptr != gotValue1) && gotValue1->AsInteger() && (number1 == gotValue1->AsInteger()->GetValue()) &&
                                    (nullptr != gotValue2) && gotValue2->AsInteger() && (number2 == gotValue2->AsInteger()->GetValue()));
                    }
                }
                break;

            case 22 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    int64_t number1 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    int64_t number2 = static_cast<int64_t>(RandomDouble(-1000, 1000));
                    auto    otherValue1{std::make_shared<InitFile::IntegerValue>(nullptr, number1)};
                    auto    otherValue2{std::make_shared<InitFile::IntegerValue>(nullptr, number2)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsInteger() && (nullptr != otherValue2) && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;
                        std::string         expectedString{"[ "s + std::to_string(number1) + ",\n"s + std::to_string(number2) + " ]"s};

                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 23 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString1{std::to_string(RandomDouble(-1000, 1000))};
                    std::string testString2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        otherValue1{std::make_shared<InitFile::StringValue>(nullptr, testString1)};
                    auto        otherValue2{std::make_shared<InitFile::StringValue>(nullptr, testString2)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsString() && (nullptr != otherValue2) && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                    if (okSoFar)
                    {
                        SpBaseValue  gotValue1{aValue->GetValue(0)};
                        SpBaseValue  gotValue2{aValue->GetValue(1)};

                        okSoFar = ((nullptr != gotValue1) && gotValue1->AsString() && (testString1 == gotValue1->AsString()->GetValue()) &&
                                    (nullptr != gotValue2) && gotValue2->AsString() && (testString2 == gotValue2->AsString()->GetValue()));
                    }
                }
                break;

            case 24 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    std::string testString1{std::to_string(RandomDouble(-1000, 1000))};
                    std::string testString2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        otherValue1{std::make_shared<InitFile::StringValue>(nullptr, testString1)};
                    auto        otherValue2{std::make_shared<InitFile::StringValue>(nullptr, testString2)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsString() && (nullptr != otherValue2) && otherValue2->AsString());
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

                        expectedString = "[ "s + kDQ + testString1 + kDQ + ",\n"s + kDQ + testString2 + kDQ + " ]"s;
                        aValue->Print(buffer);
                        okSoFar = (expectedString == buffer.str());
                    }
                }
                break;

            case 25:
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    auto    otherArray{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto    otherValue{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = ((nullptr != otherArray) && otherArray->AsArray() && (nullptr != otherValue) && otherValue->AsBoolean());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    bool    value = (0.5 <= RandomDouble());
                    auto    otherValue{std::make_shared<InitFile::BooleanValue>(nullptr, value)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    auto    otherArray{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto    otherValue{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherArray) && otherArray->AsArray() && (nullptr != otherValue) && otherValue->AsInteger());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    auto    otherArray{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto    otherValue{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = ((nullptr != otherArray) && otherArray->AsArray() && (nullptr != otherValue) && otherValue->AsDouble());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    auto    otherArray{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto    otherValue{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherArray) && otherArray->AsArray() && (nullptr != otherValue) && otherValue->AsString());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsString());
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
                    auto        otherArray{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto        otherValue{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = ((nullptr != otherArray) && otherArray->AsArray() && (nullptr != otherValue) && otherValue->AsAddress());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    auto        otherValue{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    auto    otherArray{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherArray) && otherArray->AsArray() && (nullptr != otherValue) && otherValue->AsNull());
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
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 32 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 33 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 34 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 35 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 36 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    auto        otherValue{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 37 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::ArrayValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsArray());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 38 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && otherValue->AsObject());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue);
                        okSoFar = (1 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 39 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::NullValue>(nullptr)};
                    auto    otherValue2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsNull() && (nullptr != otherValue2) && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 40 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};
                    auto    otherValue2{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsBoolean() && (nullptr != otherValue2) && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 41 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    auto    otherValue2{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsInteger() && (nullptr != otherValue2) && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 42 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    auto    otherValue2{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsString() && (nullptr != otherValue2) && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 43 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};
                    auto    otherValue2{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsDouble() && (nullptr != otherValue2) && otherValue2->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 44 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    auto        otherValue1{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};
                    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    auto    otherValue2{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsAddress() && (nullptr != otherValue2) && otherValue2->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 45 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    auto    otherValue2{std::make_shared<InitFile::ArrayValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsArray() && (nullptr != otherValue2) && otherValue2->AsArray());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 46 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::ObjectValue>(nullptr)};
                    auto    otherValue2{std::make_shared<InitFile::ObjectValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsObject() && (nullptr != otherValue2) && otherValue2->AsObject());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 47 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::NullValue>(nullptr)};
                    auto    otherValue2{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsNull() && (nullptr != otherValue2) && otherValue2->AsBoolean());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 48 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};
                    auto    otherValue2{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsBoolean() && (nullptr != otherValue2) && otherValue2->AsInteger());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 49 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    auto    otherValue2{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsInteger() && (nullptr != otherValue2) && otherValue2->AsString());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 50 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    auto        otherValue1{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    auto        otherValue2{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsString() && (nullptr != otherValue2) && otherValue2->AsAddress());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 51 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    uint32_t    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    auto        otherValue1{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};
                    auto        otherValue2{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsAddress() && (nullptr != otherValue2) && otherValue2->AsDouble());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                }
                break;

            case 52 :
                aValue = std::make_shared<InitFile::ArrayValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsArray());
                if (okSoFar)
                {
                    auto    otherValue1{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};
                    auto    otherValue2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue1) && otherValue1->AsDouble() && (nullptr != otherValue2) && otherValue2->AsNull());
                    if (okSoFar)
                    {
                        aValue->AddValueAtBack(otherValue1);
                        aValue->AddValueAtBack(otherValue2);
                        okSoFar = (2 == aValue->HowManyValues());
                    }
                }
                if (okSoFar)
                {
                    UpBaseValue  clonedValue{aValue->Clone()};

                    okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
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
    (const char *   launchPath,
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    INITFILE_UNUSED_VAR_(launchPath);
    INITFILE_UNUSED_VAR_(argc);
    INITFILE_UNUSED_VAR_(argv);
    ODL_ENTER(); //####
    //ODL_S1(launchPath); //####
    ODL_I2(subSelector, argc); //####
    ODL_B1(expected); //####
    ODL_P1(argv); //####
    int result{1};

    try
    {
        SpObjectValue   aValue;
        bool            okSoFar;

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && aValue->AsObject() && (nullptr == aValue->AsArray()) && (nullptr == aValue->AsAddress()) &&
                            (nullptr == aValue->AsBoolean()) && (nullptr == aValue->AsDouble()) && (nullptr == aValue->AsInteger()) &&
                            (nullptr == aValue->AsNull()) && (nullptr == aValue->AsString()));
                break;

            case 2 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (0 == aValue->HowManyValues()));
                break;

            case 3 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("{ }" == buffer.str());
                }
                break;

            case 4 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    UpBaseValue  otherValue{aValue->Clone()};

                    okSoFar = ((nullptr != otherValue) && (nullptr != otherValue->AsObject()) && (0 == otherValue->AsObject()->HowManyValues()));
                }
                break;

            case 5 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (*aValue == *aValue));
                break;

            case 6 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                    okSoFar = ((nullptr != otherValue) && (nullptr != otherValue->AsObject()) && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    auto    otherValue{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    UpBaseValue  otherValue{aValue->Clone()};

                    okSoFar = ((nullptr != otherValue) && (nullptr != otherValue->AsObject()) && (*aValue == *otherValue));
                }
                break;

            case 9 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved{aValue->GetValue(tagForAdd)};

                        okSoFar = ((nullptr != valueRetrieved) && (nullptr != valueRetrieved->AsNull()) && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 10 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::NullValue>(nullptr)};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd + kDQ + " : null }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 12 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved(aValue->GetValue(tagForAdd));

                        okSoFar = ((nullptr != valueRetrieved) && (nullptr != valueRetrieved->AsBoolean()) && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 13 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd + kDQ + " : "s + (valueToAdd->GetValue() ? "true"s : "false"s) + " }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 14 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved(aValue->GetValue(tagForAdd));

                        okSoFar = ((nullptr != valueRetrieved) && (nullptr != valueRetrieved->AsInteger()) && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 15 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd + kDQ + " : "s + std::to_string(valueToAdd->GetValue()) + " }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 16 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved(aValue->GetValue(tagForAdd));

                        okSoFar = ((nullptr != valueRetrieved) && (nullptr != valueRetrieved->AsString()) && (*valueToAdd == *valueRetrieved));
                    }
                }
                break;

            case 17 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd + kDQ + " : "s + kDQ + valueToAdd->GetValue() + kDQ + " }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                    }
                }
                break;

            case 18 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::NullValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved1{aValue->GetValue(tagForAdd1)};

                        okSoFar = ((nullptr != valueRetrieved1) && (nullptr != valueRetrieved1->AsNull()) && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBaseValue  valueRetrieved2{aValue->GetValue(tagForAdd2)};

                            okSoFar = ((nullptr != valueRetrieved2) && (nullptr != valueRetrieved2->AsNull()) && (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 19 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::NullValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::NullValue>(nullptr)};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::NullValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd1 + kDQ + " : null,\n"s + kDQ + tagForAdd2 + kDQ + " : null }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ "s + kDQ + tagForAdd2 + kDQ + " : null,\n"s + kDQ + tagForAdd1 + kDQ + " : null }"s;
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 21 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved1{aValue->GetValue(tagForAdd1)};

                        okSoFar = ((nullptr != valueRetrieved1) && (nullptr != valueRetrieved1->AsBoolean()) && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBaseValue  valueRetrieved2{aValue->GetValue(tagForAdd2)};

                            okSoFar = ((nullptr != valueRetrieved2) && (nullptr != valueRetrieved2->AsBoolean()) &&
                                       (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 22 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd1 + kDQ + " : "s + (valueToAdd1->GetValue() ? "true"s : "false"s) + ",\n"s +
                                    kDQ + tagForAdd2 + kDQ + " : "s + (valueToAdd2->GetValue() ? "true"s : "false"s) + " }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ "s + kDQ + tagForAdd2 + kDQ + " : "s + (valueToAdd2->GetValue() ? "true"s : "false"s) +
                                        ",\n"s + kDQ + tagForAdd1 + kDQ + " : "s + (valueToAdd1->GetValue() ? "true"s : "false"s) + " }"s;
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 23 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved1{aValue->GetValue(tagForAdd1)};

                        okSoFar = ((nullptr != valueRetrieved1) && (nullptr != valueRetrieved1->AsInteger()) && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBaseValue  valueRetrieved2{aValue->GetValue(tagForAdd2)};

                            okSoFar = ((nullptr != valueRetrieved2) && (nullptr != valueRetrieved2->AsInteger()) && (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 24 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd1 + kDQ + " : "s + std::to_string(valueToAdd1->GetValue()) + ",\n"s +
                                    kDQ + tagForAdd2 + kDQ + " : "s + std::to_string(valueToAdd2->GetValue()) + " }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ "s + kDQ + tagForAdd2 + kDQ + " : "s + std::to_string(valueToAdd2->GetValue()) + ",\n"s +
                                        kDQ + tagForAdd1 + kDQ + " : "s + std::to_string(valueToAdd1->GetValue()) + " }"s;
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 25 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        SpBaseValue  valueRetrieved1{aValue->GetValue(tagForAdd1)};

                        okSoFar = ((nullptr != valueRetrieved1) && (nullptr != valueRetrieved1->AsString()) && (*valueToAdd1 == *valueRetrieved1));
                        if (okSoFar)
                        {
                            SpBaseValue  valueRetrieved2{aValue->GetValue(tagForAdd2)};

                            okSoFar = ((nullptr != valueRetrieved2) && (nullptr != valueRetrieved2->AsString()) &&
                                       (*valueToAdd2 == *valueRetrieved2));
                        }
                    }
                }
                break;

            case 26 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        std::ostringstream  buffer;
                        std::string         expected;

                        expected = "{ "s + kDQ + tagForAdd1 + kDQ + " : "s + kDQ + valueToAdd1->GetValue() + kDQ + ",\n"s +
                                    kDQ + tagForAdd2 + kDQ + " : "s + kDQ + valueToAdd2->GetValue() + kDQ + " }"s;
                        aValue->Print(buffer);
                        okSoFar = (expected == buffer.str());
                        if (! okSoFar)
                        {
                            expected = "{ "s + kDQ + tagForAdd2 + kDQ + " : "s + kDQ + valueToAdd2->GetValue() + kDQ + ",\n"s +
                                        kDQ + tagForAdd1 + kDQ + " : "s + kDQ + valueToAdd1->GetValue() + kDQ + " }"s;
                            okSoFar = (expected == buffer.str());
                        }
                    }
                }
                break;

            case 27 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        auto    anotherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                        if ((nullptr != anotherValue) && (nullptr != anotherValue->AsObject()))
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            auto        anotherValueToAdd{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        auto    anotherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                        if ((nullptr != anotherValue) && (nullptr != anotherValue->AsObject()))
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            auto        anotherValueToAdd{std::make_shared<InitFile::IntegerValue>(nullptr,
                                                                                                   static_cast<int64_t>(RandomDouble(-1000, 1000)))};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        auto    anotherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                        if ((nullptr != anotherValue) && (nullptr != anotherValue->AsObject()))
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            auto        anotherValueToAdd{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        auto    anotherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                        if ((nullptr != anotherValue) && (nullptr != anotherValue->AsObject()))
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            auto        anotherValueToAdd{std::make_shared<InitFile::StringValue>(nullptr,
                                                                                                  std::to_string(RandomDouble(-1000, 1000)))};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        auto    anotherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                        if ((nullptr != anotherValue) && (nullptr != anotherValue->AsObject()))
                        {
                            uint32_t    byte0{static_cast<uint32_t>(RandomDouble(0, 255))};
                            uint32_t    byte1{static_cast<uint32_t>(RandomDouble(0, 255))};
                            uint32_t    byte2{static_cast<uint32_t>(RandomDouble(0, 255))};
                            uint32_t    byte3{static_cast<uint32_t>(RandomDouble(0, 255))};
                            uint32_t    inValue{(((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3};
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            auto        anotherValueToAdd{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    uint32_t    byte0{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte1{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte2{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte3{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    inValue{(((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3};
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        auto    anotherValue{std::make_shared<InitFile::ObjectValue>(nullptr)};

                        if ((nullptr != anotherValue) && (nullptr != anotherValue->AsObject()))
                        {
                            std::string anotherTag{std::to_string(RandomDouble(-1000, 1000))};
                            auto        anotherValueToAdd{std::make_shared<InitFile::NullValue>(nullptr)};

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
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 34 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 35 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 36 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 37 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 38 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    uint32_t    byte0{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte1{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte2{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte3{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    inValue{(((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3};
                    auto        valueToAdd{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 39 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::ArrayValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 40 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd{std::make_shared<InitFile::ObjectValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd, valueToAdd);
                    if (1 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 41 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::NullValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 42 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 43 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 44 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 45 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 46 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    uint32_t    byte0{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte1{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte2{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte3{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    inValue{(((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3};
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                    byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 47 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::ArrayValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::ArrayValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 48 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::ObjectValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::ObjectValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 49 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::NullValue>(nullptr)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 50 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::BooleanValue>(nullptr, 0.5 <= RandomDouble())};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 51 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::IntegerValue>(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 52 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    uint32_t    byte0{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte1{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte2{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte3{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    inValue{(((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3};
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::StringValue>(nullptr, std::to_string(RandomDouble(-1000, 1000)))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 53 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    uint32_t    byte0{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte1{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte2{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    byte3{static_cast<uint32_t>(RandomDouble(0, 255))};
                    uint32_t    inValue{(((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3};
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::AddressValue>(nullptr, inValue)};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
                    }
                }
                break;

            case 54 :
                aValue = std::make_shared<InitFile::ObjectValue>(nullptr);;
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()));
                if (okSoFar)
                {
                    std::string tagForAdd1{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd1{std::make_shared<InitFile::DoubleValue>(nullptr, RandomDouble(-1000, 1000))};
                    std::string tagForAdd2{std::to_string(RandomDouble(-1000, 1000))};
                    auto        valueToAdd2{std::make_shared<InitFile::NullValue>(nullptr)};

                    okSoFar = false;
                    aValue->AddValue(tagForAdd1, valueToAdd1);
                    aValue->AddValue(tagForAdd2, valueToAdd2);
                    if (2 == aValue->HowManyValues())
                    {
                        UpBaseValue  clonedValue{aValue->Clone()};

                        okSoFar = ((nullptr != clonedValue) && (*clonedValue == *aValue));
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
    int         result{1};

    ODL_INIT(progName.c_str(), kODLoggingOptionIncludeProcessID | //####
             kODLoggingOptionIncludeThreadID | kODLoggingOptionEnableThreadSupport | //####
             kODLoggingOptionWriteToStderr); //####
    ODL_ENTER(); //####
    try
    {
        Initialize(progName);
        if (2 < --argc)
        {
            int64_t selector;
            int64_t subSelector;
            bool    expected{('t' == *argv[2]) || ('T' == *argv[2])};

            ODL_B1(expected); //####
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
                    ODL_I1(result); //####
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
