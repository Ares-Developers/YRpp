#ifndef HELPER_OTHER_H
#define HELPER_OTHER_H

#include <cmath>
#include <vector>
#include <algorithm>

#include <Dbghelp.h>

#define MID(x) \
	((((x) / 256) * 256) + 128 )

#define XCMP(a, b, v) \
	((v) < 0) ? ((a) >= MID(b)) : (MID(b) >= (a))

#define SCALE(x, v) \
	((v) < 0) ? (MID(x)) : (MID(x))

class XY : public CoordStruct {
public:
	XY(int _x, int _y) {
		X = _x;
		Y = _y;
		Z = 0;
	}

	XY(CoordStruct *crd) {
		X = crd->X;
		Y = crd->Y;
		Z = 0;
	}

	bool operator< (const XY& RHS) {
		if(X > RHS.X) {
			return false;
		}
		if(X == RHS.X) {
			return Y < RHS.Y;
		}
		return true;
	}

	void normalize() {
		X = MID(X);
		Y = MID(Y);
	}
};

class Trajectory {
	XY st;
	XY en;

	int dirX;
	int dirY;

public:
	typedef std::vector<XY> vec;

	Trajectory(XY &s, XY &e)
		: st(s), en(e)
	{
		dirX = st.X < en.X ? 1 : -1;
		dirY = st.Y < en.Y ? 1 : -1;
	}

	Trajectory(int stx, int sty, int enx, int eny)
		: st(stx, sty), en(enx, eny)
	{
		dirX = st.X < en.X ? 1 : -1;
		dirY = st.Y < en.Y ? 1 : -1;
	}

	void path(std::vector<XY> &hitCoords) {
		hitCoords.clear();

		if(MID(st.X) != MID(en.X)) {
			walkX(hitCoords);
		}

		if(MID(st.Y) != MID(en.Y)) {
			walkY(hitCoords);
		}

		std::sort(hitCoords.begin(), hitCoords.end());

		hitCoords.erase(std::unique(hitCoords.begin(), hitCoords.end()), hitCoords.end());
	}

private:
	void walkX(std::vector<XY> &hitCoords) {
		int step = dirX * 256;
		for(int step_x = SCALE(st.X, dirX); XCMP(step_x, en.X, dirX); step_x += step) {
			int step_y = st.Y + int(dirY * stepY(step_x));
			XY temp(step_x, step_y);
			temp.normalize();
			hitCoords.push_back(temp);
		}
	}

	void walkY(std::vector<XY> &hitCoords) {
		int step = dirY * 256;
		for(int step_y = SCALE(st.Y, dirY); XCMP(step_y, en.Y, dirY); step_y += step) {
			int step_x = st.X + int(dirX * stepX(step_y));
			XY temp(step_x, step_y);
			temp.normalize();
			hitCoords.push_back(temp);
		}
	}

	double _tg() {
		return (abs(en.Y - st.Y) * 1.0) / abs(en.X - st.X);
	}

	double stepX(int Y) {
		return (abs(st.Y - Y) / _tg());
	}

	double stepY(int X) {
		return (abs(st.X - X) * _tg());
	}
};


/**
 * minidump
 */

/*
bool g_ExtendedMinidumps = false;
LONG WINAPI ExceptionHandler(int code, LPEXCEPTION_POINTERS pExs)
{
//	if (IsDebuggerAttached()) return EXCEPTION_CONTINUE_SEARCH;
	if (pExs->ExceptionRecord->ExceptionCode == ERROR_MOD_NOT_FOUND ||
		pExs->ExceptionRecord->ExceptionCode == ERROR_PROC_NOT_FOUND)
	{
		//tell user
		ExitProcess(pExs->ExceptionRecord->ExceptionCode);
	}

	switch(pExs->ExceptionRecord->ExceptionCode)
	{
		case EXCEPTION_ACCESS_VIOLATION:
		case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
		case EXCEPTION_BREAKPOINT:
		case EXCEPTION_DATATYPE_MISALIGNMENT:
		case EXCEPTION_FLT_DENORMAL_OPERAND:
		case EXCEPTION_FLT_DIVIDE_BY_ZERO:
		case EXCEPTION_FLT_INEXACT_RESULT:
		case EXCEPTION_FLT_INVALID_OPERATION:
		case EXCEPTION_FLT_OVERFLOW:
		case EXCEPTION_FLT_STACK_CHECK:
		case EXCEPTION_FLT_UNDERFLOW:
		case EXCEPTION_ILLEGAL_INSTRUCTION:
		case EXCEPTION_IN_PAGE_ERROR:
		case EXCEPTION_INT_DIVIDE_BY_ZERO:
		case EXCEPTION_INT_OVERFLOW:
		case EXCEPTION_INVALID_DISPOSITION:
		case EXCEPTION_NONCONTINUABLE_EXCEPTION:
		case EXCEPTION_PRIV_INSTRUCTION:
		case EXCEPTION_SINGLE_STEP:
		case EXCEPTION_STACK_OVERFLOW:
		{
			wchar_t filename[MAX_PATH];
			wchar_t path[MAX_PATH];
		
			HANDLE dumpFile;
			SYSTEMTIME time;
			MINIDUMP_EXCEPTION_INFORMATION expParam;
			
			GetLocalTime(&time);
			GetCurrentDirectoryW(MAX_PATH, path);

			swprintf(filename, MAX_PATH, L"%s\\debug", path);
			CreateDirectoryW(filename, NULL);

			swprintf(filename, MAX_PATH, g_ExtendedMinidumps ? L"%s\\debug\\extcrashdump.%04u%02u%02u-%02u%02u%02u.dmp" : L"%s\\debug\\crashdump.%04u%02u%02u-%02u%02u%02u.dmp", 
							path, 
							time.wYear, time.wMonth, time.wDay, 
							time.wHour, time.wMinute, time.wSecond);

			dumpFile = CreateFileW(filename, GENERIC_READ | GENERIC_WRITE, 
							FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL);

			expParam.ThreadId = GetCurrentThreadId();
			expParam.ExceptionPointers = pExs;
			expParam.ClientPointers = FALSE;

			MINIDUMP_TYPE type = (MINIDUMP_TYPE) ((g_ExtendedMinidumps ? MiniDumpWithFullMemory : (MiniDumpWithDataSegs | MiniDumpWithIndirectlyReferencedMemory)));
				
			MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFile, type, &expParam, NULL, NULL);
			CloseHandle(dumpFile);

			// FIXME FIXME FIXME
			// Shiny dialog explaining that something went horribly wrong and 
			// that we need the crashdumps to fix it
			// Following message is placeholder
			MessageBoxW(NULL, 
			L"Yuri's Revenge has encountered an internal error and is unable to continue normally.\n"
			L"A crash dump should have been created in your game's \\debug subfolder. If you wish to report this bug to the developers, be sure to include that file.",
				L"Command and Conquer: Yuri's Revenge - Internal Error", MB_ICONERROR | MB_OK | MB_SETFOREGROUND);

			ExitProcess(pExs->ExceptionRecord->ExceptionCode); // Exit Renegade.
			break;
		}
		default:
			return EXCEPTION_CONTINUE_SEARCH;
			break;
	}
}
*/

#endif
