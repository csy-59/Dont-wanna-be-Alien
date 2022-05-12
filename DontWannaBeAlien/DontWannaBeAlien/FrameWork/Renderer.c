#include "Renderer.h"

HANDLE s_consoleHandle;
HANDLE s_screens[2];
int32 s_backIndex;

bool Renderer_Init(void) {
	//1. 콘솔에 대한 핸들을 얻는다.
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == s_consoleHandle) {
		return false;
	}

	//2. 스크린을 만든다.
	for (int32 i = 0; i < 2; i++) {
		s_screens[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	}

	return true;
}

void Renderer_Cleanup(void) {
	CloseHandle(s_consoleHandle);
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}

void clear(HANDLE consoleHandle)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}

void Renderer_Flip(void) {

	// 1. 백 버퍼로 화면을 지정.
	SetConsoleActiveScreenBuffer(s_screens[s_backIndex]);

	// 2. 백 버퍼를 바꿔준다.
	s_backIndex = !s_backIndex; //0이면 1로, 1이면 0으로

	// 3. 백 버퍼에 있는 화면을 지워준다.
	clear(s_screens[s_backIndex]);
}

void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y)
{
	// 1. 백 버퍼에 대한 핸들을 가져온다.
	HANDLE backBuffer = s_screens[s_backIndex];

	// 2. 커서 위치를 옮겨준다.
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 3. 백 버퍼에 텍스트를 출력한다.
	for (int32 i = 0; i < numberOfChar; ++i)
	{
		//각 글자마다 속성이 달라서 따로 출력
		SetConsoleTextAttribute(backBuffer, text[i].Attributes);
		WriteConsole(backBuffer, &text[i].Char, 1, NULL, NULL);
	}
	SetConsoleTextAttribute(backBuffer, TEXT_COLOR_WHITE);
}