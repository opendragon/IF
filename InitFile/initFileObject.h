//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileObject.h
//
//  Project:    IF
//
//  Contains:   The class declaration for InitFile Object values.
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

#if (! defined(initFileObject_H_))
# define initFileObject_H_ /* Header guard */

# include <initFileBase.h>
# include <initFileCompareWithoutCase.h>

# include <map>
# include <set>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for %InitFile Object values. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace InitFile
{
    /*! @brief A class to provide the base type for Object values. */
    class ObjectValue : public BaseValue
    {
        public :
            // Public type definitions.

        protected :
            // Protected type definitions.

        private :
            // Private type definitions.

            /*! @brief The class that this class is derived from. */
            using inherited = BaseValue;

            /*! @brief The internal storage structure for Object values. */
            using ValueMap = std::map<std::string, SpBaseValue, CompareWithoutCase>;

            /*! @brief A shortcut name for a constant iterator over the Object contents. */
            using const_iterator = ValueMap::const_iterator;

            /*! @brief A shortcut name for an iterator over the Object contents. */
            using iterator = ValueMap::iterator;

            /*! @brief A shortcut name for the size of the Object contents. */
            using size_type = ValueMap::size_type;

            /*! @brief A shortcut name for the keys used to access the Object contents. */
            using key_type = ValueMap::key_type;

            /*! @brief A shortcut name for the values stored in the Object contents. */
            using value_type = ValueMap::value_type;

            /*! @brief A shortcut name for the result of an insert into the Object contents. */
            using insert_type = std::pair<iterator, bool>;

        public :
            // Public methods.

            /*! @brief The constructor.
             @param[in] parent The parent of this value. */
            inline explicit ObjectValue
                (SpBaseValue    parent) :
                    inherited{parent}
                {
                } /* constructor */

            /*! @brief The move constructor.
             @param[in] other The object to be moved. */
            ObjectValue
                (ObjectValue &&	other)
                noexcept;

            /*! @brief Add a value to the Object contents.
             @param[in] key The tag for the value being added.
             @param[in] aValue The value to be added.
             Only non-@c nullptr values will be added and only if the key is non-empty.
             @return The Object that was modified. */
            ObjectValue &
            AddValue
                (const std::string &    key,
                 SpBaseValue                 aValue);

            /*! @brief Return @c this if this is an object.
             @return @c this if this is an object. */
            ObjectValue *
            AsObject
                (void)
                override;

            /*! @brief Return @c this if this is an object.
             @return @c this if this is an object. */
            const ObjectValue *
            AsObject
                (void)
                const
                override;

            /*! @brief Return a copy of this value.
            @return A newly allocated copy of this value. */
            SpBaseValue
            Clone
                (void)
                const
                override;

            /*! @brief Return the set of tags for this object.
            @return The tags for this object. */
            std::set<std::string>
            GetTags
                (void)
                const;

            /*! @brief Return a value from the Object contents.
             @param[in] tag The tag for the desired value.
             @return The value in the contents corresponding to the tag.
             @c nullptr is returned if the tag is empty or not found in the contents. */
            SpBaseValue
            GetValue
                (const std::string &    tag)
                const;

            /*! @brief Return the number of values in the Object contents.
             @return The number of values in the Object contents. */
            size_t
            HowManyValues
                (void)
                const;

            /*! @brief Return @c true if the Object contents includes a value with the given tag.
             @param[in] key The tag to be checked.
             @return @c true if there is a value in the contents with the given tag.
             @c false is returned if the tag is empty or not found in the contents. */
            bool
            IsTagPresent
                (const std::string &    tag)
                const;

            /*! @brief The copy assignment operator.
             @param[in] other The object to be copied.
             @return The updated object. */
            ObjectValue &
            operator =
                (const ObjectValue &  other) = delete;

            /*! @brief The move assignment operator.
             @param[in] other The object to be moved.
             @return The updated object. */
            ObjectValue &
            operator =
                (ObjectValue &&  other)
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

            /*! @brief The copy constructor. Used by Clone().
             @param[in] other The object to be copied. */
            ObjectValue
                (const ObjectValue &	other);

        public :
            // Public fields.

        protected :
            // Protected fields.

        private :
            // Private fields.

            /*! @brief The content of this value. */
            ValueMap  fValue{};

    }; // ObjectValue

} // InitFile

#endif /* not initFileObject_H_ */
