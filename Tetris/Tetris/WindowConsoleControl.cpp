#include "WindowConsoleControl.hpp"

void WindowConsoleControl::SETTITLE(const std::string _title)
{
	SETTITLE(std::wstring(begin(_title), end(_title)));
}
void WindowConsoleControl::SETTITLE(const std::wstring _title)
{
	SetConsoleTitle(_title.c_str());
}
void WindowConsoleControl::SETTEXTCOLOR(const WINDOW_CONSOLE_COLOR _fore_color, const WINDOW_CONSOLE_COLOR _back_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(_fore_color) | (static_cast<WORD>(_back_color) << 4));
}
void WindowConsoleControl::SETSIZE(const short _x, const short _y)
{
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);
	MoveWindow(GetConsoleWindow(), r.left, r.top, _x, _y, TRUE);
}
void WindowConsoleControl::CURSORVISIBLE(const bool _visible)
{
	CONSOLE_CURSOR_INFO cur = {1, _visible};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
void WindowConsoleControl::SETPOSITION(const short _x, const short _y)
{
	COORD pos;
	pos.X = _x;
	pos.Y = _y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void WindowConsoleControl::SETFONT(const short _sx, const short _sy, const WCHAR* _fname, const bool _isbold)
{
	CONSOLE_FONT_INFOEX cfi{sizeof(cfi), 0, {_sx, _sy}, FF_DONTCARE, FW_NORMAL};

	if(_isbold)
		cfi.FontWeight = FW_BOLD;
	
	wcscpy_s(cfi.FaceName, _fname);
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void WindowConsoleControl::ClearInputBuffer()
{
	// If you happen to have any trouble clearing already cleared buffer, uncomment the section below.
	/* keybd_event('S', 0, 0, 0);
	keybd_event('S', 0,KEYEVENTF_KEYUP, 0);
	keybd_event(VK_BACK, 0, 0, 0);
	keybd_event(VK_BACK, 0,KEYEVENTF_KEYUP, 0); */
	PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
	DWORD ClearingVar2;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ClearingVar1, 256, &ClearingVar2);
	delete[] ClearingVar1;
}
void WindowConsoleControl::CLEAR()
{
	system("cls");
}