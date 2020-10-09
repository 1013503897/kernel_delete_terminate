﻿#include "rtltypes.h"

int _strncmpi_a(const char *s1, const char *s2, size_t cchars)
{
	char c1, c2;

	if ( s1==s2 )
		return 0;

	if ( s1==0 )
		return -1;

	if ( s2==0 )
		return 1;

	if ( cchars==0 )
		return 0;

	do {
		c1 = locase_a(*s1);
		c2 = locase_a(*s2);
		s1++;
		s2++;
		cchars--;
	} while ( (c1 != 0) && (c1 == c2) && (cchars>0) );
	
	return (int)(c1 - c2);
}

int _strncmpi_w(const wchar_t *s1, const wchar_t *s2, size_t cchars)
{
	wchar_t c1, c2;

	if ( s1==s2 )
		return 0;

	if ( s1==0 )
		return -1;

	if ( s2==0 )
		return 1;

	if ( cchars==0 )
		return 0;

	do {
		c1 = locase_w(*s1);
		c2 = locase_w(*s2);
		s1++;
		s2++;
		cchars--;
	} while ( (c1 != 0) && (c1 == c2) && (cchars>0) );
	
	return (int)(c1 - c2);
}
