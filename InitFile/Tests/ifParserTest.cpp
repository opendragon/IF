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
#include <ifValueListener.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <unistd.h>

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

/*! @brief Return a temporary file name.
 @return A temporary file name.
*/
static std::string
getTempFileName
    (void)
{
#define ROOT_NAME_  "/tmp/IF_PARSER_.XXXXX"
    static char newName[] = ROOT_NAME_;

    return std::string(mktemp(newName));
} // getTempFileName

/*! @brief Construct a string and parse it.
 @param[in,out] listener The listener used to handle the parse operation.
 @param[in] stringToAdd The string of interest.
 @param[in] tagToUse The tag to be used if constructing an Object string.
 @return The result of the parse operation. */
static InitFile::SpBase
addToStringAndParse
    (InitFile::BaseValueListener *  listener,
     const std::string &            stringToAdd,
     const std::string &            tagToUse = "")
{
    std::string stringToBuild;

    if (0 < tagToUse.length())
    {
        // This is for an Object value.
        stringToBuild = "{ " + MakeWrappedString(tagToUse) + " : " + stringToAdd + " }";
    }
    else
    {
        // This is for an Array value.
        stringToBuild = "[ " + stringToAdd + " ]";
    }
    return listener->GetValue(stringToBuild);
} // addToStringAndParse

/*! @brief Write to afile and parse it.
 @param[in,out] listener The listener used to handle the parse operation.
 @param[in,out] inOutFile The file to be used for the parsing.
 @param[in] fileName The name of the file being used.
 @param[in] stringToWrite The string of interest.
 @param[in] tagToUse The tag to be used if writing an Object.
 @return The result of the parse operation. */
