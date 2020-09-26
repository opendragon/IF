//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifBase.h
//
//  Project:    IF
//
//  Contains:   The class declaration for InitFile values.
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

#if (! defined(ifBase_H_))
# define ifBase_H_ /* Header guard */

# include <ifConfig.h>

# include <istream>
# include <ostream>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for %InitFile values. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace InitFile
{
	// Forward references:
	class AddressValue;
	class ArrayValue;
	class BaseValue;
	class BooleanValue;
	class DoubleValue;
	class IntegerValue;
	class NullValue;
	class ObjectValue;
	class StringValue;

    /*! @brief A holder for a shared pointer to an IPv4 address value. */
    using SpAddress = std::shared_ptr<AddressValue>;

    /*! @brief A holder for a shared pointer to an array value. */
    using SpArray = std::shared_ptr<ArrayValue>;

    /*! @brief A holder for a shared pointer to a general value. */
    using SpBase = std::shared_ptr<BaseValue>;

    /*! @brief A holder for a shared pointer to a boolean value. */
    using SpBoolean = std::shared_ptr<BooleanValue>;

    /*! @brief A holder for a shared pointer to a double value. */
    using SpDouble = std::shared_ptr<DoubleValue>;

    /*! @brief A holder for a shared pointer to an integer value. */
    using SpInteger = std::shared_ptr<IntegerValue>;

    /*! @brief A holder for a shared pointer to a null value. */
    using SpNull = std::shared_ptr<NullValue>;

    /*! @brief A holder for a shared pointer to an object value. */
    using SpObject = std::shared_ptr<ObjectValue>;

    /*! @brief A holder for a shared pointer to a string value. */
    using SpString = std::shared_ptr<StringValue>;

    /*! @brief A class to provide the base type for values. */
    class BaseValue
    {
    public :
        // Public type definitions.

    protected :
        // Protected type definitions.

    private :
        // Private type definitions.

    public :
        // Public methods.

        /*! @brief Return @c this if this is an IPv4 address value.
         @return @c this if this is an IPv4 address value. */
		virtual AddressValue *
		AsAddress
			(void);

        /*! @brief Return @c this if this is an array value.
         @return @c this if this is an array value. */
		virtual ArrayValue *
		AsArray
			(void);

        /*! @brief Return @c this if this is a boolean value.
         @return @c this if this is a boolean value. */
		virtual BooleanValue *
		AsBoolean
			(void);

        /*! @brief Return @c this if this is a double value.
         @return @c this if this is a double value. */
		virtual DoubleValue *
		AsDouble
			(void);

        /*! @brief Return @c this if this is an integer value.
         @return @c this if this is an integer value. */
		virtual IntegerValue *
		AsInteger
			(void);

        /*! @brief Return @c this if this is NULL.
         @return @c this if this is NULL. */
		virtual NullValue *
		AsNull
			(void);

        /*! @brief Return @c this if this is an object.
         @return @c this if this is an object. */
		virtual ObjectValue *
		AsObject
			(void);

        /*! @brief Return @c this if this is a string.
         @return @c this if this is a string. */
		virtual StringValue *
		AsString
			(void);

        /*! @brief The destructor. */
        virtual
        ~BaseValue
            (void);

        /*! @brief Return the parent of this value.
         @return The parent of this value. */
		inline SpBase
		GetParent
			(void)
			const
		{
			return fParent;
		} // GetParent

        /*! @brief Write a human-readable representation of the value to a stream.
         @param[in,out] output The stream to be written to.
		 @param[in] indentStep How many characters to insert at each level
		 @param[in] indentChar The character to be used for indentation
		 @param[in] indentLevel The amount of indentation to apply
         @param[in] squished @c true if the output has no unnecessary characters and @c false if it
         is as readable as possible.
		 @return The stream being written to. */
		virtual std::ostream &
		Print
			(std::ostream &	output,
			 const size_t	indentStep = 2,
			 const char		indentChar = ' ',
			 const size_t	indentLevel = 0,
			 const bool		squished = false)
			const = 0;

    protected :
        // Protected methods.

        /*! @brief The constructor.
         @param[in] parent The parent of this value. */
		inline BaseValue
			(SpBase	parent) :
				fParent(parent)
			{
			} /* constructor */

		/*! @brief Add multiple characters to a stream.
         @param[in,out] output The stream to be written to.
		 @param[in] aChar The character to write.
		 @param[in] howMany The number of characters to write.
		 @return The stream being written to. */
		std::ostream &
		outputChars
			(std::ostream &	output,
			 const char		aChar,
			 const size_t	howMany)
			const;

		/*! @brief Add a string to a stream, with special characters escaped.
         @param[in,out] output The stream to be written to.
		 @param[in] aString The string to write.
		 @return The stream being written to. */
		std::ostream &
		outputEscapedString
			(std::ostream &			output,
			 const std::string &	aString)
			const;

    private :
        // Private methods.

    public :
        // Public fields.

    protected :
        // Protected fields.

        /*! @brief The parent of this value. */
		SpBase	fParent;

    private :
        // Private fields.

    }; // BaseValue

} // InitFile

#endif /* not ifBase_H_ */
