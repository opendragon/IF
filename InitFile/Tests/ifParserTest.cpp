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

#include <initFileAddress.h>
#include <initFileArray.h>
#include <initFileBoolean.h>
#include <initFileDouble.h>
#include <initFileInteger.h>
#include <initFileNull.h>
#include <initFileObject.h>
#include <initFileString.h>
#include <initFileValueListener.h>

//#include <odlEnable.h>
#include <odlInclude.h>

#include <iomanip>
#include <iostream>
#include <random>
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
    ODL_EXIT_EXIT(1); //####
    exit(1);
} // catchSignal

/*! @brief Return a temporary file name.
Note that mktemp() is considered dangerous and mkstemp() only returns a file descriptor, but there is no portable
way to connect a file descriptor to a standard file stream.
 @return A temporary file name.
*/
static std::string
getTempFileName
    (void)
{
    std::stringstream   aStream;
    std::string         newName;

    aStream << "/tmp/IF_PARSER_." << std::hex << InitFile::RandomUnsigned() << std::dec << std::ends;
    aStream >> newName;
    return newName;
} // getTempFileName

/*! @brief Construct a string for an Array and parse it.
 @param[in,out] listener The listener used to handle the parse operation.
 @param[in] stringToAdd1 The first string of interest.
 @param[in] stringToAdd2 The second string of interest.
 @return The result of the parse operation. */
static InitFile::SpBaseValue
addArrayToStringAndParse
    (InitFile::BaseValueListener *  listener,
     const std::string &            stringToAdd1,
     const std::string &            stringToAdd2 = "")
{
    std::string stringToBuild{"[ " + stringToAdd1};

    if (0 < stringToAdd2.length())
    {
        stringToBuild += ", " + stringToAdd2;
    }
    stringToBuild += " ]";
    return listener->GetValue(stringToBuild);
} // addArrayToStringAndParse

/*! @brief Construct a string for an Object and parse it.
 @param[in,out] listener The listener used to handle the parse operation.
 @param[in] tagToUse1 The first tag to be used.
 @param[in] stringToAdd1 The first string of interest.
 @param[in] tagToUse2 The second tag to be used.
 @param[in] stringToAdd2 The second string of interest.
 @return The result of the parse operation. */
static InitFile::SpBaseValue
addObjectToStringAndParse
    (InitFile::BaseValueListener *  listener,
     const std::string &            tagToUse1,
     const std::string &            stringToAdd1,
     const std::string &            tagToUse2 = "",
     const std::string &            stringToAdd2 = "")
{
    std::string stringToBuild{"{ " + MakeWrappedString(tagToUse1) + " : " + stringToAdd1};

    if ((0 < tagToUse2.length()) && (0 < stringToAdd2.length()))
    {
        stringToBuild += ", " + MakeWrappedString(tagToUse2) + " : " + stringToAdd2;
    }
    stringToBuild += " }";
    return listener->GetValue(stringToBuild);
} // addObjectToStringAndParse

/*! @brief Write an Array to a file and parse it.
 @param[in,out] listener The listener used to handle the parse operation.
 @param[in,out] inOutFile The file to be used for the parsing.
 @param[in] fileName The name of the file being used.
 @param[in] stringToWrite1 The first string of interest.
 @param[in] stringToWrite2 The second string of interest.
 @return The result of the parse operation. */
static InitFile::SpBaseValue
writeArrayToFileAndParse
    (InitFile::BaseValueListener *  listener,
     std::fstream &                 inOutFile,
     const std::string &            fileName,
     const std::string &            stringToWrite1,
     const std::string &            stringToWrite2 = "")
{
    inOutFile << "[ " << stringToWrite1;
    if (0 < stringToWrite2.length())
    {
        inOutFile << ", " << stringToWrite2;
    }
    inOutFile << " ]";
    inOutFile.close();
    inOutFile.open(fileName, std::ios::in);
    return listener->GetValue(inOutFile);
} // writeArrayToFileAndParse

/*! @brief Write an Object to a file and parse it.
 @param[in,out] listener The listener used to handle the parse operation.
 @param[in,out] inOutFile The file to be used for the parsing.
 @param[in] fileName The name of the file being used.
 @param[in] tagToUse1 The first tag to be used.
 @param[in] stringToWrite1 The string of interest.
 @param[in] tagToUse2 The second tag to be used.
 @param[in] stringToWrite2 The string of interest.
 @return The result of the parse operation. */
