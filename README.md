# simple-regexp

int simpleregexp( char * filter, char * str );

Function simpleregexp check if 'str' string matches to 'filter' string. Filter may contain any symbols and '*', '?'. Symbol '*' - replaces any number of any symbols; symbol '?' - replaces one any symbol. String 'str' must not contain '*' and '?'.
