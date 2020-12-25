//--------------------------------------------------------------------------------------------------
//
//  File:       Tests/ifValuesTest.cpp
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
//  Created:    2020-09-22
//
//--------------------------------------------------------------------------------------------------

#include "ifTestSupport.h"

#include <ifAddress.h>
#include <ifArray.h>
#include <ifBoolean.h>
#include <ifDouble.h>
#include <ifInteger.h>
#include <ifNull.h>
#include <ifObject.h>
#include <ifString.h>

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
    std::string message("Exiting due to signal ");

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
doTestNullValue
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
        SpNull  aValue;
        bool    okSoFar;

        // 1) test that NULL values are distinct.
        // 2) test that a NULL value can be created.
        // 3) test that a NULL value is described correctly.
        // 4) test that a NULL value can be cloned.
        // 5) test that a NULL value is considered equal to itself.
        // 6) test that a NULL value and another NULL value are considered equal.
        // 7) test that a NULL value and another value type are not considered equal.
        // 8) test that a NULL value and its clone are considered equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull() && (! aValue->AsAddress()) && (! aValue->AsArray()) &&
                        (! aValue->AsBoolean()) && (! aValue->AsDouble()) && (! aValue->AsInteger()) &&
                        (! aValue->AsObject()) && (! aValue->AsString()));
                break;

            case 2 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull());
                break;

            case 3 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull());
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("null" == buffer.str());
                }
                break;

            case 4 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsNull());
                }
                break;

            case 5 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull() && (*aValue == *aValue));
                break;

            case 6 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull());
                if (okSoFar)
                {
                    SpNull  otherValue(new InitFile::NullValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 7 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull());
                if (okSoFar)
                {
                    SpArray otherValue(new InitFile::ArrayValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue.reset(new InitFile::NullValue(nullptr));
                okSoFar = (aValue && aValue->AsNull());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsNull() && (*aValue == *otherValue));
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
} // doTestNullValue

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
doTestBooleanValue
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
        SpBoolean   aValue;
        bool        okSoFar;

        // 1) test that boolean values are distinct.
        // 2) test that a 'false' value can be created with the correct value.
        // 3) test that a 'true' value can be created with the correct value.
        // 4) test that a 'false' value is described correctly.
        // 5) test that a 'true' value is described correctly.
        // 6) test that a boolean value can be cloned.
        // 7) test that a boolean value is considered equal to itself.
        // 7) test that a boolean value and another boolean value are considered equal.
        // 9) test that a boolean value and another value type are not considered equal.
        // 10) test that a boolean value and its clone are considered equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::BooleanValue(nullptr, false));
                okSoFar = (aValue && aValue->AsBoolean() && (! aValue->AsAddress()) && (! aValue->AsArray()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) &&
                            (! aValue->AsObject()) && (! aValue->AsString()));
                break;

            case 2 :
                aValue.reset(new InitFile::BooleanValue(nullptr, false));
                okSoFar = (aValue && aValue->AsBoolean() && (! aValue->GetValue()));
                break;

            case 3 :
                aValue.reset(new InitFile::BooleanValue(nullptr, true));
                okSoFar = (aValue && aValue->AsBoolean() && aValue->GetValue());
                break;

            case 4 :
                aValue.reset(new InitFile::BooleanValue(nullptr, false));
                okSoFar = (aValue && aValue->AsBoolean());
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("false" == buffer.str());
                }
                break;

            case 5 :
                aValue.reset(new InitFile::BooleanValue(nullptr, true));
                okSoFar = (aValue && aValue->AsBoolean());
                if (okSoFar)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    okSoFar = ("true" == buffer.str());
                }
                break;

            case 6 :
                aValue.reset(new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble()));
                okSoFar = (aValue && aValue->AsBoolean());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsBoolean() &&
                                (aValue->GetValue() == otherValue->AsBoolean()->GetValue()));
                }
                break;

            case 7 :
                aValue.reset(new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble()));
                okSoFar = (aValue && aValue->AsBoolean() && (*aValue == *aValue));
                break;

            case 8 :
                aValue.reset(new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble()));
                okSoFar = (aValue && aValue->AsBoolean());
                if (okSoFar)
                {
                    SpBase  otherValue(new InitFile::BooleanValue(nullptr, aValue->GetValue()));

                    okSoFar = (otherValue && otherValue->AsBoolean() && (*aValue == *otherValue));
                }
                break;

            case 9 :
                aValue.reset(new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble()));
                okSoFar = (aValue && aValue->AsBoolean());
                if (okSoFar)
                {
                    SpArray otherValue(new InitFile::ArrayValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 10 :
                aValue.reset(new InitFile::BooleanValue(nullptr, 0.5 <= RandomDouble()));
                okSoFar = (aValue && aValue->AsBoolean());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsBoolean() && (*aValue == *otherValue));
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
} // doTestBooleanValue