static InitFile::SpBaseValue
writeObjectToFileAndParse
    (InitFile::BaseValueListener *  listener,
     std::fstream &                 inOutFile,
     const std::string &            fileName,
     const std::string &            tagToUse1,
     const std::string &            stringToWrite1,
     const std::string &            tagToUse2 = "",
     const std::string &            stringToWrite2 = "")
{
    inOutFile << "{ " << MakeWrappedString(tagToUse1) << " : " << stringToWrite1;
    if ((0 < tagToUse2.length()) && (0 < stringToWrite2.length()))
    {
        inOutFile << ", " << MakeWrappedString(tagToUse2) << " : " << stringToWrite2;
    }
    inOutFile << " }";
    inOutFile.close();
    inOutFile.open(fileName, std::ios::in);
    return listener->GetValue(inOutFile);
} // writeObjectToFileAndParse

/*! @brief Convert a dot-separated string of integers into an IPv4 address.
 @param[in] inString The string to be processed, which may have a leading '@' character.
 @return The IPv4 address represented by the string. */
static uint32_t
convertStringToIp4Value
    (const std::string &    inString)
{
    uint32_t    result{0};
    size_t      lastPos{static_cast<size_t>(('@' == inString[0]) ? 1 : 0)};

    for (size_t ii = 0; ii < 4; ++ii)
    {
        size_t      jj{inString.find_first_of('.', lastPos)};
        std::string segment;

        result <<= 8;
        if (std::string::npos == jj)
        {
            segment = inString.substr(lastPos, inString.length());
        }
        else if (ii < 3)
        {
            segment = inString.substr(lastPos, jj - lastPos);
            lastPos = jj + 1;
        }
        else
        {
            // Extra dot after a valid IPv4 address, which makes it invalid.
            result = static_cast<uint32_t>(-1);
            break;

        }
        size_t  nextPos;
        size_t  segmentValue{std::stoul(segment, &nextPos)};

        // Check if the segment has no invalid characters and is not too large.
        if ((255 < segmentValue) || (nextPos < segment.length()))
        {
            result = static_cast<uint32_t>(-1);
            break;

        }
        result += segmentValue;
    }
    return result;
} // convertStringToIp4Value

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
    (const char *   launchPath,
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    INITFILE_UNUSED_VAR_(launchPath);
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result{1};

    try
    {
        std::unique_ptr<InitFile::BaseValueListener>    listener{new InitFile::BaseValueListener};
        SpBaseValue                                     aValue;
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
        // 13) test that a string with an array with a pair of NULLs is accepted.
        // 14) test that a string with an array with a pair of Boolean values is accepted.
        // 15) test that a string with an array with a pair of Integer values is accepted.
        // 16) test that a string with an array with a pair of String values is accepted.
        // 17) test that a string with an array with a pair of Double values is accepted.
        // 18) test that a string with an array with a pair of Address values is accepted.
        // 19) test that a string with an array with a pair of Array values is accepted.
        // 20) test that a string with an array with a pair of Object values is accepted.
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
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (0 == aValue->AsArray()->HowManyValues()));
                break;

            case 4 :
                aValue = listener->GetValue("[");
                okSoFar = (nullptr != aValue);
                break;

            case 5 :
                if (1 <= argc)
                {
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsNull()));
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
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        bool        expectedValue{'t' == tolower(*argv[0])};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsBoolean()) &&
                                   (expectedValue == fetchedValue->AsBoolean()->GetValue()));
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
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        int64_t     expectedValue;

                        okSoFar = (ConvertToInt64(*argv, expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsInteger()) &&
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
                    std::string     wrappedString{InitFile::MakeWrappedString(*argv)};

                    aValue = addArrayToStringAndParse(listener.get(), wrappedString);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsString()) &&
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
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        double      expectedValue;

                        okSoFar = (ConvertToDouble(*argv, expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsDouble()) &&
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
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        uint32_t    expectedValue = convertStringToIp4Value(*argv);

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsAddress()) &&
                                   (expectedValue == fetchedValue->AsAddress()->GetValue()));
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
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsArray()));
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
                    aValue = addArrayToStringAndParse(listener.get(), *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsObject()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 13 :
                if (2 <= argc)
                {
                    aValue = addArrayToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsNull()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsNull()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 14 :
                if (2 <= argc)
                {
                    aValue = addArrayToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        bool        expectedValue1{'t' == tolower(*argv[0])};
                        bool        expectedValue2{'t' == tolower(*argv[1])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsBoolean()) &&
                                   (expectedValue1 == fetchedValue1->AsBoolean()->GetValue()) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsBoolean()) &&
                                   (expectedValue2 == fetchedValue2->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 15 :
                if (2 <= argc)
                {
                    aValue = addArrayToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        int64_t     expectedValue1;
                        int64_t     expectedValue2;

                        okSoFar = (ConvertToInt64(*argv, expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsInteger()) &&
                                   (expectedValue1 == fetchedValue1->AsInteger()->GetValue()) && ConvertToInt64(argv[1], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsInteger()) &&
                                   (expectedValue2 == fetchedValue2->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 16 :
                if (2 <= argc)
                {
                    std::string wrappedString1{InitFile::MakeWrappedString(*argv)};
                    std::string wrappedString2{InitFile::MakeWrappedString(argv[1])};

                    aValue = addArrayToStringAndParse(listener.get(), wrappedString1, wrappedString2);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsString()) &&
                                   (*argv == fetchedValue1->AsString()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsString()) && (argv[1] == fetchedValue2->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 17 :
                if (2 <= argc)
                {
                    aValue = addArrayToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        double      expectedValue1;
                        double      expectedValue2;

                        okSoFar = (ConvertToDouble(*argv, expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsDouble()) &&
                                   (expectedValue1 == fetchedValue1->AsDouble()->GetValue()) && ConvertToDouble(argv[1], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsDouble()) &&
                                   (expectedValue2 == fetchedValue2->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 18 :
                if (2 <= argc)
                {
                    aValue = addArrayToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        uint32_t    expectedValue1{convertStringToIp4Value(*argv)};
                        uint32_t    expectedValue2{convertStringToIp4Value(argv[1])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsAddress()) &&
                                   (expectedValue1 == fetchedValue1->AsAddress()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsAddress()) && (expectedValue2 == fetchedValue2->AsAddress()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 19 :
                aValue = addArrayToStringAndParse(listener.get(), "[ ]", "[]");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                    SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsArray()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsArray()));
                }
                break;

            case 20 :
                aValue = addArrayToStringAndParse(listener.get(), "{}", "{ }");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                    SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsObject()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsObject()));
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
    (const char *   launchPath,
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    INITFILE_UNUSED_VAR_(launchPath);
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int         result{1};
    std::string fileName{getTempFileName()};

    try
    {
        std::unique_ptr<InitFile::BaseValueListener>    listener{new InitFile::BaseValueListener};
        SpBaseValue                                     aValue;
        bool                                            okSoFar;
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
        // 13) test that a file with an array with a pair of NULLs is accepted.
        // 14) test that a file with an array with a pair of Boolean values is accepted.
        // 15) test that a file with an array with a pair of integer values is accepted.
        // 16) test that a file with an array with a pair of string values is accepted.
        // 17) test that a file with an array with a pair of double values is accepted.
        // 18) test that a file with an array with a pair of address values is accepted.
        // 19) test that a file with an array with a pair of array values is accepted.
        // 20) test that a file with an array with a pair of object values is accepted.
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
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (0 == aValue->AsArray()->HowManyValues()));
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsNull()));
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        bool        expectedValue{'t' == tolower(*argv[0])};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsBoolean()) &&
                                   (expectedValue == fetchedValue->AsBoolean()->GetValue()));
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        int64_t     expectedValue;

                        okSoFar = (ConvertToInt64(*argv, expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsInteger()) &&
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
                    std::string wrappedString{InitFile::MakeWrappedString(*argv)};

                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, wrappedString);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsString()) &&
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        double      expectedValue;

                        okSoFar = (ConvertToDouble(*argv, expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsDouble()) &&
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};
                        uint32_t    expectedValue{convertStringToIp4Value(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsAddress()) &&
                                   (expectedValue == fetchedValue->AsAddress()->GetValue()));
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsArray()));
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
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (1 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsArray()->GetValue(0)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsObject()));
                    }
                }
                else
                {
                    ODL_LOG("! (1 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 13 :
                if (2 <= argc)
                {
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsNull()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsNull()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 14 :
                if (2 <= argc)
                {
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        bool        expectedValue1{'t' == tolower(*argv[0])};
                        bool        expectedValue2{'t' == tolower(*argv[1])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsBoolean()) &&
                                   (expectedValue1 == fetchedValue1->AsBoolean()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsBoolean()) && (expectedValue2 == fetchedValue2->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 15 :
                if (2 <= argc)
                {
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        int64_t     expectedValue1;
                        int64_t     expectedValue2;

                        okSoFar = (ConvertToInt64(*argv, expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsInteger()) &&
                                   (expectedValue1 == fetchedValue1->AsInteger()->GetValue()) && ConvertToInt64(argv[1], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsInteger()) &&
                                   (expectedValue2 == fetchedValue2->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 16 :
                if (2 <= argc)
                {
                    std::string wrappedString1{InitFile::MakeWrappedString(*argv)};
                    std::string wrappedString2{InitFile::MakeWrappedString(argv[1])};

                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, wrappedString1, wrappedString2);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsString()) &&
                                   (*argv == fetchedValue1->AsString()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsString()) && (argv[1] == fetchedValue2->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 17 :
                if (2 <= argc)
                {
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        double      expectedValue1;
                        double      expectedValue2;

                        okSoFar = (ConvertToDouble(*argv, expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsDouble()) &&
                                   (expectedValue1 == fetchedValue1->AsDouble()->GetValue()) && ConvertToDouble(argv[1], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsDouble()) &&
                                   (expectedValue2 == fetchedValue2->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 18 :
                if (2 <= argc)
                {
                    aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                        SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};
                        uint32_t    expectedValue1{convertStringToIp4Value(*argv)};
                        uint32_t    expectedValue2{convertStringToIp4Value(argv[1])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsAddress()) &&
                                   (expectedValue1 == fetchedValue1->AsAddress()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsAddress()) && (expectedValue2 == fetchedValue2->AsAddress()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 19 :
                aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, "[]", "[ ]");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                    SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsArray()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsArray()));
                }
                break;

            case 20 :
                aValue = writeArrayToFileAndParse(listener.get(), inputOutput, fileName, "{}", "{ }");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsArray()) && (2 == aValue->AsArray()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsArray()->GetValue(0)};
                    SpBaseValue fetchedValue2{aValue->AsArray()->GetValue(1)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsObject()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsObject()));
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
    remove(fileName.c_str());
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
    (const char *   launchPath,
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    INITFILE_UNUSED_VAR_(launchPath);
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int result{1};

    try
    {
        std::unique_ptr<InitFile::BaseValueListener>    listener{new InitFile::BaseValueListener};
        SpBaseValue                                     aValue;
        bool                                            okSoFar;
        std::string                                     key1;
        std::string                                     key2;

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
        // 11) test that a string with an object with a pair of NULLs is accepted.
        // 12) test that a string with an object with a pair of Boolean values is accepted.
        // 13) test that a string with an object with a pair of integer values is accepted.
        // 14) test that a string with an object with a pair of string values is accepted.
        // 15) test that a string with an object with a pair of double values is accepted.
        // 16) test that a string with an object with a pair of address values is accepted.
        // 17) test that a string with an object with a pair of array values is accepted.
        // 18) test that a string with an object with a pair of object values is accepted.
        switch (subSelector)
        {
            case 1 :
                aValue = listener->GetValue("{}");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (0 == aValue->AsObject()->HowManyValues()));
                break;

            case 2 :
                aValue = listener->GetValue("{");
                okSoFar = (nullptr != aValue);
                break;

            case 3 :
                if (2 <= argc)
                {
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsNull()));
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
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        bool        expectedValue{'t' == tolower(*argv[1])};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsBoolean()) &&
                                   (expectedValue == fetchedValue->AsBoolean()->GetValue()));
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
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        int64_t     expectedValue;

                        okSoFar = (ConvertToInt64(argv[1], expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsInteger()) &&
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
                    std::string wrappedString{InitFile::MakeWrappedString(argv[1])};

                    aValue = addObjectToStringAndParse(listener.get(), *argv, wrappedString);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsString()) &&
                                   (argv[1] == fetchedValue->AsString()->GetValue()));
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
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        double      expectedValue;

                        okSoFar = (ConvertToDouble(argv[1], expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsDouble()) &&
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
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        uint32_t    expectedValue = convertStringToIp4Value(argv[1]);

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsAddress()) &&
                                   (expectedValue == fetchedValue->AsAddress()->GetValue()));
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
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsArray()));
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
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsObject()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 11 :
                if (4 <= argc)
                {
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsNull()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsNull()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 12 :
                if (4 <= argc)
                {
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        bool        expectedValue1{'t' == tolower(*argv[1])};
                        bool        expectedValue2{'t' == tolower(*argv[3])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsBoolean()) &&
                                   (expectedValue1 == fetchedValue1->AsBoolean()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue1->AsBoolean()) && (expectedValue2 == fetchedValue2->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 13 :
                if (4 <= argc)
                {
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        int64_t     expectedValue1;
                        int64_t     expectedValue2;

                        okSoFar = (ConvertToInt64(argv[1], expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsInteger()) &&
                                   (expectedValue1 == fetchedValue1->AsInteger()->GetValue()) && ConvertToInt64(argv[3], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsInteger()) &&
                                   (expectedValue2 == fetchedValue2->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 14 :
                if (4 <= argc)
                {
                    std::string wrappedString1{InitFile::MakeWrappedString(argv[1])};
                    std::string wrappedString2{InitFile::MakeWrappedString(argv[3])};

                    aValue = addObjectToStringAndParse(listener.get(), *argv, wrappedString1, argv[2], wrappedString2);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsString()) &&
                                   (argv[1] == fetchedValue1->AsString()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsString()) && (argv[3] == fetchedValue2->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 15 :
                if (4 <= argc)
                {
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        double      expectedValue1;
                        double      expectedValue2;

                        okSoFar = (ConvertToDouble(argv[1], expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsDouble()) &&
                                   (expectedValue1 == fetchedValue1->AsDouble()->GetValue()) && ConvertToDouble(argv[3], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsDouble()) &&
                                   (expectedValue2 == fetchedValue2->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 16 :
                if (4 <= argc)
                {
                    aValue = addObjectToStringAndParse(listener.get(), *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        uint32_t    expectedValue1{convertStringToIp4Value(argv[1])};
                        uint32_t    expectedValue2{convertStringToIp4Value(argv[3])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsAddress()) &&
                                   (expectedValue1 == fetchedValue1->AsAddress()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsAddress()) && (expectedValue2 == fetchedValue2->AsAddress()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 17 :
                key1 = std::to_string(RandomDouble(-1000, 1000));
                key2 = std::to_string(RandomDouble(-1000, 1000));
                aValue = addObjectToStringAndParse(listener.get(), key1, "[ ]", key2, "[]");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(key1)};
                    SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(key2)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsArray()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsArray()));
                }
                break;

            case 18 :
                key1 = std::to_string(RandomDouble(-1000, 1000));
                key2 = std::to_string(RandomDouble(-1000, 1000));
                aValue = addObjectToStringAndParse(listener.get(), key1, "{ }", key2, "{}");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(key1)};
                    SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(key2)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsObject()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsObject()));
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
    (const char *   launchPath,
     const int      subSelector,
     const bool     expected,
     const int      argc,
     char **        argv)
{
    INITFILE_UNUSED_VAR_(launchPath);
    ODL_ENTER(); //####
    //ODL_S1("launchPath = ", launchPath); //####
    ODL_I2("subSelector = ", subSelector, "argc = ", argc); //####
    ODL_B1("expected = ", expected); //####
    ODL_P1("argv = ", argv); //####
    int         result{1};
    std::string fileName{getTempFileName()};

    try
    {
        std::unique_ptr<InitFile::BaseValueListener>    listener{new InitFile::BaseValueListener};
        SpBaseValue                                     aValue;
        bool                                            okSoFar;
        std::fstream                                    inputOutput;
        std::string                                     key1;
        std::string                                     key2;

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
        // 11) test that a file with an object with a pair of NULLs is accepted.
        // 12) test that a file with an object with a pair of Boolean values is accepted.
        // 13) test that a file with an object with a pair of integer values is accepted.
        // 14) test that a file with an object with a pair of string values is accepted.
        // 15) test that a file with an object with a pair of double values is accepted.
        // 16) test that a file with an object with a pair of address values is accepted.
        // 17) test that a file with an object with a pair of array values is accepted.
        // 18) test that a file with an object with a pair of object values is accepted.
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
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (0 == aValue->AsObject()->HowManyValues()));
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsNull()));
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        bool        expectedValue{'t' == tolower(*argv[1])};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsBoolean()) &&
                                   (expectedValue == fetchedValue->AsBoolean()->GetValue()));
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        int64_t     expectedValue;

                        okSoFar = (ConvertToInt64(argv[1], expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsInteger()) &&
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
                    std::string wrappedString{InitFile::MakeWrappedString(argv[1])};

                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, wrappedString);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsString()) &&
                                   (argv[1] == fetchedValue->AsString()->GetValue()));
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        double      expectedValue;

                        okSoFar = (ConvertToDouble(argv[1], expectedValue) && (nullptr != fetchedValue) && (nullptr != fetchedValue->AsDouble()) &&
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};
                        uint32_t    expectedValue{convertStringToIp4Value(argv[1])};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsAddress()) &&
                                   (expectedValue == fetchedValue->AsAddress()->GetValue()));
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsArray()));
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
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (1 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue{aValue->AsObject()->GetValue(*argv)};

                        okSoFar = ((nullptr != fetchedValue) && (nullptr != fetchedValue->AsObject()));
                    }
                }
                else
                {
                    ODL_LOG("! (2 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 11 :
                if (4 <= argc)
                {
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsNull()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsNull()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 12 :
                if (4 <= argc)
                {
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        bool        expectedValue1{'t' == tolower(*argv[1])};
                        bool        expectedValue2{'t' == tolower(*argv[3])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsBoolean()) &&
                                   (expectedValue1 == fetchedValue1->AsBoolean()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue1->AsBoolean()) && (expectedValue2 == fetchedValue2->AsBoolean()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 13 :
                if (4 <= argc)
                {
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        int64_t     expectedValue1;
                        int64_t     expectedValue2;

                        okSoFar = (ConvertToInt64(argv[1], expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsInteger()) &&
                                   (expectedValue1 == fetchedValue1->AsInteger()->GetValue()) && ConvertToInt64(argv[3], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsInteger()) &&
                                   (expectedValue2 == fetchedValue2->AsInteger()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 14 :
                if (4 <= argc)
                {
                    std::string wrappedString1{InitFile::MakeWrappedString(argv[1])};
                    std::string wrappedString2{InitFile::MakeWrappedString(argv[3])};

                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, wrappedString1, argv[2], wrappedString2);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsString()) &&
                                   (argv[1] == fetchedValue1->AsString()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsString()) && (argv[3] == fetchedValue2->AsString()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 15 :
                if (4 <= argc)
                {
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        double      expectedValue1;
                        double      expectedValue2;

                        okSoFar = (ConvertToDouble(argv[1], expectedValue1) && (nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsDouble()) &&
                                   (expectedValue1 == fetchedValue1->AsDouble()->GetValue()) && ConvertToDouble(argv[3], expectedValue2) &&
                                   (nullptr != fetchedValue2) && (nullptr != fetchedValue2->AsDouble()) &&
                                   (expectedValue2 == fetchedValue2->AsDouble()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 16 :
                if (4 <= argc)
                {
                    aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, *argv, argv[1], argv[2], argv[3]);
                    okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                    if (okSoFar)
                    {
                        SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(*argv)};
                        SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(argv[2])};
                        uint32_t    expectedValue1{convertStringToIp4Value(argv[1])};
                        uint32_t    expectedValue2{convertStringToIp4Value(argv[3])};

                        okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsAddress()) &&
                                   (expectedValue1 == fetchedValue1->AsAddress()->GetValue()) && (nullptr != fetchedValue2) &&
                                   (nullptr != fetchedValue2->AsAddress()) && (expectedValue2 == fetchedValue2->AsAddress()->GetValue()));
                    }
                }
                else
                {
                    ODL_LOG("! (4 <= argc)"); //####
                    okSoFar = false;
                }
                break;

            case 17 :
                key1 = std::to_string(RandomDouble(-1000, 1000));
                key2 = std::to_string(RandomDouble(-1000, 1000));
                aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, key1, "[ ]", key2, "[]");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(key1)};
                    SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(key2)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsArray()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsArray()));
                }
                break;

            case 18 :
                key1 = std::to_string(RandomDouble(-1000, 1000));
                key2 = std::to_string(RandomDouble(-1000, 1000));
                aValue = writeObjectToFileAndParse(listener.get(), inputOutput, fileName, key1, "{ }", key2, "{}");
                okSoFar = ((nullptr != aValue) && (nullptr != aValue->AsObject()) && (2 == aValue->AsObject()->HowManyValues()));
                if (okSoFar)
                {
                    SpBaseValue fetchedValue1{aValue->AsObject()->GetValue(key1)};
                    SpBaseValue fetchedValue2{aValue->AsObject()->GetValue(key2)};

                    okSoFar = ((nullptr != fetchedValue1) && (nullptr != fetchedValue1->AsObject()) && (nullptr != fetchedValue2) &&
                               (nullptr != fetchedValue2->AsObject()));
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
    remove(fileName.c_str());
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
