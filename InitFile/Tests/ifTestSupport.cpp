//--------------------------------------------------------------------------------------------------
//
//  File:       Tests/ifTestSupport.cpp
//
//  Project:    IF
//
//  Contains:   The function and class definitions for InitFile test programs.
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
//  Created:    2020-09-25
//
//--------------------------------------------------------------------------------------------------

#include "ifTestSupport.h"

#include <initFileBase.h>

#include <csignal>
#include <random>
#include <sstream>
#include <string>

//#include <odlEnable.h>
#include <odlInclude.h>

#if MAC_OR_LINUX_
# include <unistd.h>
#else // ! MAC_OR_LINUX_
# include <Windows.h>
#endif // ! MAC_OR_LINUX_

#if LINUX_
# include <signal.h>
#endif // LINUX_

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The function and class definitions for %InitFile test programs. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Namespace references
#endif // defined(__APPLE__)

using namespace InitFile;
using namespace std::string_literals;

#if defined(__APPLE__)
# pragma mark Private structures, constants and variables
#endif // defined(__APPLE__)

/*! @brief Seed for random number generator. */
static std::random_device   lRd;

/*! @brief Mersenne Twister random number engine. */
static std::mt19937         lMt(lRd());

/*! @brief The signal to use for internally-detected timeouts. */
#if MAC_OR_LINUX_
# define STANDARD_SIGNAL_TO_USE_       SIGUSR2
#else // ! MAC_OR_LINUX_
# define STANDARD_SIGNAL_TO_USE_       42
#endif // ! MAC_OR_LINUX_

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

std::string  InitFile::kDQ{"\""};

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

#if MAC_OR_LINUX_
/*! @brief The signal handler to catch requests to stop the service.
 @param[in] signal The signal being handled. */
[[noreturn]]
static void
localCatcher
    (int    signal)
{
    INITFILE_UNUSED_VAR_(signal);
    ODL_ENTER(); //####
    //ODL_I1(signal); //####
    ODL_EXIT_EXIT(1); //####
    exit(1);
} // localCatcher
#endif // MAC_OR_LINUX_

#if defined(__APPLE__)
# pragma mark Class methods
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Constructors and Destructors
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)

bool
InitFile::CanReadFromStandardInput
    (void)
{
    ODL_ENTER(); //####
#if MAC_OR_LINUX_
    pid_t   fg{tcgetpgrp(STDIN_FILENO)};
#else // ! MAC_OR_LINUX_
    HWND    wind{GetConsoleWindow()};
#endif // ! MAC_OR_LINUX_
    bool    result{false};

#if MAC_OR_LINUX_
    if (-1 == fg)
    {
        // Piped
        result = true;
    }
    else
    {
        if (getpgrp() == fg)
        {
            // Foreground
            result = true;
        }
        else
        {
            // Background
            result = false;
        }
    }
#else // ! MAC_OR_LINUX_
    result = (nullptr != wind);
#endif // ! MAC_OR_LINUX_
    ODL_EXIT_B(result); //####
    return result;
} // InitFile::CanReadFromStandardInput

std::string
InitFile::ConvertDoubleToString
    (const double   value)
{
    ODL_ENTER(); //####
    ODL_D1(value); //####
    // Note that boost::lexical_cast<std::string>(double) generates strings with trailing digits.
    // That is, 1E-22 winds up as 9.9999999999999E-21, which is platform-sensitive.
    std::ostringstream  holder;

    holder << std::defaultfloat << value;
    std::string result{holder.str()};

    ODL_EXIT_s(result); //####
    return result;
} // InitFile::ConvertDoubleToString

bool
InitFile::ConvertToDouble
    (const char *   startPtr,
     double &       result)
{
    ODL_ENTER(); //####
    ODL_S1(startPtr); //####
    ODL_P1(&result); //####
    bool    okSoFar;
    char *  endPtr;
    double  value{strtod(startPtr, &endPtr)};

    if ((startPtr != endPtr) && (! *endPtr))
    {
        result = value;
        ODL_D1(result); //####
        okSoFar = true;
    }
    else
    {
        okSoFar = false;
    }
    ODL_EXIT_B(okSoFar); //####
    return okSoFar;
} // InitFile::ConvertToDouble

