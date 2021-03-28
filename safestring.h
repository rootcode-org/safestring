/* Copyright is waived. No warranty is provided. Unrestricted use and modification is permitted. */

#pragma once
#include <cstdlib>

// Ascii/Wide string conversions
size_t strtowcs (wchar_t* dst, const char*    src, size_t count);						// Convert an ascii string to a wide string
size_t wcstostr (char*    dst, const wchar_t* src, size_t count);						// Convert a wide string to an ascii string

// Safe string copy, append and formatting functions
size_t strlcpy    (char* dst, const char* src, size_t count);							 // Copy ascii string
size_t strlcat    (char* dst, const char* src, size_t count);							 // Append ascii string
size_t strlncpy   (char* dst, const char* src, size_t nchars, size_t count);			 // Copy N characters of an ascii string
size_t strlncat   (char* dst, const char* src, size_t nchars, size_t count);			 // Append N characers of an ascii string
char*  strlstr    (const char* string, size_t length, const char* substring);			 // Search for substring
char*  strlrstr   (const char* string, size_t length, const char* substring);			 // Search backwards for substring
int    strltoken  (char* string, size_t length, const char* delimiter);					 // Search for substring and tokenize
int    strlenum   (char* string, size_t length, const char* enumeration[], size_t count);// Find string in an array of strings
int    slprintf   (char* dst, size_t count, const char* format, ...);					 // Safe sprintf
int    vslprintf  (char* dst, size_t count, const char* format, va_list vararg);		 // Safe vsprintf

size_t   wcslcpy    (wchar_t* dst, const wchar_t* src, size_t count);							 // Copy wide string
size_t   wcslcat    (wchar_t* dst, const wchar_t* src, size_t count);							 // Append wide string
size_t   wcslncpy   (wchar_t* dst, const wchar_t* src, size_t nchars, size_t count);			 // Copy N characters of a wide string
size_t   wcslncat   (wchar_t* dst, const wchar_t* src, size_t nchars, size_t count);			 // Append N characers of a wide string
wchar_t* wcslstr    (const wchar_t* string, size_t length, const wchar_t* substring);			 // Search for substring
wchar_t* wcslrstr   (const wchar_t* string, size_t length, const wchar_t* substring);			 // Search backwards for substring
int		 wcsltoken  (wchar_t* string, size_t length, const wchar_t* delimiter);					 // Search for substring and tokenize
int      wcslenum   (wchar_t* string, size_t length, const wchar_t* enumeration[], size_t count);// Find string in an array of strings
int      slwprintf  (wchar_t* dst, size_t count, const wchar_t* format, ...);					 // Safe swprintf
int      vslwprintf (wchar_t* dst, size_t count, const wchar_t* format, va_list vararg);		 // Safe vswprintf

// Additional useful string functions
char    strlast (const char*    src);								// Return the last character in an ascii string
wchar_t wcslast (const wchar_t* src);								// Return the last character in a wide string
bool    atob    (const char*    str);								// Ascii to bool i.e. "true" or "1" returns true, anything else returns false
bool    wtob    (const wchar_t* str);								// Wide ascii to bool i.e. "true" or "1" returns true, anything else returns false
int     strhash (const char* string);								// Generate 32-bit FNV1a hash of ascii string
int     wcshash (const wchar_t* string);							// Generate 32-bit FNV1a hash of ascii string
void    scvt    (long long size, char*    buffer, size_t count);	// Convert a size value to a human-readable ascii string e.g. 3328 converts to "3.25KB"
void    swcvt   (long long size, wchar_t* buffer, size_t count);	// Convert a size value to a human-readable wide string  e.g. 3328 converts to L"3.25KB"
const size_t SCVT_MAX = 17;											// Maximum length of string returned by scvt() including terminator

// For now just have wide versions of these functions
void wcs_epoch_ISO8601(wchar_t* buffer, size_t length);
void wcs_epoch_RFC1123(wchar_t* buffer, size_t length);

// Generic text mappings for the safe string functions
#if defined(_UNICODE)
#define _tcslcpy    wcslcpy
#define _tcslcat    wcslcat
#define _tcslncpy   wcslncpy
#define _tcslncat   wcslncat
#define _tcslstr    wcslstr
#define _sltprintf  slwprintf
#define _vsltprintf vslwprintf
#define _tstob      wtob
#define _tcslast    wcslast
#define _tcshash    wcshash
#define _tcshash64  wcshash64
#define _tcvt       swcvt
#else
#define _tcslcpy    strlcpy
#define _tcslcat    strlcat
#define _tcslncpy   strlncpy
#define _tcslncat   strlncat
#define _tcslstr    strlstr
#define _sltprintf  slprintf
#define _vsltprintf vslprintf
#define _tstob      atob
#define _tcslast    strlast
#define _tcshash    strhash
#define _tcshash64  strhash64
#define _tcvt       scvt
#endif

