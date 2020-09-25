//===========================================================================
// Lexer definitions:

lexer grammar InitFileLexer;

TRUE_VALUE : [Tt][Rr][Uu][Ee] ;

FALSE_VALUE : [Ff][Aa][Ll][Ss][Ee] ;

NULL_VALUE : [Nn][Uu][Ll][Ll] ;

IPV4_ADDRESS : '@' INT3 '.' INT3 '.' INT3 '.' INT3 ;

fragment INT3 : DIGIT ( DIGIT DIGIT? )? ;

SIGNED_DOUBLE : SIGN? UNSIGNED_DOUBLE ;

UNSIGNED_DOUBLE : INT '.' DIGIT* EXP?
                    | '.' INT EXP?
                    | INT EXP ;

fragment DIGIT : [0-9] ;

fragment INT : DIGIT+ ;

fragment EXP : [Ee] SIGN? INT ;

fragment SIGN : [+\-] ;

SIGNED_INTEGER : SIGN? INT ;

DOUBLE_Q : '"' ;

SINGLE_Q : '\'' ;

STRING1 : DOUBLE_Q ( ESC1 | SAFE_CODE_POINT1 )+ DOUBLE_Q ;

STRING2 : SINGLE_Q ( ESC2 | SAFE_CODE_POINT2 )+ SINGLE_Q ;

STRING3 : DOUBLE_Q DOUBLE_Q ; // empty string, only legal for a value

STRING4 : SINGLE_Q SINGLE_Q ; // empty string, only legal for a value

fragment ESC1 : '\\' ( ["\\/bfnrtv] | UNICODE ) ;

fragment ESC2 : '\\' ( ['\\/bfnrtv] | UNICODE ) ;

fragment UNICODE : 'u' HEX HEX HEX HEX ;

fragment HEX : [0-9a-fA-F] ;

fragment SAFE_CODE_POINT1 : ~ ["\\\u0000-\u001F] ;

fragment SAFE_CODE_POINT2 : ~ ['\\\u0000-\u001F] ;

NAME : [a-zA-Z][a-zA-Z0-9_]* ;

COMMENT_POUND : '#' .*? [\n\r]+ -> skip ;

COMMENT_SLASHES : '//' .*? [\n\r]+ -> skip ;

COMMENT_C_STYLE : '/*' .*? '*/' -> skip ;

OPEN_CURLY : '{' ;

CLOSE_CURLY : '}' ;

OPEN_SQUARE : '[' ;

CLOSE_SQUARE : ']' ;

COMMA : ',' ;

COLON : ':' ;

WS : [ \t\n\r]+ -> skip ;
