//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileValueListener.h
//
//  Project:    IF
//
//  Contains:   The class declaration for a listener for InitFile streams.
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

#if (! defined(initFileValueListener_H_))
# define initFileValueListener_H_ /* Header guard */

# include <initFileBase.h>

# include "antlr4-runtime.h"
# include "InitFileParserBaseListener.h"

# include <deque>
# include <istream>
# include <ostream>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for a listener for %InitFile streams. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace InitFile
{

    class BaseValueListener final : public InitParser::InitFileParserBaseListener
    {
    public :
        // Public type definitions.

    protected :
        // Protected type definitions.

    private :
        // Private type definitions.

    public :
        // Public methods.

        /*! @brief The constructor. */
        BaseValueListener
            (void);

        /*! @brief The move constructor.
         @param[in] other The object to be moved. */
        BaseValueListener
            (BaseValueListener &&	other)
            noexcept;

        /*! @brief The destructor. */
        virtual
        ~BaseValueListener
            (void)
            override;

        /*! @brief Handle the beginning of an empty object description.
        @param[in] ctx The parser context. */
        virtual void
        enterEmptyObject
            (InitParser::InitFileParser::EmptyObjectContext * ctx)
            override;

        /*! @brief Handle the beginning of a non-empty array description.
        @param[in] ctx The parser context. */
        virtual void
        enterNonEmptyArray
            (InitParser::InitFileParser::NonEmptyArrayContext * ctx)
            override;

        /*! @brief Handle the beginning of a non-empty object description.
        @param[in] ctx The parser context. */
        virtual void
        enterNonEmptyObject
            (InitParser::InitFileParser::NonEmptyObjectContext * ctx)
            override;

        /*! @brief Handle a complete address value.
        @param[in] ctx The parser context. */
        virtual void
        exitAddressValue
            (InitParser::InitFileParser::AddressValueContext *  ctx)
            override;

        /*! @brief Handle a complete configuration.
        @param[in] ctx The parser context. */
        virtual void
        exitConfiguration
            (InitParser::InitFileParser::ConfigurationContext * ctx)
            override;

        /*! @brief Handle a complete double value.
        @param[in] ctx The parser context. */
        virtual void
        exitDoubleValue
            (InitParser::InitFileParser::DoubleValueContext * ctx)
            override;

        /*! @brief Handle a complete empty array.
        @param[in] ctx The parser context. */
        virtual void
        exitEmptyArray
            (InitParser::InitFileParser::EmptyArrayContext * ctx)
            override;

        /*! @brief Handle a complete empty object.
        @param[in] ctx The parser context. */
        virtual void
        exitEmptyObject
            (InitParser::InitFileParser::EmptyObjectContext * ctx)
            override;

        /*! @brief Handle a complete integer value.
        @param[in] ctx The parser context. */
        virtual void
        exitIntegerValue
            (InitParser::InitFileParser::IntegerValueContext *  ctx)
            override;

        /*! @brief Handle a complete literal value.
        @param[in] ctx The parser context. */
        virtual void
        exitLiteralValue
            (InitParser::InitFileParser::LiteralValueContext * ctx)
            override;

        /*! @brief Handle a complete non-empty array.
        @param[in] ctx The parser context. */
        virtual void
        exitNonEmptyArray
            (InitParser::InitFileParser::NonEmptyArrayContext * ctx)
            override;

        /*! @brief Handle a complete non-empty object.
        @param[in] ctx The parser context. */
        virtual void
        exitNonEmptyObject
            (InitParser::InitFileParser::NonEmptyObjectContext * ctx)
            override;

        /*! @brief Handle a complete tag / value pair.
        @param[in] ctx The parser context. */
        virtual void
        exitPair
            (InitParser::InitFileParser::PairContext * ctx)
            override;

        /*! @brief Handle a complete string value.
        @param[in] ctx The parser context. */
        virtual void
        exitStringValue
            (InitParser::InitFileParser::StringValueContext * ctx)
            override;

        /*! @brief Handle a complete tag.
        @param[in] ctx The parser context. */
        virtual void
        exitTag
            (InitParser::InitFileParser::TagContext * ctx)
            override;

        /*! @brief Extract the values from a string.
            @param[in] input The string to be analyzed.
            @return The top-level value found in the string. */
        SpBaseValue
        GetValue
            (const std::string &	input);

        /*! @brief Extract the values from a stream.
            @param[in] input The stream to be analyzed.
            @return The top-level value found in the stream. */
        SpBaseValue
        GetValue
            (std::istream &	input);

    protected :
        // Protected methods.

    private :
        // Private methods.

        /*! @brief Remove the top container from the container stack and return it.
        @return The top of the container stack. */
        SpBaseValue
        popContainer
            (void);

        /*! @brief Remove the top tag from the tag stack and return it.
        @return The top of the tag stack. */
        std::string
        popTag
            (void);

        /*! @brief Remove the top value from the value stack and return it.
        @return The top of the value stack. */
        SpBaseValue
        popValue
            (void);

        /*! @brief Push a container onto the container stack.
        @return The active listener. */
        BaseValueListener &
        pushContainer
            (SpBaseValue  value);

        /*! @brief Push a tag onto the tag stack.
        @return The active listener. */
        BaseValueListener &
        pushTag
            (const std::string  tag);

        /*! @brief Push a value onto the value stack.
        @return The active listener. */
        BaseValueListener &
        pushValue
            (SpBaseValue  value);

    public :
        // Public fields.

    protected :
        // Protected fields.

    private :
        // Private fields.

        /*! @brief The stack of active tags. */
        std::deque<std::string> fTagStack{};

        /*! @brief The stack of values to be stored. */
        std::deque<SpBaseValue> fValueStack{};

        /*! @brief The stack of open containers. */
        std::deque<SpBaseValue> fContainerStack{};

        /*! @brief The container currently being filled. */
        SpBaseValue fCurrentContainer{};

        /*! @brief The outermost container. */
        SpBaseValue fRootObject{};

    }; // BaseValueListener

} // InitFile

#endif /* not initFileValueListener_H_ */
