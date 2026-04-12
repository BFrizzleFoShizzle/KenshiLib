
#include "Debug.h"

#include <sstream>
#include <fstream>
#include <ctime>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <intrin.h>
#include <Shlwapi.h>

std::stringstream debugLog;
std::ofstream debugFile("RE_Kenshi_log.txt");
clock_t startTime = -1;

std::string GetModuleName(void* address)
{
	// extract DLL name of caller without extension
	HMODULE module;
	if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)address, &module))
		return "ERROR";
	char modulePath[_MAX_PATH];
	if(GetModuleFileNameA(module, modulePath, sizeof(modulePath)) == 0)
		return "ERROR";
	char* moduleFileName = PathFindFileNameA(modulePath);
	PathRemoveExtensionA(moduleFileName);
	return moduleFileName;
}

static void DebugLog(const std::string& moduleFileName, const std::string& message)
{
	if (startTime == -1)
		startTime = clock();

	clock_t logTime = clock();
	clock_t timeInMSecs = (logTime - startTime) / (CLOCKS_PER_SEC / 1000);

	char timeStr[10];
	sprintf_s(timeStr, "%i.%03i", timeInMSecs / 1000, timeInMSecs % 1000);

	// TODO disable?
	debugFile << timeStr << " " << moduleFileName << ": " << message << std::endl;
	debugLog << timeStr << " " << moduleFileName << ": " << message << std::endl;
}

void DebugLog(const std::wstring& message)
{
	DebugLog(GetModuleName(_ReturnAddress()), std::string(message.begin(), message.end()));
}

void DebugLog(const std::string& message)
{
	DebugLog(GetModuleName(_ReturnAddress()), message);
}

void DebugLog(const char* message)
{
	DebugLog(GetModuleName(_ReturnAddress()), std::string(message));
}

static void ErrorLog(const std::string& moduleFileName, const std::string& message)
{
	if (startTime == -1)
		startTime = clock();

	clock_t logTime = clock();
	clock_t timeInMSecs = (logTime - startTime) / (CLOCKS_PER_SEC / 1000);

	char timeStr[10];
	sprintf_s(timeStr, "%i.%03i", timeInMSecs / 1000, timeInMSecs % 1000);

	debugFile << "Error " << timeStr << " " << moduleFileName << ": " << message << std::endl << std::flush;
	debugLog << "Error " << timeStr << " " << moduleFileName << ": " << message << std::endl;
}

void ErrorLog(const std::wstring& message)
{
	ErrorLog(GetModuleName(_ReturnAddress()), std::string(message.begin(), message.end()));
}

void ErrorLog(const std::string& message)
{
	ErrorLog(GetModuleName(_ReturnAddress()), message);
}

void ErrorLog(const char* message)
{
	ErrorLog(GetModuleName(_ReturnAddress()), std::string(message));
}

std::string GetDebugLog()
{
	return debugLog.str();
}

// stolen from https://www.codeproject.com/tips/479880/getlasterror-as-std-string
// Create a string with last error message
std::string GetLastErrorStdStr()
{
	DWORD error = GetLastError();
	if (error)
	{
		LPVOID lpMsgBuf;
		DWORD bufLen = FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			error,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&lpMsgBuf,
			0, NULL);
		if (bufLen)
		{
			LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
			std::string result(lpMsgStr, lpMsgStr + bufLen);

			LocalFree(lpMsgBuf);

			return result;
		}
	}
	return std::string();
}
