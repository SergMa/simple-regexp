# simple-regexp

DESCRIPTION:
Function simpleregexp check if 'str' string matches to 'filter' string

NOTE:
     filter may contain any symbols and '*', '?'
     '*' - replaces any number of any symbols
     '?' - replaces one any symbol
     str must not contain '*' and '?'
EXAMPLES:
     simpleregexp("*",    "12345") returns 1
     simpleregexp("*34*", "12345") returns 1
     simpleregexp("*34",  "12345") returns 0
     simpleregexp("*3?4*","12345") returns 0
     simpleregexp("*3*4*","12345") returns 1
     simpleregexp("34",   "12345") returns 0
     simpleregexp("*2??5","12345") returns 1
     ...
RETURNS:
     1 = str matches to filter
     0 = str does not match to filter

int simpleregexp( char * filter, char * str );

