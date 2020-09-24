//===========================================================================
// Parser definitions:

parser grammar InitFileParser;

options
    {
        tokenVocab=InitFileLexer;
    }

configuration : object EOF
                | array EOF
;

object : OPEN_CURLY pair ( COMMA pair )* COMMA? CLOSE_CURLY # nonEmptyObject
            | OPEN_CURLY CLOSE_CURLY                        # emptyObject
;

pair : tag COLON value ;

tag : dq=STRING1 | sq=STRING2 | na=NAME ;

value : stringValue
        | doubleValue
        | integerValue
        | object
        | array
        | literalValue
        | addressValue
;

addressValue : add=IPV4_ADDRESS ;

stringValue : dq=STRING1 | sq=STRING2 | na=NAME | edq=STRING3 | esq=STRING4 ;

doubleValue : nu=SIGNED_DOUBLE ;

integerValue : nu=SIGNED_INTEGER ;

literalValue : tv=TRUE | fv=FALSE | nv=NULL_VALUE ;

array : OPEN_SQUARE value ( COMMA value )* COMMA? CLOSE_SQUARE  # nonEmptyArray
        | OPEN_SQUARE CLOSE_SQUARE                              # emptyArray
;
