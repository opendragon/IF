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
        bool    typeOK;

        // 1) test that a NULL value can be created.
        // 2) test that a NULL value is described correctly.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::NullValue(nullptr));
                typeOK = (aValue && aValue->AsNull() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK)
                {
                    result = (expected ? 0 : 1);
                }
                break;

            case 2 :
                aValue.reset(new InitFile::NullValue(nullptr));
                typeOK = (aValue && aValue->AsNull() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    if ("null" == buffer.str())
                    {
                        result = (expected ? 0 : 1);
                    }
                }
                break;

            default :
                break;

        }
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
        bool        typeOK;

        // 1) test that a 'false' value can be created with the correct value.
        // 2) test that a 'true' value can be created with the correct value.
        // 3) test that a 'false' value is described correctly.
        // 4) test that a 'true' value is described correctly.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::BooleanValue(nullptr, false));
                typeOK = (aValue && aValue->AsBoolean() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsDouble()) &&
                            (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK && (! aValue->GetValue()))
                {
                    result = (expected ? 0 : 1);
                }
                break;

            case 2 :
                aValue.reset(new InitFile::BooleanValue(nullptr, true));
                typeOK = (aValue && aValue->AsBoolean() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsDouble()) &&
                            (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK && aValue->GetValue())
                {
                    result = (expected ? 0 : 1);
                }
                break;

            case 3 :
                aValue.reset(new InitFile::BooleanValue(nullptr, false));
                typeOK = (aValue && aValue->AsBoolean() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsDouble()) &&
                            (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    if ("false" == buffer.str())
                    {
                        result = (expected ? 0 : 1);
                    }
                }
                break;

            case 4 :
                aValue.reset(new InitFile::BooleanValue(nullptr, true));
                typeOK = (aValue && aValue->AsBoolean() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsDouble()) &&
                            (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    if ("true" == buffer.str())
                    {
                        result = (expected ? 0 : 1);
                    }
                }
                break;

            default :
                break;

        }
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
        if (1 <= argc)
        {
            const int64_t   inValue = strtol(*argv, NULL, 10);
            SpInteger       aValue;
            bool            typeOK;

            // 1) test that an integer value can be created with the correct value.
            // 2) test that an integer value is described correctly.
            switch (subSelector)
            {
                case 1 :
                    aValue.reset(new InitFile::IntegerValue(nullptr, inValue));
                    typeOK = (aValue && aValue->AsInteger() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                                (! aValue->AsDouble()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                    if (typeOK)
                    {
                        int64_t fetched = aValue->GetValue();
                        
                        result = ((expected == (inValue == fetched)) ? 0 : 1);
                    }
                    break;

                case 2 :
                    aValue.reset(new InitFile::IntegerValue(nullptr, inValue));
                    typeOK = (aValue && aValue->AsInteger() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                                (! aValue->AsDouble()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                    if (typeOK)
                    {
                        std::ostringstream  buffer;

                        aValue->Print(buffer);
                        if (*argv == buffer.str())
                        {
                            result = (expected ? 0 : 1);
                        }
                    }
                    break;

                default :
                    break;

            }
        }
        else
        {
            ODL_LOG("! (1 < argc)"); //####            
        }
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
        if (1 <= argc)
        {
            const double    dblValue = strtod(*argv, NULL);
            SpDouble        aValue;
            bool            typeOK;

            // 1) test that a double value can be created with the correct value.
            // 2) test that a double value is described correctly.
            switch (subSelector)
            {
                case 1 :
                    aValue.reset(new InitFile::DoubleValue(nullptr, dblValue));
                    typeOK = (aValue && aValue->AsDouble() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                                (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                    if (typeOK)
                    {
                        double  fetched = aValue->GetValue();
                        
                        result = ((expected == (dblValue == fetched)) ? 0 : 1);
                    }
                    break;

                case 2 :
                    if (2 <= argc)
                    {
                        aValue.reset(new InitFile::DoubleValue(nullptr, dblValue));
                        typeOK = (aValue && aValue->AsDouble() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                                    (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                        if (typeOK)
                        {
                            std::ostringstream  buffer;

                            aValue->Print(buffer);
                            if (argv[1] == buffer.str())
                            {
                                result = (expected ? 0 : 1);
                            }
                        }
                    }
                    break;

                default :
                    break;

            }
        }
        else
        {
            ODL_LOG("! (1 < argc)"); //####            
        }
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
        if (1 <= argc)
        {
            SpString    aValue;
            bool        typeOK;

            // 1) test that a string value can be created with the correct value.
            // 2) test that a string value is described correctly.
            switch (subSelector)
            {
                case 1 :
                    aValue.reset(new InitFile::StringValue(nullptr, *argv));
                    typeOK = (aValue && aValue->AsString() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                                (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()));
                    if (typeOK)
                    {
                        std::string fetched = aValue->GetValue();

                        result = ((expected == (*argv == fetched)) ? 0 : 1);
                    }
                    break;

                case 2 :
                    if (2 <= argc)
                    {
                        aValue.reset(new InitFile::StringValue(nullptr, *argv));
                        typeOK = (aValue && aValue->AsString() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                                    (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()));
                        if (typeOK)
                        {
                            std::ostringstream  buffer;

                            aValue->Print(buffer);
                            if (argv[1] == buffer.str())
                            {
                                result = (expected ? 0 : 1);
                            }
                        }
                    }
                    break;

                default :
                    break;

            }
        }
        else
        {
            ODL_LOG("! (1 < argc)"); //####            
        }
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
        if (4 <= argc)
        {
            SpAddress   aValue;
            bool        typeOK;
            uint32_t    byte0 = strtol(*argv, NULL, 10);
            uint32_t    byte1 = strtol(argv[1], NULL, 10);
            uint32_t    byte2 = strtol(argv[2], NULL, 10);
            uint32_t    byte3 = strtol(argv[3], NULL, 10);
            uint32_t    inValue = (((((byte0 << 8) + byte1) << 8) + byte2) << 8) + byte3;

            // 1) test that an address value can be created with the correct value.
            // 2) test that an address value is described correctly.
            switch (subSelector)
            {
                case 1 :
                    aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                    typeOK = (aValue && aValue->AsAddress() && (! aValue->AsArray()) && (! aValue->AsBoolean()) && (! aValue->AsDouble()) &&
                                (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                    if (typeOK)
                    {
                        uint32_t    fetched = aValue->GetValue();

                        result = ((expected == (inValue == fetched)) ? 0 : 1);
                    }
                    break;

                case 2 :
                    if (5 <= argc)
                    {
                        aValue.reset(new InitFile::AddressValue(nullptr, inValue));
                        typeOK = (aValue && aValue->AsAddress() && (! aValue->AsArray()) && (! aValue->AsBoolean()) && (! aValue->AsDouble()) &&
                                    (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                        if (typeOK)
                        {
                            std::ostringstream  buffer;

                            aValue->Print(buffer);
                            if (argv[4] == buffer.str())
                            {
                                result = (expected ? 0 : 1);
                            }
                        }
                    }
                    break;

                default :
                    break;

            }
        }
        else
        {
            ODL_LOG("! (1 < argc)"); //####            
        }
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
# pragma mark *** Test Case 07 ***
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
        bool    typeOK;

        // 1) test that an empty array value can be created.
        // 2) test that an empty array value is described correctly.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                typeOK = (aValue && aValue->AsArray() && (! aValue->AsAddress()) && (! aValue->AsBoolean()) && (! aValue->AsDouble()) &&
                            (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK && (0 == aValue->HowManyValues()))
                {
                    result = (expected ? 0 : 1);
                }
                break;

            case 2 :
                aValue.reset(new InitFile::ArrayValue(nullptr));
                typeOK = (aValue && aValue->AsArray() && (! aValue->AsAddress()) && (! aValue->AsBoolean()) && (! aValue->AsDouble()) &&
                            (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsObject()) && (! aValue->AsString()));
                if (typeOK)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    if ("[ ]" == buffer.str())
                    {
                        result = (expected ? 0 : 1);
                    }
                }
                break;

            default :
                break;

        }
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
# pragma mark *** Test Case 08 ***
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
        bool        typeOK;

        // 1) test that an empty object value can be created.
        // 2) test that an empty object value is described correctly.
        switch (subSelector)
        {
            case 1 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                typeOK = (aValue && aValue->AsObject() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsString()));
                if (typeOK && (0 == aValue->HowManyValues()))
                {
                    result = (expected ? 0 : 1);
                }
                break;

            case 2 :
                aValue.reset(new InitFile::ObjectValue(nullptr));
                typeOK = (aValue && aValue->AsObject() && (! aValue->AsAddress()) && (! aValue->AsArray()) && (! aValue->AsBoolean()) &&
                            (! aValue->AsDouble()) && (! aValue->AsInteger()) && (! aValue->AsNull()) && (! aValue->AsString()));
                if (typeOK)
                {
                    std::ostringstream  buffer;

                    aValue->Print(buffer);
                    if ("{ }" == buffer.str())
                    {
                        result = (expected ? 0 : 1);
                    }
                }
                break;

            default :
                break;

        }
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

                    case 7 :
                        // Array value
                        result = doTestArrayValue(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 8 :
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
