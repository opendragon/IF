//===========================================================================
// Lexer definitions:

lexer grammar InitFileLexer;

TRUE : [Tt][Rr][Uu][Ee] ;

FALSE : [Ff][Aa][Ll][Ss][Ee] ;

NULL_VALUE : [Nn][Uu][Ll][Ll] ;

IPV4_ADDRESS : '@' INT3 '.' INT3 '.' INT3 '.' INT3 ;

fragment INT3 : [0-9]([0-9][0-9]?)? ;

// ###.###[E###]
// .####[E###]
// ###E###
SIGNED_DOUBLE : [-+]? UNSIGNED_DOUBLE ;

UNSIGNED_DOUBLE : INT '.' [0-9]* EXP? | '.' INT EXP? | INT EXP ;

fragment INT : [0-9]+ ;

fragment EXP : [Ee] [+\-]? INT ;

SIGNED_INTEGER : [-+]? INT ;

STRING1 : '"' ( ESC1 | SAFE_CODE_POINT1 )+ '"' ;

STRING2 : '\'' ( ESC2 | SAFE_CODE_POINT2 )+ '\'';

STRING3 : '"' '"' ; // empty string, only legal for a value

STRING4 : '\'' '\'' ; // empty string, only legal for a value

fragment ESC1 : '\\' ( ["\\/bfnrt] | UNICODE ) ;

fragment ESC2 : '\\' ( ['\\/bfnrt] | UNICODE ) ;

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
