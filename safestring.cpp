/* Copyright is waived. No warranty is provided. Unrestricted use and modification is permitted. */

#include <cstdio>		// sprintf_s, vsnprintf_s
#include <cstdarg>		// va_start
#include <cstring>		// strlen etc.
#include <locale>
#include "safestring.h"

static const wchar_t* days_w[] = {L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat"};
static const wchar_t* months_w[] = {L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun", L"Jul", L"Aug", L"Sep", L"Oct", L"Nov", L"Dec"};


size_t strtowcs (wchar_t* dst, const char* src, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;
	if (!src)
	{
		*dst=0;
		return 0;
	}

	// Copy the string
	wchar_t* start = dst;
	while (*src && count)
	{
		*dst++ = (wchar_t) *src++;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the string
	return dst - start;
}


size_t wcstostr (char* dst, const wchar_t* src, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;
	if (!src)
	{
		*dst=0;
		return 0;
	}

	// Copy the string
	char* start = dst;
	while (*src && count)
	{
		*dst++ = (char) *src++;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the string
	return dst - start;
}


size_t strlcpy (char* dst, const char* src, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;
	if (!src)
	{
		*dst=0;
		return 0;
	}

	// Copy the string
	char* start=dst;
	while (*src && count)
	{
		*dst++ = *src++;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the string
	return dst - start;
}


size_t wcslcpy(wchar_t* dst, const wchar_t* src, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;
	if (!src)
	{
		*dst = 0;
		return 0;
	}

	// Copy the string
	wchar_t* start = dst;
	while (*src && count)
	{
		*dst++ = *src++;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the string
	return dst - start;
}


size_t strlcat (char* dst, const char* src, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;

	// Find the end of the existing string in the destination buffer
	char* start = dst;
	while (*dst && count)
	{
		dst++;
		count--;
	}

	// Exit if there is nothing to copy
	if ((!src) || (!count))
	{
		return (int) (dst-start);
	}

	// Append the source string
	while (*src && count)
	{
		*dst++ = *src++;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the full string
	return dst - start;
}


size_t wcslcat(wchar_t* dst, const wchar_t* src, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;

	// Find the end of the existing string in the destination buffer
	wchar_t* start = dst;
	while (*dst && count)
	{
		dst++;
		count--;
	}

	// Exit if there is no source string or no more room in the destination buffer
	if ((!src) || (!count))
	{
		return dst - start;
	}

	// Append the source string
	while (*src && count)
	{
		*dst++ = *src++;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the full string
	return dst - start;
}


size_t strlncpy (char* dst, const char* src, size_t nchars, size_t count)
{
	// Validate parameters
	if (!count)  return 0;
	if (!dst)    return 0;
	if ((!src) ||(!nchars))
	{
		*dst=0;
		return 0;
	}

	// Copy the string
	char* start = dst;
	while (*src && nchars && count)
	{
		*dst++ = *src++;
		nchars--;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the string
	return dst - start;
}


size_t wcslncpy(wchar_t* dst, const wchar_t* src, size_t nchars, size_t count)
{
	// Validate parameters
	if (!count)  return 0;
	if (!dst)    return 0;
	if ((!src) || (!nchars))
	{
		*dst = 0;
		return 0;
	}

	// Copy the string
	wchar_t* start = dst;
	while (*src && nchars && count)
	{
		*dst++ = *src++;
		nchars--;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the string
	return dst - start;
}


size_t strlncat (char* dst, const char* src, size_t nchars, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;

	// Find the end of the existing string in the destination buffer
	char* start = dst;
	while (*dst && count)
	{
		dst++;
		count--;
	}

	// Exit if there is nothing to copy
	if ((!src) || (!nchars) || (!count))
	{
		return (int) (dst-start);
	}

	// Append the source string
	while (*src && nchars && count)
	{
		*dst++ = *src++;
		nchars--;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the full string
	return dst - start;
}


size_t wcslncat(wchar_t* dst, const wchar_t* src, size_t nchars, size_t count)
{
	// Validate parameters
	if (!count) return 0;
	if (!dst)   return 0;

	// Find the end of the existing string in the destination buffer
	wchar_t* start = dst;
	while (*dst && count)
	{
		dst++;
		count--;
	}

	// Exit if there is nothing to copy
	if ((!src) || (!nchars) || (!count))
	{
		return dst - start;
	}

	// Append the source string
	while (*src && nchars && count)
	{
		*dst++ = *src++;
		nchars--;
		count--;
	}

	// Terminate the string (truncates last character if buffer is full)
	if (count == 0) dst--;
	*dst = 0;

	// Return the length of the full string
	return dst - start;
}


char* strlstr(const char* string, size_t length, const char* substring)
{
	for (size_t i = 0; i < length; i++)
	{
		size_t j = 0;
		while (substring[j] && (substring[j] == string[i + j])) j++;
		if (substring[j] == 0) return (char*)&string[i];
	}

	return nullptr;
}


wchar_t* wcslstr(const wchar_t* string, size_t length, const wchar_t* substring)
{
	for (size_t i = 0; i < length; i++)
	{
		size_t j = 0;
		while (substring[j] && (substring[j] == string[i + j])) j++;
		if (substring[j] == 0) return (wchar_t*)&string[i];
	}

	return nullptr;
}


char* strlrstr(const char* string, size_t length, const char* substring)
{
	size_t substring_length = strlen(substring);
	for (size_t i = length-1; i >= substring_length; i--)
	{
		size_t j = substring_length;
		while (j >= 0 && (substring[j] == string[i - substring_length + j])) j--;
		if (j < 0) return (char*)&string[i - substring_length];
	}

	return nullptr;
}


wchar_t* wcslrstr(const wchar_t* string, size_t length, const wchar_t* substring)
{
	size_t substring_length = wcslen(substring);
	for (size_t i = length - 1; i >= substring_length; i--)
	{
		size_t j = substring_length;
		while (j >= 0 && (substring[j] == string[i - substring_length + j])) j--;
		if (j < 0) return (wchar_t*)&string[i - substring_length];
	}

	return nullptr;
}


int strltoken(char* string, size_t length, const char* delimiter)
{
	char* end = strlstr(string, length, delimiter);
	if (end == nullptr) return -1;
	*end = 0;
	return (int)((intptr_t)end - (intptr_t)string);
}


int wcsltoken(wchar_t* string, size_t length, const wchar_t* delimiter)
{
	wchar_t* end = wcslstr(string, length, delimiter);
	if (end == nullptr) return -1;
	*end = 0;
	return (int)((intptr_t)end - (intptr_t)string);
}


int strlenum(char* string, size_t length, const char* enumeration[], size_t count)
{
	for (int i = 0; i < count; i++)
	{
		const char* item = enumeration[i];
		if (strncmp(string, item, length) == 0) return i;
	}

	return -1;
}


int wcslenum(wchar_t* string, size_t length, const wchar_t* enumeration[], size_t count)
{
	for (int i = 0; i < count; i++)
	{
		const wchar_t* item = enumeration[i];
		if (wcsncmp(string, item, length) == 0) return i;
	}

	return -1;
}


int slprintf (char* dst, size_t count, const char* format, ...)
{
	// It's okay to call this function with a count of 0, we just exit
	if (!count) return 0;

	// Create argument list and call formatting function
	va_list  argptr;
	va_start (argptr, format);
	int length = vsnprintf_s (dst, (size_t) count, _TRUNCATE, format, argptr);

	// If the destination buffer was filled then calculate the length of the truncated string
	if (length == -1)
	{
		length = (int) count-1;
	}

	// Return number of characters written to buffer. If this is less than the
	// 'count' parameter passed then the user will know that the string was truncated.
	return length;
}


int vslprintf (char* dst, size_t count, const char* format, va_list argptr)
{
	// It's okay to call this function with a count of 0, we just exit
	if (!count) return 0;

	// Call formatting function
	int length = vsnprintf_s (dst, (size_t) count, _TRUNCATE, format, argptr);

	// If the destination buffer was filled then calculate the length of the truncated string
	if (length == -1)
	{
		length = (int) count-1;
	}

	// Return number of characters written to buffer. If this is less than the
	// 'count' parameter passed then the user will know that the string was truncated.
	return length;
}


int slwprintf (wchar_t* dst, size_t count, const wchar_t* format, ...)
{
	// It's okay to call this function with a count of 0, we just exit
	if (!count) return 0;

	// Create argument list and call formatting function
	#undef _vsnwprintf
	va_list  argptr;
	va_start (argptr, format);
	int length = _vsnwprintf_s (dst, (size_t) count, _TRUNCATE, format, argptr);

	// If the destination buffer was filled then calculate the length of the truncated string
	if (length == -1)
	{
		length = (int)count - 1;
	}

	// Return number of characters written to buffer. If this is less than the
	// 'count' parameter passed then the user will know that the string was truncated.
	return length;
}


int vslwprintf (wchar_t* dst, size_t count, const wchar_t* format, va_list argptr)
{
	// It's okay to call this function with a count of 0, we just exit
	if (!count) return 0;

	// Call formatting function
	int length = _vsnwprintf_s (dst, (size_t) count, _TRUNCATE, format, argptr);

	// If the destination buffer was filled then calculate the length of the truncated string
	if (length == -1)
	{
		length = (int) count-1;
	}

	// Return number of characters written to buffer. If this is less than the
	// 'count' parameter passed then the user will know that the string was truncated.
	return length;
}


char strlast (const char* src)
{
	int length = (int) strlen(src);
	if (length == 0) return 0;
	else             return src[length-1];
}


wchar_t wcslast (const wchar_t* src)
{
	int length = (int) wcslen(src);
	if (length == 0) return 0;
	else             return src[length-1];
}


bool atob (const char* str)
{
	// If the string is NULL return false
	if (!str) return false;

	// If the string is '1' or 'true' then return true
	if (_stricmp (str, "1")    == 0) return true;
	if (_stricmp (str, "true") == 0) return true;

	// Anything else returns false
	return false;
}


bool wtob (const wchar_t* str)
{
	// If the string is NULL return false
	if (!str) return false;

	// If the string is '1' or 'true' then return true
	if (_wcsicmp (str, L"1")    == 0) return true;
	if (_wcsicmp (str, L"true") == 0) return true;

	// Anything else returns false
	return false;
}


// Hash a string with FNV1a
int strhash(const char* string)
{
	unsigned int hash = 0x811c9dc5;
	while (*string)
	{
		hash ^= *string++;
		hash *= 0x01000193;
	}

	return (int)hash;
}


// Hash a wide string with FNV1a
int wcshash(const wchar_t* string)
{
	unsigned int hash = 0x811c9dc5;
	while (*string)
	{
		wchar_t value = *string++;
		hash ^= value & 0xff;
		hash *= 0x01000193;
		hash ^= value >> 8;
		hash *= 0x01000193;
	}

	return (int)hash;
}


void scvt(long long size, char* buffer, size_t count)
{
	const char* postfix;
	float divisor;
	if (size < 1024 * 1024)
	{
		postfix = "KB";
		divisor = 1024.0f;
	}
	else if (size < 1024 * 1024 * 1024)
	{
		postfix = "MB";
		divisor = 1048576.0f;
	}
	else
	{
		postfix = "GB";
		divisor = 1073741824.0f;
	}

	float num = (float)size / divisor;
	sprintf_s(buffer, (size_t)count, "%.2f%s", num, postfix);
}


void swcvt(long long size, wchar_t* buffer, size_t count)
{
	const wchar_t* postfix;
	float divisor;
	if (size < 1024 * 1024)
	{
		postfix = L"KB";
		divisor = 1024.0f;
	}
	else if (size < 1024 * 1024 * 1024)
	{
		postfix = L"MB";
		divisor = 1048576.0f;
	}
	else
	{
		postfix = L"GB";
		divisor = 1073741824.0f;
	}

	float num = (float)size / divisor;
	swprintf_s(buffer, (size_t)count, L"%.2f%s", num, postfix);
}


void wcs_epoch_ISO8601(wchar_t* buffer, size_t length)
{
    std::time_t time = std::time(nullptr);
    std::tm tm;
    gmtime_s(&tm, &time);
    slwprintf(buffer, length, L"%04u%02u%02uT%02u%02u%02uZ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}


void wcs_epoch_RFC1123(wchar_t* buffer, size_t length)
{
    std::time_t time = std::time(nullptr);
    std::tm tm;
    gmtime_s(&tm, &time);
    const wchar_t* day = days_w[tm.tm_wday];
    const wchar_t* month = months_w[tm.tm_mon];
    slwprintf(buffer, length, L"%s, %02u %s %04u %02u:%02u:%02u GMT", day, tm.tm_mday, month, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
