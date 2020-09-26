//--------------------------------------------------------------------------------------------------
//
//  File:       InitFile/ifString.h
//
//  Project:    IF
//
//  Contains:   The class declaration for InitFile String values.
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

#if (! defined(ifString_H_))
# define ifString_H_ /* Header guard */

# include <ifBase.h>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for %InitFile String values. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace InitFile
{
    /*! @brief A class to provide the base type for String values. */
    class StringValue : public BaseValue
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
		inline StringValue
			(SpBase	        parent,
             const std::string &    value) :
				inherited(parent), fValue(value)
			{
			} /* constructor */

        /*! @brief The destructor. */
        virtual
        ~StringValue
            (void);

        /*! @brief Return @c this if this is a string.
         @return @c this if this is a string. */
		virtual StringValue *
		AsString
			(void)
            override;

        /*! @brief Return the content of this value.
         @return The content of this value. */
		inline std::string
		GetValue
			(void)
			const
		{
			return fValue;
		} // GetValue

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
		std::string fValue;

    }; // StringValue

} // InitFile

#endif /* not ifString_H_ */
