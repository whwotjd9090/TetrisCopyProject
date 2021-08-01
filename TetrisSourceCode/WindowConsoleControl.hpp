#pragma once
#ifndef WINDOWCONSOLECONTROL_HPP_INCLUDED
#define WINDOWCONSOLECONTROL_HPP_INCLUDED
#include <string>
#include <windows.h>

enum class WINDOW_CONSOLE_COLOR : COLOR16
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
	GRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	LIGHTYELLOW,
	LIGHTWHITE
};

class WindowConsoleControl
{
public:
	static void SETTITLE(const std::string _title);
	static void SETTITLE(const std::wstring _title);
	static void SETTEXTCOLOR(const WINDOW_CONSOLE_COLOR _fore_color, const WINDOW_CONSOLE_COLOR _back_color);
	static void SETSIZE(const short _x, const short _y);
	static void CURSORVISIBLE(const bool _visible);
	static void SETPOSITION(const short _x, const short _y);
	static void SETFONT(const short _sx, const short _sy, const WCHAR* _fname, const bool _isbold);
	static void ClearInputBuffer();
	static void CLEAR();
};

#endif