bool
InitFile::ConvertToInt64
    (const char *   startPtr,
     int64_t &      result)
{
    ODL_ENTER(); //####
    ODL_S1(startPtr); //####
    ODL_P1(&result); //####
    bool    okSoFar;
    char *  endPtr;
    int64_t value{strtoll(startPtr, &endPtr, 10)};

    if ((startPtr != endPtr) && (! *endPtr))
    {
        result = value;
        ODL_I1(result); //####
        okSoFar = true;
    }
    else
    {
        okSoFar = false;
    }
    ODL_EXIT_B(okSoFar); //####
    return okSoFar;
} // InitFile::ConvertToInt64

void
InitFile::Initialize
    (const std::string &    progName)
{
    INITFILE_UNUSED_VAR_(progName);
    ODL_ENTER(); //####
    //ODL_S1(progName); //####
    try
    {

    }
    catch (...)
    {
        ODL_LOG("Exception caught"); //####
        throw;
    }
    ODL_EXIT(); //####
} // InitFile::Initialize

const char *
InitFile::NameOfSignal
    (const int  theSignal)
{
    const char *    result;

#if MAC_OR_LINUX_
    switch (theSignal)
    {
        case SIGHUP :
            result = "SIGHUP[hangup]";
            break;

        case SIGINT :
            result = "SIGINT[interrupt]";
            break;

        case SIGQUIT :
            result = "SIGQUIT[quit]";
            break;

        case SIGILL :
            result = "SIGILL[illegal instruction]";
            break;

        case SIGTRAP :
            result = "SIGTRAP[trace trap]";
            break;

        case SIGABRT :
            result = "SIGABRT[abort()]";
            break;

# if (defined(_POSIX_C_SOURCE) && (! defined(_DARWIN_C_SOURCE)))
        case SIGPOLL :
            result = "SIGPOLL[pollable evebt]";
            break;
# else // (! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE)
        case SIGEMT :
            result = "SIGEMT[EMT instruction]";
            break;
# endif // (! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE)

        case SIGFPE :
            result = "SIGFPE[floating point exception]";
            break;

        case SIGKILL :
            result = "SIGKILL[kill]";
            break;

        case SIGBUS :
            result = "SIGBUS[bus error]";
            break;

        case SIGSEGV :
            result = "SIGSEGV[segmentation violation]";
            break;

        case SIGSYS :
            result = "SIGSYS[bad argument to system call]";
            break;

        case SIGPIPE :
            result = "SIGPIPE[write on a pipe with no one to read it]";
            break;

        case SIGALRM :
            result = "SIGALRM[alarm clock]";
            break;

        case SIGTERM :
            result = "SIGTERM[software termination signal from kill]";
            break;

        case SIGURG :
            result = "SIGURG[urgent condition on IO channel]";
            break;

        case SIGSTOP :
            result = "SIGSTOP[sendable stop signal not from tty]";
            break;

        case SIGTSTP :
            result = "SIGTSTP[stop signal from tty]";
            break;

        case SIGCONT :
            result = "SIGCONT[continue a stopped process]";
            break;

        case SIGCHLD :
            result = "SIGCHLD[to parent on child stop or exit]";
            break;

        case SIGTTIN :
            result = "SIGTTIN[to readers pgrp upon background tty read]";
            break;

        case SIGTTOU :
            result = "SIGTTOU[like TTIN for output if (tp->t_local &LTOSTOP)]";
            break;

# if ((! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE))
        case SIGIO :
            result = "SIGIO[input/output possible signal]";
            break;
# endif // (! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE)

        case SIGXCPU :
            result = "SIGXCPU[exceeded CPU time limit]";
            break;

        case SIGXFSZ :
            result = "SIGXFSZ[exceeded file size limit]";
            break;

        case SIGVTALRM :
            result = "SIGVTALRM[virtual time alarm]";
            break;

        case SIGPROF :
            result = "SIGPROF[profiling time alarm]";
            break;

# if ((! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE))
        case SIGWINCH :
            result = "SIGWINCH[window size changes]";
            break;
# endif // (! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE)

# if ((! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE))
        case SIGINFO :
            result = "SIGINFO[information request]";
            break;
# endif // (! defined(_POSIX_C_SOURCE)) || defined(_DARWIN_C_SOURCE)

        case SIGUSR1 :
            result = "SIGUSR1[user defined signal 1]";
            break;

        case SIGUSR2 :
            result = "SIGUSR2[user defined signal 2]";
            break;

        default :
            result = "unknown";
            break;

    }
#else // ! MAC_OR_LINUX_
    switch (theSignal)
    {
        case SIGINT :
            result = "SIGINT[interrupt]";
            break;

        case SIGABRT :
            result = "SIGABRT[abort()]";
            break;

        default :
            result = "unknown";
            break;

    }
#endif // ! MAC_OR_LINUX_
    return result;
} // InitFile::NameOfSignal

