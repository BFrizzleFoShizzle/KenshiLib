#pragma once

#include "Defines.h"

#include <string>

KLIB_EXPORT void DebugLog(const std::wstring& message);
KLIB_EXPORT void DebugLog(const std::string& message);
KLIB_EXPORT void DebugLog(const char* message);
KLIB_EXPORT void ErrorLog(const std::wstring& message);
KLIB_EXPORT void ErrorLog(const std::string& message);
KLIB_EXPORT void ErrorLog(const char* message);
KLIB_EXPORT std::string GetDebugLog();

// returns string containing WINAPI GetLastError()
KLIB_EXPORT std::string GetLastErrorStdStr();
std::string GetModuleName(void* address);
