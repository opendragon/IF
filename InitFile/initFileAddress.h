//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileAddress.h
//
//  Project:    IF
//
//  Contains:   The class declaration for InitFile Address values.
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

#if (! defined(initFileAddress_H_))
# define initFileAddress_H_ /* Header guard */

# include <initFileBase.h>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for %InitFile Address values. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace InitFile
{
    /*! @brief A class to provide the base type for Address values. */
    class AddressValue final : public BaseValue
    {
        public :
            // Public type definitions.

        protected :
            // Protected type definitions.

        private :
            // Private type definitions.

            /*! @brief The class that this class is derived from. */
            using inherited = BaseValue;

        public :
            // Public methods.

            /*! @brief The constructor.
             @param[in] parent The parent of this value. */
            inline AddressValue
                (SpBaseValue    parent,
                 const uint32_t value) :
                    inherited{parent}, fValue{value}
                {
                }

            /*! @brief The copy constructor.
             @param[in] other The object to be copied. */
            AddressValue
                (const AddressValue &    other);

            /*! @brief The move constructor.
             @param[in] other The object to be moved. */
            AddressValue
                (AddressValue &&	other)
                noexcept;

            /*! @brief Return @c this if this is an IPv4 address.
             @return @c this if this is an IPv4 address. */
            AddressValue *
            AsAddress
                (void)
                override;

            /*! @brief Return @c this if this is an IPv4 address.
             @return @c this if this is an IPv4 address. */
            const AddressValue *
            AsAddress
                (void)
                const
                override;

            /*! @brief Return a copy of this value.
            @return A newly allocated copy of this value. */
            UpBaseValue
            Clone
                (void)
                const
                override;

            /*! @brief Return the content of this value.
             @return The content of this value. */
            inline uint32_t
            GetValue
                (void)
                const
            {
                return fValue;
            }

            /*! @brief The copy assignment operator.
             @param[in] other The object to be copied.
             @return The updated object. */
            AddressValue &
            operator =
                (const AddressValue &  other) = delete;

            /*! @brief The move assignment operator.
             @param[in] other The object to be moved.
             @return The updated object. */
            AddressValue &
            operator =
                (AddressValue &&  other)
                noexcept;

            /*! @brief Return @c true if the two values are equal.
             @param[in] other The value to be compared with.
             @return @c true if the two values are comparable and equal. */
            bool
            operator ==
                (const BaseValue &	other)
                const
                override;

            /*! @brief Write a human-readable representation of the value to a stream.
             @param[in,out] output The stream to be written to.
             @param[in] indentStep How many characters to insert at each level
             @param[in] indentChar The character to be used for indentation
             @param[in] indentLevel The amount of indentation to apply
             @param[in] squished @c true if the output has no unnecessary characters and @c false if it
             is as readable as possible.
             @return The stream being written to. */
            std::ostream &
            Print
                (std::ostream &	output,
                 const size_t	indentStep = 2,
                 const char		indentChar = ' ',
                 const size_t	indentLevel = 0,
                 const bool		squished = false)
                const
                override;

        protected :
            // Protected methods.

        private :
            // Private methods.

        public :
            // Public fields.

        protected :
            // Protected fields.

        private :
            // Private fields.

            /*! @brief The content of this value. */
            uint32_t    fValue{0};

    }; // AddressValue

} // InitFile

#endif /* not initFileAddress_H_ */
