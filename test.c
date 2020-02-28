/******************************************************************************/
/* SIMPLE-REGEXP FUNCTION TEST                                                */
/* (c) Mashkin S.V.                                                           */
/******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#include "mylog.h"
#include "simpleregexp.h"

//=============================================================================

int main( void )
{
    char *flt;
    char *str;
    int   result;
    printf("started\n");

    flt    = "*";
    str    = "75376853765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "****";
    str    = "75376853765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "????????????";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "???????????";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "??????????";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*?";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "?*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "?*?";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*???????????";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "???????????*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "???7??33???";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "???7??34???";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "753*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "754*";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*765";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*765*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*755";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*768*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*6*8*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*6?8*";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*7*5";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*7?5*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "75376833765";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*75376833765";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "75376833765*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*75376833765*";
    str    = "75376833765";
    result = 1;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    flt    = "*753768337658*";
    str    = "75376833765";
    result = 0;
    printf("simpleregexp(\"%s\",\"%s\")=%d (must be %d)\n", flt, str, simpleregexp(flt,str), result );

    printf("finished\n");
    return 0;
}
