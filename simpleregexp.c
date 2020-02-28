/******************************************************************************/
/* SIMPLE-REGEXP FUNCTION                                                     */
/* (c) Mashkin S.V.                                                           */
/******************************************************************************/

#include "mylog.h"
#include "simpleregexp.h"
#include <stdlib.h>

//------------------------------------------------------------------------------
static int priv_compare( char * filter, char * str, int ast );

//DESCRIPTION:
//Kernel part of function simpleregexp
//
//NOTE:
//     filter may contain any symbols and '*', '?'
//     '*' - replaces any number of any symbols
//     '?' - replaces one any symbol
//     str must not contain '*' and '?'
//INPUTS:
//     filter
//     str
//     ast = previous checked symbol was '*'
//RETURNS:
//     1 = str matches to filter (current partly check)
//     0 = str does not match to filter (current partly check)

static int priv_compare( char * filter, char * str, int ast )
{
    char * f;
    char * s;

    MYLOG_TRACE("@(filter=%s,str=%s,ast=%d)",filter,str,ast);

    if(filter==NULL) {
        MYLOG_ERROR("invalid argument: filter=NULL");
        return 0;
    }
    if(str==NULL) {
        MYLOG_ERROR("invalid argument: str=NULL");
        return 0;
    }

    f = filter;
    s = str;

    if(f[0]=='*') {
        if( priv_compare(f+1,s,1)==1 )
            return 1;
        while(*s != '\0') {
            if( priv_compare(f+1,s,1)==1 )
                return 1;
            s++;
        }
        return 0;
    }
    else if(f[0]=='?') {
        if(s[0]=='\0')
            return 0;
        else
            return priv_compare(f+1,s+1,0);
    }
    else if(f[0]=='\0') {
        if(s[0]=='\0')
            return 1;
        else {
            if(ast)
                return priv_compare(f,s+1,ast);
            else
                return 0;
        }
    }
    else {
        if(f[0]==s[0]) {
            return priv_compare(f+1,s+1,0);
        }
        else {
            return 0;
        }
    }
}

//------------------------------------------------------------------------------
//DESCRIPTION:
//Function simpleregexp check if 'str' string matches to 'filter' string
//
//NOTE:
//     filter may contain any symbols and '*', '?'
//     '*' - replaces any number of any symbols
//     '?' - replaces one any symbol
//     str must not contain '*' and '?'
//EXAMPLES:
//     simpleregexp("*",    "12345") returns 1
//     simpleregexp("*34*", "12345") returns 1
//     simpleregexp("*34",  "12345") returns 0
//     simpleregexp("*3?4*","12345") returns 0
//     simpleregexp("*3*4*","12345") returns 1
//     simpleregexp("34",   "12345") returns 0
//     simpleregexp("*2??5","12345") returns 1
//     ...
//RETURNS:
//     1 = str matches to filter
//     0 = str does not match to filter

int simpleregexp( char * filter, char * str )
{
    MYLOG_TRACE("@(filter=%s,str=%s)",filter,str);

    return priv_compare(filter,str,0);
}

