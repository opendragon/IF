//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/initFileBase.h
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

#if (! defined(initFileBase_H_))
# define initFileBase_H_ /* Header guard */

# include <initFileConfig.h>

# include <istream>
# include <memory>
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
    using SpAddressValue = std::shared_ptr<AddressValue>;

    /*! @brief A holder for a shared pointer to an array value. */
    using SpArrayValue = std::shared_ptr<ArrayValue>;

    /*! @brief A holder for a shared pointer to a general value. */
    using SpBaseValue = std::shared_ptr<BaseValue>;

    /*! @brief A holder for a shared pointer to a boolean value. */
    using SpBooleanValue = std::shared_ptr<BooleanValue>;

    /*! @brief A holder for a shared pointer to a double value. */
    using SpDoubleValue = std::shared_ptr<DoubleValue>;

    /*! @brief A holder for a shared pointer to an integer value. */
    using SpIntegerValue = std::shared_ptr<IntegerValue>;

    /*! @brief A holder for a shared pointer to a null value. */
    using SpNullValue = std::shared_ptr<NullValue>;

    /*! @brief A holder for a shared pointer to an object value. */
    using SpObjectValue = std::shared_ptr<ObjectValue>;

    /*! @brief A holder for a shared pointer to a string value. */
    using SpStringValue = std::shared_ptr<StringValue>;

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

        /*! @brief Return @c this if this is an IPv4 address value.
         @return @c this if this is an IPv4 address value. */
		virtual const AddressValue *
		AsAddress
			(void)
			const;

        /*! @brief Return @c this if this is an array value.
         @return @c this if this is an array value. */
		virtual ArrayValue *
		AsArray
			(void);

        /*! @brief Return @c this if this is an array value.
         @return @c this if this is an array value. */
		virtual const ArrayValue *
		AsArray
			(void)
			const;

        /*! @brief Return @c this if this is a boolean value.
         @return @c this if this is a boolean value. */
		virtual BooleanValue *
		AsBoolean
			(void);

        /*! @brief Return @c this if this is a boolean value.
         @return @c this if this is a boolean value. */
		virtual const BooleanValue *
		AsBoolean
			(void)
			const;

        /*! @brief Return @c this if this is a double value.
         @return @c this if this is a double value. */
		virtual DoubleValue *
		AsDouble
			(void);

        /*! @brief Return @c this if this is a double value.
         @return @c this if this is a double value. */
		virtual const DoubleValue *
		AsDouble
			(void)
			const;

        /*! @brief Return @c this if this is an integer value.
         @return @c this if this is an integer value. */
		virtual IntegerValue *
		AsInteger
			(void);

        /*! @brief Return @c this if this is an integer value.
         @return @c this if this is an integer value. */
		virtual const IntegerValue *
		AsInteger
			(void)
			const;

        /*! @brief Return @c this if this is NULL.
         @return @c this if this is NULL. */
		virtual NullValue *
		AsNull
			(void);

        /*! @brief Return @c this if this is NULL.
         @return @c this if this is NULL. */
		virtual const NullValue *
		AsNull
			(void)
			const;

        /*! @brief Return @c this if this is an object.
         @return @c this if this is an object. */
		virtual ObjectValue *
		AsObject
			(void);

        /*! @brief Return @c this if this is an object.
         @return @c this if this is an object. */
		virtual const ObjectValue *
		AsObject
			(void)
			const;

        /*! @brief Return @c this if this is a string.
         @return @c this if this is a string. */
		virtual StringValue *
		AsString
			(void);

        /*! @brief Return @c this if this is a string.
         @return @c this if this is a string. */
		virtual const StringValue *
		AsString
			(void)
			const;

        /*! @brief The destructor. */
        virtual
        ~BaseValue
            (void);

		/*! @brief Return a copy of this value.
		@return A newly allocated copy of this value. */
		virtual SpBaseValue
		Clone
			(void)
			const = 0;

        /*! @brief Return the parent of this value.
         @return The parent of this value. */
		inline SpBaseValue
		GetParent
			(void)
			const
		{
			return fParent;
		} // GetParent

        /*! @brief The copy assignment operator.
         @param[in] other The object to be copied.
         @return The updated object. */
        BaseValue &
        operator =
            (const BaseValue &  other) = delete;

        /*! @brief The move assignment operator.
         @param[in] other The object to be moved.
         @return The updated object. */
        BaseValue &
        operator =
            (BaseValue &&  other)
            noexcept;

        /*! @brief Return @c true if the two values are equal.
         @param[in] other The value to be compared with.
         @return @c true if the two values are comparable and equal. */
        virtual bool
        operator ==
            (const BaseValue &	other)
			const = 0;

        /*! @brief Return @c true if the two values are equal.
         @param[in] other The value to be compared with.
         @return @c true if the two values are comparable and equal. */
        inline bool
        operator !=
            (const BaseValue &	other)
			const
		{
			return (! operator ==(other));
		} // operator !=

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
		inline explicit BaseValue
			(SpBaseValue	parent) :
                fParent{parent}
			{
			} /* constructor */

        /*! @brief The copy constructor.
         @param[in] other The object to be copied. */
        BaseValue
            (const BaseValue &	other);

        /*! @brief The move constructor.
         @param[in] other The object to be moved. */
        BaseValue
            (BaseValue &&	other)
            noexcept;

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

        /*! @brief Set the parent of this value.
		@param[in] newParent The new parent of this value.
         @return The Value that was modified. */
		inline BaseValue &
		SetParent
			(SpBaseValue	newParent)
		{
			fParent = newParent;
			return *this;
		} // SetParent

    private :
        // Private methods.

    public :
        // Public fields.

    protected :
        // Protected fields.

        /*! @brief The parent of this value. */
        SpBaseValue	fParent{};

    private :
        // Private fields.

    }; // BaseValue

    namespace internal_
    {
        /*! @brief A function used to suppress 'unused variable' warnings.
         @tparam Type_ The type of value being ignored. */
        template
            <typename Type_>
        void
        ignore_unused_variable_
            (const Type_ &)
        {
        }

    }; // internal_

/*! @brief Suppress warnings about unused variables. */
# define INITFILE_UNUSED_VAR_(var_)  InitFile::internal_::ignore_unused_variable_(var_)

/*! @brief Convert an arbitrary string into a correctly formatted string.
	@param[in] inString The string to be formatted.
	@result A string with correctly escaped characters and delimiters. */
	std::string
	MakeWrappedString
		(const std::string &    inString);

} // InitFile

#endif /* not initFileBase_H_ */