double
InitFile::RandomDouble
    (const double   minValue,
     const double   maxValue)
{
    std::uniform_real_distribution<double>  dist{minValue, maxValue};

    return dist(lMt);
} // InitFile::RandomDouble

uint32_t
InitFile::RandomUnsigned
    (void)
{
    std::uniform_int_distribution<> dist{0, RAND_MAX};

    return dist(lMt);
} // InitFile::RandomUnsigned

void
InitFile::SetSignalHandlers
    (InitFile::SignalHandler    theHandler)
{
    ODL_ENTER(); //####
#if MAC_OR_LINUX_
    sigset_t            blocking;
    struct sigaction    act;
#endif // MAC_OR_LINUX_

#if MAC_OR_LINUX_
    act.sa_handler = theHandler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
# if (defined(SIGABRT) && (SIGABRT != STANDARD_SIGNAL_TO_USE_))
    sigaction(SIGABRT, &act, nullptr);
# endif // defined(SIGABRT) && (SIGABRT != STANDARD_SIGNAL_TO_USE_)
# if (defined(SIGHUP) && (SIGHUP != STANDARD_SIGNAL_TO_USE_))
    sigaction(SIGHUP, &act, nullptr);
# endif // defined(SIGHUP) && (SIGABRT != STANDARD_SIGNAL_TO_USE_)
# if (defined(SIGINT) && (SIGINT != STANDARD_SIGNAL_TO_USE_))
    sigaction(SIGINT, &act, nullptr);
# endif // defined(SIGINT) && (SIGABRT != STANDARD_SIGNAL_TO_USE_)
# if (defined(SIGQUIT) && (SIGQUIT != STANDARD_SIGNAL_TO_USE_))
    sigaction(SIGQUIT, &act, nullptr);
# endif // defined(SIGQUIT) && (SIGABRT != STANDARD_SIGNAL_TO_USE_)
# if (defined(SIGUSR1) && (SIGUSR1 != STANDARD_SIGNAL_TO_USE_))
    sigaction(SIGUSR1, &act, nullptr);
# endif // defined(SIGUSR1) && (SIGABRT != STANDARD_SIGNAL_TO_USE_)
# if (defined(SIGUSR2) && (SIGUSR2 != STANDARD_SIGNAL_TO_USE_))
    sigaction(SIGUSR2, &act, nullptr);
# endif // defined(SIGUSR2) && (SIGABRT != STANDARD_SIGNAL_TO_USE_)
    sigemptyset(&blocking);
    sigaddset(&blocking, STANDARD_SIGNAL_TO_USE_);
    pthread_sigmask(SIG_BLOCK, &blocking, nullptr);
#else // ! MAC_OR_LINUX
#endif // ! MAC_OR_LINUX_
    ODL_EXIT(); //####
} // InitFile::SetSignalHandlers

void
InitFile::SetUpCatcher
    (void)
{
    ODL_ENTER(); //####
#if MAC_OR_LINUX_
    sigset_t            unblocking;
    struct sigaction    act;
#endif // MAC_OR_LINUX_

#if MAC_OR_LINUX_
    sigemptyset(&unblocking);
    sigaddset(&unblocking, STANDARD_SIGNAL_TO_USE_);
    pthread_sigmask(SIG_UNBLOCK, &unblocking, nullptr);
    act.sa_handler = localCatcher;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(STANDARD_SIGNAL_TO_USE_, &act, nullptr);
#else // ! MAC_OR_LINUX_
#endif // ! MAC_OR_LINUX_
    ODL_EXIT(); //####
} // InitFile::SetUpCatcher

void
InitFile::ShutDownCatcher
    (void)
{
    ODL_ENTER(); //####
#if MAC_OR_LINUX_
    sigset_t            blocking;
    struct sigaction    act;
#endif // MAC_OR_LINUX_

#if MAC_OR_LINUX_
    sigemptyset(&blocking);
    sigaddset(&blocking, STANDARD_SIGNAL_TO_USE_);
    pthread_sigmask(SIG_BLOCK, &blocking, nullptr);
    act.sa_handler = SIG_DFL;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(STANDARD_SIGNAL_TO_USE_, &act, nullptr);
#else // ! MAC_OR_LINUX_
#endif // ! MAC_OR_LINUX_
    ODL_EXIT(); //####
} // InitFile::ShutDownCatcher
