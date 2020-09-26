//--------------------------------------------------------------------------------------------------
//
//  File:       Tests/ifNull.h
//
//  Project:    IF
//
//  Contains:   The function and class declarations for InitFile test programs.
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

#if (! defined(ifTestSupport_H_))
# define ifTestSupport_H_ /* Header guard */

# include <string>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The function and class declarations for %InitFile test programs. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

/*! @brief A simple macro to hold the pieces of a string together. */
# define T_(xx_)            xx_

/*! @brief A simple macro to hide unused parameters for a function. */
# define NOT_USED_(var_)    /* var_ */

/*! @brief A simple macro to calculate the number of elements in an array. */
# define A_SIZE(arr_)       (sizeof(arr_) / sizeof(*arr_))

namespace InitFile
{
    /*! @brief A pointer to a handler for system signals.
     @param[in] theSignal The signal of interest. */
    using SignalHandler = void (*)
       (int theSignal);

    /*! @brief Return @c true if standard input can be used and @c false otherwise.
     @return @c true if standard input can be used and @c false otherwise. */
    bool
    CanReadFromStandardInput
        (void);

    /*! @brief Convert a double value to a string.
     @param[in] value The value to be represented in the string.
     @return The string representation of the value. */
    std::string
    ConvertDoubleToString
        (const double   value);
    
    /*! @brief Convert a string to a double value.
     @param[in] startPtr The string to be converted.
     @param[out] result The value represented by the string.
     @return @c true if the string contained a representation of a double and @c false
     otherwise. */
    bool
    ConvertToDouble
        (const char *   startPtr,
         double &       result);

    /*! @brief Convert a string to an integer value.
     @param[in] startPtr The string to be converted.
     @param[out] result The value represented by the string.
     @return @c true if the string contained a representation of an integer and @c false
     otherwise. */
    bool
    ConvertToInt64
        (const char *   startPtr,
         int64_t &      result);

    /*! @brief Perform initialization of internal resources.
     @param[in] progName The name of the executing program.

     Should be called in the main() function of each application or service. */
    void
    Initialize
        (const std::string &    progName);

    /*! @brief Return the name of a signal.
     @param[in] theSignal The signal of interest.
     @return A string description of the signal. */
    const char *
    NameOfSignal
        (const int  theSignal);

    /*! @brief Connect the standard signals to a handler.
     @param[in] theHandler The new handler for the signals. */
    void
    SetSignalHandlers
        (SignalHandler  theHandler);

    /*! @brief Set up the signal-handling behaviour so that this thread will catch our signal. */
    void
    SetUpCatcher
        (void);

    /*! @brief Restore the normal signal-handling behaviour. */
    void
    ShutDownCatcher
        (void);

} // InitFile

#endif /* not ifTestSupport_H_ */
