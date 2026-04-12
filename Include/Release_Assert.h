#include "Debug.h"
#include <crtdefs.h>

// defines assert_release() without defining assert()
extern "C" {
	_CRTIMP void __cdecl _wassert(_In_z_ const wchar_t* _Message, _In_z_ const wchar_t* _File, _In_ unsigned _Line);
}
#define STRINGIZE(x) STRINGIZE2(x)
#define STRINGIZE2(x) #x
#define LINE_STRING STRINGIZE(__LINE__)

#define assert_release_1(expression) \
	((!!(expression)) \
	|| (ErrorLog(std::string("Assertion failed: ") + #expression + " in " + __FILE__ + " line: " + LINE_STRING), 0) \
	|| (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0))

#define assert_release_2(expression, message) \
	((!!(expression)) \
	|| (ErrorLog(std::wstring(L"Assertion failed: ") + message + L" in " + _CRT_WIDE(__FILE__) + L" line: " + _CRT_WIDE(LINE_STRING)), 0) \
	|| (_wassert((std::wstring(message) + L"\n" + _CRT_WIDE(#expression) + L"\n").c_str(), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0))

// Source - https://stackoverflow.com/a/11763277
// Posted by netcoder, modified by community. See post 'Timeline' for change history
// Retrieved 2026-04-12, License - CC BY-SA 4.0
#define EXPAND(x)                           x
#define GET_MACRO(_1, _2, name, ...)    name
#define assert_release(...)    EXPAND( GET_MACRO(__VA_ARGS__, assert_release_2, assert_release_1)(__VA_ARGS__) )
