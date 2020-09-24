# IF
InitFile is a JSON derivative for loading initial values into an application.

## JSON extensions

As a JSON extension, the following additions have been made:

* Tags can be quoted using either double or single quotes or, they can be unquoted if they do not contain embedded whitespace
* Tags are case-insensitive
* String values can be quoted with either double or single quotes or they can be unquoted if they do not contain embedded whitespace
* Literal values (`true`, `false` and `null`) are case-insensitive
* The last pair in an object can be followed by a comma
* The last value in an array can be followed by a comma
* Comments can be present
  * C++-style comments are supported (`//` and `/* */`)
  * A semicolon comment (`;`) extends from the semicolon to the end-of-line
* IPv4 values are in the form (`@###.###.###.###`) where `#` indicates a decimal digit; fewer than three digits can appear in each segment of the address
