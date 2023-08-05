//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileArray.h
//
//  Project:    IF
//
//  Contains:   The class declaration for InitFile Array values.
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

#if (! defined(initFileArray_H_))
# define initFileArray_H_ /* Header guard */

# include <initFileBase.h>

# include <deque>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for %InitFile Array values. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace InitFile
{
    /*! @brief A class to provide the base type for Array values. */
    class ArrayValue final : public BaseValue
    {
        public :
            // Public type definitions.

        protected :
            // Protected type definitions.

        private :
            // Private type definitions.

            /*! @brief The class that this class is derived from. */
            using inherited = BaseValue;

            /*! @brief The internal storage structure for Array values. */
            using ValueQueue = std::deque<SpBaseValue>;

            /*! @brief A shortcut name for a constant iterator over the Array contents. */
            using const_iterator = ValueQueue::const_iterator;

            /*! @brief A shortcut name for an iterator over the Array contents. */
            using iterator = ValueQueue::iterator;

            /*! @brief A shortcut name for a reverse iterator over the Array contents. */
            using const_reverse_iterator = ValueQueue::const_reverse_iterator;

            /*! @brief A shortcut name for the size of the Array contents. */
            using size_type = ValueQueue::size_type;

        public :
            // Public methods.

            /*! @brief The constructor.
             @param[in] parent The parent of this value. */
            inline explicit ArrayValue
                (SpBaseValue    parent) :
                    inherited{parent}
                {
                }

            /*! @brief The copy constructor.
             @param[in] other The object to be copied. */
            ArrayValue
                (const ArrayValue &    other);

            /*! @brief The move constructor.
             @param[in] other The object to be moved. */
            ArrayValue
                (ArrayValue &&	other)
                noexcept;

            /*! @brief Add a value to the Array contents.
             @param[in] aValue The value to be added.
             Values are added to the end of the contents.
             Only non-@c nullptr values will be added.
             @return The Array that was modified. */
            ArrayValue &
            AddValueAtBack
                (SpBaseValue aValue);

            /*! @brief Add a value to the Array contents.
             @param[in] aValue The value to be added.
             Values are added to the beginning of the contents.
             Only non-@c nullptr values will be added.
             @return The Array that was modified. */
            ArrayValue &
            AddValueAtFront
                (SpBaseValue aValue);

            /*! @brief Return @c this if this is an array.
             @return @c this if this is an array. */
            ArrayValue *
            AsArray
                (void)
                override;

            /*! @brief Return @c this if this is an array.
             @return @c this if this is an array. */
            const ArrayValue *
            AsArray
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

            /*! @brief Return a value from the Array contents.
             @param[in] index The index (zero-origin) of the desired value.
             @return The value in the contents corresponding to the index. */
            SpBaseValue
            GetValue
                (const size_t   index)
                const;

            /*! @brief Return the number of values in the Array contents.
             @return The number of values in the Array contents. */
            size_t
            HowManyValues
                (void)
                const;

            /*! @brief The copy assignment operator.
             @param[in] other The object to be copied.
             @return The updated object. */
            ArrayValue &
            operator =
                (const ArrayValue &  other) = delete;

            /*! @brief The move assignment operator.
             @param[in] other The object to be moved.
             @return The updated object. */
            ArrayValue &
            operator =
                (ArrayValue &&  other)
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
            ValueQueue fValue{};

    }; // ArrayValue

} // InitFile

#endif /* not initFileArray_H_ */