#if defined(__APPLE__)
# pragma mark *** Test Case 03 ***
#endif // defined(__APPLE__)

/*! @brief Perform a test case.
 @param[in] launchPath The command-line name used to launch the service.
 @param[in] subSelector The subtest to perform.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used for the test.
 @return @c 0 on success and @c 1 on failure. */
static int
doTestIntegerValue
    (const char *   NOT_USED_(launchPath),
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result = 1;

    try
    {
        SpInteger   aValue;
        bool        okSoFar;

        // 1) test that integer values are distinct.
        // 2) test that an integer value can be created with the correct value.
        // 3) test that an integer value is described correctly.
        // 4) test that an integer value can be cloned.
        // 5) test that an integer value is considered equal to itself.
        // 6) test that an integer value and another integer value are considered equal.
        // 7) test that an integer value and another value type are not considered equal.
        // 8) test that an integer value and its clone are considered equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::IntegerValue(nullptr, 42));
                okSoFar = (aValue && aValue->AsInteger() && (! aValue->AsAddress()) && (! aValue->AsArray()) &&
                            (! aValue->AsBoolean()) && (! aValue->AsDouble()) && (! aValue->AsNull()) &&
                            (! aValue->AsObject()) && (! aValue->AsString()));
                break;

            case 2 :
                if (1 <= argc)
                {
                    const int64_t   inValue = strtol(*argv, nullptr, 10);

                    aValue.reset(new InitFile::IntegerValue(nullptr, inValue));
                    okSoFar = (aValue && aValue->AsInteger());
                    if (okSoFar)
                    {
                        int64_t fetched = aValue->GetValue();

                        okSoFar = (inValue == fetched);
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 3 :
                if (1 <= argc)
                {
                    const int64_t   inValue = strtol(*argv, nullptr, 10);

                    aValue.reset(new InitFile::IntegerValue(nullptr, inValue));
                    okSoFar = (aValue && aValue->AsInteger());
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;

                        aValue->Print(buffer);
                        okSoFar = (*argv == buffer.str());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 4 :
                aValue.reset(new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsInteger());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsInteger() && (aValue->GetValue() == otherValue->AsInteger()->GetValue()));
                }
                break;

            case 5 :
                aValue.reset(new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsInteger() && (*aValue == *aValue));
                break;

            case 6 :
                aValue.reset(new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsInteger());
                if (okSoFar)
                {
                    SpBase  otherValue(new InitFile::IntegerValue(nullptr, aValue->GetValue()));

                    okSoFar = (otherValue && otherValue->AsInteger() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue.reset(new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsInteger());
                if (okSoFar)
                {
                    SpArray otherValue(new InitFile::ArrayValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue.reset(new InitFile::IntegerValue(nullptr, static_cast<int64_t>(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsInteger());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsInteger() && (*aValue == *otherValue));
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
} // doTestIntegerValue

#if defined(__APPLE__)
# pragma mark *** Test Case 04 ***
#endif // defined(__APPLE__)

/*! @brief Perform a test case.
 @param[in] launchPath The command-line name used to launch the service.
 @param[in] subSelector The subtest to perform.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used for the test.
 @return @c 0 on success and @c 1 on failure. */
static int
doTestDoubleValue
    (const char *   NOT_USED_(launchPath),
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result = 1;

    try
    {
        SpDouble        aValue;
        bool            okSoFar;

        // 1) test that double values are distinct.
        // 2) test that a double value can be created with the correct value.
        // 3) test that a double value is described correctly.
        // 4) test that a double value can be cloned.
        // 5) test that a double value is considered equal to itself.
        // 6) test that a double value and another double value are considered equal.
        // 7) test that a double value and another value type are not considered equal.
        // 8) test that a double value and its clone are considered equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::DoubleValue(nullptr, 42));
                okSoFar = (aValue && aValue->AsDouble() && (! aValue->AsAddress()) && (! aValue->AsArray()) &&
                            (! aValue->AsBoolean()) && (! aValue->AsInteger()) && (! aValue->AsNull()) &&
                            (! aValue->AsObject()) && (! aValue->AsString()));
                break;

            case 2 :
                if (1 <= argc)
                {
                    const double    dblValue = strtod(*argv, nullptr);

                    aValue.reset(new InitFile::DoubleValue(nullptr, dblValue));
                    okSoFar = (aValue && aValue->AsDouble());
                    if (okSoFar)
                    {
                        double  fetched = aValue->GetValue();

                        okSoFar = (dblValue == fetched);
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 3 :
                if (2 <= argc)
                {
                    const double    dblValue = strtod(*argv, nullptr);

                    aValue.reset(new InitFile::DoubleValue(nullptr, dblValue));
                    okSoFar = (aValue && aValue->AsDouble());
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;

                        aValue->Print(buffer);
                        okSoFar = (argv[1] == buffer.str());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 4 :
                aValue.reset(new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000)));
                okSoFar = (aValue && aValue->AsDouble());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsDouble() && (aValue->GetValue() == otherValue->AsDouble()->GetValue()));
                }
                break;

            case 5 :
                aValue.reset(new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000)));
                okSoFar = (aValue && aValue->AsDouble() && (*aValue == *aValue));
                break;

            case 6 :
                aValue.reset(new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000)));
                okSoFar = (aValue && aValue->AsDouble());
                if (okSoFar)
                {
                    SpBase  otherValue(new InitFile::DoubleValue(nullptr, aValue->GetValue()));

                    okSoFar = (otherValue && otherValue->AsDouble() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue.reset(new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000)));
                okSoFar = (aValue && aValue->AsDouble());
                if (okSoFar)
                {
                    SpArray otherValue(new InitFile::ArrayValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue.reset(new InitFile::DoubleValue(nullptr, RandomDouble(-1000, 1000)));
                okSoFar = (aValue && aValue->AsDouble());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsDouble() && (*aValue == *otherValue));
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
} // doTestDoubleValue

#if defined(__APPLE__)
# pragma mark *** Test Case 05 ***
#endif // defined(__APPLE__)

/*! @brief Perform a test case.
 @param[in] launchPath The command-line name used to launch the service.
 @param[in] subSelector The subtest to perform.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used for the test.
 @return @c 0 on success and @c 1 on failure. */
static int
doTestStringValue
    (const char *   NOT_USED_(launchPath),
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result = 1;

    try
    {
        SpString    aValue;
        bool        okSoFar;

        // 1) test that string values are distinct.
        // 2) test that a string value can be created with the correct value.
        // 3) test that a string value is described correctly.
        // 4) test that a string value can be cloned.
        // 5) test that a string value is considered equal to itself.
        // 6) test that a string value and another string value are considered equal.
        // 7) test that a string value and another value type are not considered equal.
        // 8) test that a string value and its clone are considered equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::StringValue(nullptr, "chuckles"));
                okSoFar = (aValue && aValue->AsString() && (! aValue->AsAddress()) && (! aValue->AsArray()) &&
                            (! aValue->AsBoolean()) && (! aValue->AsDouble()) && (! aValue->AsInteger()) &&
                            (! aValue->AsNull()) && (! aValue->AsObject()));
                break;

            case 2 :
                if (1 <= argc)
                {
                    aValue.reset(new InitFile::StringValue(nullptr, *argv));
                    okSoFar = (aValue && aValue->AsString());
                    if (okSoFar)
                    {
                        std::string fetched = aValue->GetValue();

                        okSoFar = (*argv == fetched);
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 3 :
                if (2 <= argc)
                {
                    aValue.reset(new InitFile::StringValue(nullptr, *argv));
                    okSoFar = (aValue && aValue->AsString());
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;

                        aValue->Print(buffer);
                        okSoFar = (argv[1] == buffer.str());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 4 :
                aValue.reset(new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsString());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsString() && (aValue->GetValue() == otherValue->AsString()->GetValue()));
                }
                break;

            case 5 :
                aValue.reset(new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsString() && (*aValue == *aValue));
                break;

            case 6 :
                aValue.reset(new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsString());
                if (okSoFar)
                {
                    SpBase  otherValue(new InitFile::StringValue(nullptr, aValue->GetValue()));

                    okSoFar = (otherValue && otherValue->AsString() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                aValue.reset(new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsString());
                if (okSoFar)
                {
                    SpArray otherValue(new InitFile::ArrayValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                aValue.reset(new InitFile::StringValue(nullptr, std::to_string(RandomDouble(-1000, 1000))));
                okSoFar = (aValue && aValue->AsString());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsString() && (*aValue == *otherValue));
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
} // doTestStringValue

#if defined(__APPLE__)
# pragma mark *** Test Case 06 ***
#endif // defined(__APPLE__)

/*! @brief Perform a test case.
 @param[in] launchPath The command-line name used to launch the service.
 @param[in] subSelector The subtest to perform.
 @param[in] argc The number of arguments in 'argv'.
 @param[in] argv The arguments to be used for the test.
 @return @c 0 on success and @c 1 on failure. */
static int
doTestAddressValue
    (const char *   NOT_USED_(launchPath),
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result = 1;

    try
    {
        SpAddress   aValue;
        bool        okSoFar;
        uint32_t    byte0;
        uint32_t    byte1;
        uint32_t    byte2;
        uint32_t    byte3;
        uint32_t    inValue;

        // 1) test that address values are distinct.
        // 2) test that an address value can be created with the correct value.
        // 3) test that an address value is described correctly.
        // 4) test that an address value can be cloned.
        // 5) test that an address value is considered equal to itself.
        // 6) test that an address value and another address value are considered equal.
        // 7) test that an address value and another value type are not considered equal.
        // 8) test that an address value and its clonse are considered equal.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::AddressValue(nullptr, 1234567));
                okSoFar = (aValue && aValue->AsAddress() && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) &&
                            (! aValue->AsObject()) && (! aValue->AsString()));
                break;

            case 2 :
                if (4 <= argc)
                {
                    byte0 = strtol(*argv, nullptr, 10);
                    byte1 = strtol(argv[1], nullptr, 10);
                    byte2 = strtol(argv[2], nullptr, 10);
                    byte3 = strtol(argv[3], nullptr, 10);
                    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                    okSoFar = (aValue && aValue->AsAddress());
                    if (okSoFar)
                    {
                        uint32_t    fetched = aValue->GetValue();

                        okSoFar = (inValue == fetched);
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 3 :
                if (5 <= argc)
                {
                    byte0 = strtol(*argv, nullptr, 10);
                    byte1 = strtol(argv[1], nullptr, 10);
                    byte2 = strtol(argv[2], nullptr, 10);
                    byte3 = strtol(argv[3], nullptr, 10);
                    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                    aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                    okSoFar = (aValue && aValue->AsAddress());
                    if (okSoFar)
                    {
                        std::ostringstream  buffer;

                        aValue->Print(buffer);
                        okSoFar = (argv[4] == buffer.str());
                    }
                }
                else
                {
                    ODL_LOG("! (5 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 4 :
                byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                okSoFar = (aValue && aValue->AsAddress());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsAddress() && (aValue->GetValue() == otherValue->AsAddress()->GetValue()));
                }
                break;

            case 5 :
                byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                okSoFar = (aValue && aValue->AsAddress() && (*aValue == *aValue));
                break;

            case 6 :
                byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                okSoFar = (aValue && aValue->AsAddress());
                if (okSoFar)
                {
                    SpBase  otherValue(new InitFile::AddressValue(nullptr, aValue->GetValue()));

                    okSoFar = (otherValue && otherValue->AsAddress() && (*aValue == *otherValue));
                }
                break;

            case 7 :
                byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                okSoFar = (aValue && aValue->AsAddress());
                if (okSoFar)
                {
                    SpArray otherValue(new InitFile::ArrayValue(nullptr));

                    okSoFar = (*aValue == *otherValue);
                }
                break;

            case 8 :
                byte0 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte1 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte2 = static_cast<uint32_t>(RandomDouble(0, 255));
                byte3 = static_cast<uint32_t>(RandomDouble(0, 255));
                inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;
                aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                okSoFar = (aValue && aValue->AsAddress());
                if (okSoFar)
                {
                    SpBase  otherValue(aValue->Clone());

                    okSoFar = (otherValue && otherValue->AsAddress() && (*aValue == *otherValue));
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
} // doTestAddressValue

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
    std::string progName(*argv);

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
                        // NULL value
                        result = doTestNullValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 2 :
                        // Boolean value
                        result = doTestBooleanValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 3 :
                        // Integer value
                        result = doTestIntegerValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 4 :
                        // Double value
                        result = doTestDoubleValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 5 :
                        // String value
                        result = doTestStringValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 6 :
                        // Address value
                        result = doTestAddressValue(*argv, subSelector, expected, argc - 3, argv + 4);
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