static InitFile::SpBase
writeToFileAndParse
    (InitFile::BaseValueListener *  listener,
     std::fstream &                 inOutFile,
     const std::string &            fileName,
     const std::string &            stringToWrite,
     const std::string &            tagToUse = "")
{
    if (0 < tagToUse.length())
    {
        // This is for an Object value.
        inOutFile << "{ " << MakeWrappedString(tagToUse) << " : " << stringToWrite << " }";
    }
    else
    {
        // This is for an Array value.
        inOutFile << "[ " << stringToWrite << " ]";
    }
    inOutFile.close();
    inOutFile.open(fileName, std::ios::in);
    return listener->GetValue(inOutFile);
} // writeToFileAndParse

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
doTestStringInputArray
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
        std::unique_ptr<InitFile::BaseValueListener>    listener(new InitFile::BaseValueListener);
        SpBase                                          aValue;
        bool                                            okSoFar;

        // 1) test that an empty string fails.
        // 2) test that a string with a non-container fails.
        // 3) test that a string with an empty array is accepted.
        // 4) test that a string with an unterminated array fails.
        // 5) test that a string with an array with a single NULL value succeeds or fails.
        // 6) test that a string with an array with a single Boolean value succeeds or fails.
        // 7) test that a string with an array with a single integer value succeeds or fails.
        // 8) test that a string with an array with a single string value succeeds or fails.
        // 9) test that a string with an array with a single double value succeeds or fails.
        // 10) test that a string with an array with a single address value succeeds or fails.
        // 11) test that a string with an array with a single array value succeeds or fails.
        // 12) test that a string with an array with a single object value succeeds or fails.
        switch (subSelector)
        {
            case 1 :
                aValue = listener->GetValue("");
                okSoFar = (nullptr != aValue);
                break;

            case 2 :
                aValue = listener->GetValue("42");
                okSoFar = (nullptr != aValue);
                break;

            case 3 :
                aValue = listener->GetValue("[]");
                okSoFar = (aValue && aValue->AsArray() && (0 == aValue->AsArray()->HowManyValues()));
                break;

            case 4 :
                aValue = listener->GetValue("[");
                okSoFar = (nullptr != aValue);
                break;

            case 5 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsNull());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 6 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));
                        bool    expectedValue = ('t' == tolower(*argv[0]));

                        okSoFar = (fetchedValue && fetchedValue->AsBoolean() && (expectedValue == fetchedValue->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 7 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));
                        int64_t expectedValue;

                        okSoFar = (ConvertToInt64(*argv, expectedValue) && fetchedValue && fetchedValue->AsInteger() &&
                                    (expectedValue == fetchedValue->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 8 :
                if (1 <= argc)
                {
                    std::string     wrappedString(InitFile::MakeWrappedString(*argv));

                    aValue = addToStringAndParse(listener.get(), wrappedString);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsString() &&
                                    (*argv == fetchedValue->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 9 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));
                        double  expectedValue;

                        okSoFar = (ConvertToDouble(*argv, expectedValue) && fetchedValue && fetchedValue->AsDouble() &&
                                    (expectedValue == fetchedValue->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 10 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsAddress());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 11 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsArray());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 12 :
                if (1 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsObject());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
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
} // doTestStringInputArray

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
doTestFileInputArray
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
        std::unique_ptr<InitFile::BaseValueListener>    listener(new InitFile::BaseValueListener);
        SpBase                                          aValue;
        bool                                            okSoFar;
        std::string                                     fileName(getTempFileName());
        std::fstream                                    inputOutput;

        // 1) test that an empty file fails.
        // 2) test that file with a non-container fails.
        // 3) test that a file with an empty array is accepted.
        // 4) test that a file with an unterminated array fails.
        // 5) test that a file with an array with a single NULL value succeeds or fails.
        // 6) test that a file with an array with a single Boolean value succeeds or fails.
        // 7) test that a file with an array with a single integer value succeeds or fails.
        // 8) test that a file with an array with a single string value succeeds or fails.
        // 9) test that a file with an array with a single double value succeeds or fails.
        // 10) test that a file with an array with a single address value succeeds or fails.
        // 11) test that a file with an array with a single array value succeeds or fails.
        // 12) test that a file with an array with a single object value succeeds or fails.
        if (! inputOutput.is_open())
        {
            inputOutput.clear();
            inputOutput.open(fileName, std::ios::out);
        }
        switch (subSelector)
        {
            case 1 :
                inputOutput.close();
                inputOutput.open(fileName, std::ios::in);
                aValue = listener->GetValue(inputOutput);
                okSoFar = (nullptr != aValue);
                break;

            case 2 :
                inputOutput << "42";
                inputOutput.close();
                inputOutput.open(fileName, std::ios::in);
                aValue = listener->GetValue(inputOutput);
                okSoFar = (nullptr != aValue);
                break;

            case 3 :
                inputOutput << "[]";
                inputOutput.close();
                inputOutput.open(fileName, std::ios::in);
                aValue = listener->GetValue(inputOutput);
                okSoFar = (aValue && aValue->AsArray() && (0 == aValue->AsArray()->HowManyValues()));
                break;

            case 4 :
                inputOutput << "[";
                inputOutput.close();
                inputOutput.open(fileName, std::ios::in);
                aValue = listener->GetValue(inputOutput);
                okSoFar = (nullptr != aValue);
                break;

            case 5 :
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsNull());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 6 :
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));
                        bool    expectedValue = ('t' == tolower(*argv[0]));

                        okSoFar = (fetchedValue && fetchedValue->AsBoolean() && (expectedValue == fetchedValue->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 7 :
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));
                        int64_t expectedValue;

                        okSoFar = (ConvertToInt64(*argv, expectedValue) && fetchedValue && fetchedValue->AsInteger() &&
                                    (expectedValue == fetchedValue->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 8 :
                if (1 <= argc)
                {
                    std::string     wrappedString(InitFile::MakeWrappedString(*argv));

                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, wrappedString);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsString() &&
                                    (*argv == fetchedValue->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 9 :
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));
                        double  expectedValue;

                        okSoFar = (ConvertToDouble(*argv, expectedValue) && fetchedValue && fetchedValue->AsDouble() &&
                                    (expectedValue == fetchedValue->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 10:
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsAddress());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 11 :
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsArray());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 12 :
                if (1 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = (aValue && aValue->AsArray() && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsArray()->GetValue(0));

                        okSoFar = (fetchedValue && fetchedValue->AsObject());
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
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
} // doTestFileInputArray

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
doTestStringInputObject
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
        std::unique_ptr<InitFile::BaseValueListener>    listener(new InitFile::BaseValueListener);
        SpBase                                          aValue;
        bool                                            okSoFar;

        // 1) test that a string with an empty object is accepted.
        // 2) test that a string with an unterminated object fails.
        // 3) test that a string with an object with a single NULL value succeeds or fails.
        // 4) test that a string with an object with a single Boolean value succeeds or fails.
        // 5) test that a string with an object with a single integer value succeeds or fails.
        // 6) test that a string with an object with a single string value succeeds or fails.
        // 7) test that a string with an object with a single double value succeeds or fails.
        // 8) test that a string with an object with a single address value succeeds or fails.
        // 9) test that a string with an object with a single array value succeeds or fails.
        // 10) test that a string with an object with a single object value succeeds or fails.
        switch (subSelector)
        {
            case 1 :
                aValue = listener->GetValue("{}");
                okSoFar = (aValue && aValue->AsObject() && (0 == aValue->AsObject()->HowManyValues()));
                break;

            case 2 :
                aValue = listener->GetValue("{");
                okSoFar = (nullptr != aValue);
                break;

            case 3 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsNull());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 4 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));
                        bool    expectedValue = ('t' == tolower(*argv[1]));

                        okSoFar = (fetchedValue && fetchedValue->AsBoolean() && (expectedValue == fetchedValue->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 5 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));
                        int64_t expectedValue;

                        okSoFar = (ConvertToInt64(argv[1], expectedValue) && fetchedValue && fetchedValue->AsInteger() &&
                                    (expectedValue == fetchedValue->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 6 :
                if (2 <= argc)
                {
                    std::string     wrappedString(InitFile::MakeWrappedString(argv[1]));

                    aValue = addToStringAndParse(listener.get(), wrappedString, *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsString() && (argv[1] == fetchedValue->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 7 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));
                        double  expectedValue;

                        okSoFar = (ConvertToDouble(argv[1], expectedValue) && fetchedValue && fetchedValue->AsDouble() &&
                                    (expectedValue == fetchedValue->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 8 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsAddress());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 9 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsArray());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 10 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsObject());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
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
} // doTestStringInputObject

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
doTestFileInputObject
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
        std::unique_ptr<InitFile::BaseValueListener>    listener(new InitFile::BaseValueListener);
        SpBase                                          aValue;
        bool                                            okSoFar;
        std::string                                     fileName(getTempFileName());
        std::fstream                                    inputOutput;

        // 1) test that a file with an empty object is accepted.
        // 2) test that a file with an unterminated object fails.
        // 3) test that a file with an object with a single NULL value succeeds or fails.
        // 4) test that a file with an object with a single Boolean value succeeds or fails.
        // 5) test that a file with an object with a single integer value succeeds or fails.
        // 6) test that a file with an object with a single string value succeeds or fails.
        // 7) test that a file with an object with a single double value succeeds or fails.
        // 8) test that a file with an object with a single address value succeeds or fails.
        // 9) test that a file with an object with a single array value succeeds or fails.
        // 10) test that a file with an object with a single object value succeeds or fails.
        if (! inputOutput.is_open())
        {
            inputOutput.clear();
            inputOutput.open(fileName, std::ios::out);
        }
        switch (subSelector)
        {
            case 1 :
                inputOutput << "{}";
                inputOutput.close();
                inputOutput.open(fileName, std::ios::in);
                aValue = listener->GetValue(inputOutput);
                okSoFar = (aValue && aValue->AsObject() && (0 == aValue->AsObject()->HowManyValues()));
                break;

            case 2 :
                inputOutput << "{";
                inputOutput.close();
                inputOutput.open(fileName, std::ios::in);
                aValue = listener->GetValue(inputOutput);
                okSoFar = (nullptr != aValue);
                break;

            case 3 :
                if (2 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsNull());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 4 :
                if (2 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));
                        bool    expectedValue = ('t' == tolower(*argv[1]));

                        okSoFar = (fetchedValue && fetchedValue->AsBoolean() && (expectedValue == fetchedValue->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 5 :
                if (2 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));
                        int64_t expectedValue;

                        okSoFar = (ConvertToInt64(argv[1], expectedValue) && fetchedValue && fetchedValue->AsInteger() &&
                                    (expectedValue == fetchedValue->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 6 :
                if (2 <= argc)
                {
                    std::string     wrappedString(InitFile::MakeWrappedString(argv[1]));

                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, wrappedString, *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsString() && (argv[1] == fetchedValue->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 7 :
                if (2 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));
                        double  expectedValue;

                        okSoFar = (ConvertToDouble(argv[1], expectedValue) && fetchedValue && fetchedValue->AsDouble() &&
                                    (expectedValue == fetchedValue->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 8 :
                if (2 <= argc)
                {
                    aValue = writeToFileAndParse(listener.get(), inputOutput, fileName, argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsAddress());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 9 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsArray());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 10 :
                if (2 <= argc)
                {
                    aValue = addToStringAndParse(listener.get(), argv[1], *argv);
                    okSoFar = (aValue && aValue->AsObject() && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBase  fetchedValue(aValue->AsObject()->GetValue(*argv));

                        okSoFar = (fetchedValue && fetchedValue->AsObject());
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
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
} // doTestFileInputObject

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
                        // Array input from a string
                        result = doTestStringInputArray(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 2 :
                        // Array input from a file
                        result = doTestFileInputArray(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 3 :
                        // Object input from a string
                        result = doTestStringInputObject(*argv, subSelector, expected, argc - 3, argv + 4);
                        break;

                    case 4 :
                        // Object input from a file
                        result = doTestFileInputObject(*argv, subSelector, expected, argc - 3, argv + 4);
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
