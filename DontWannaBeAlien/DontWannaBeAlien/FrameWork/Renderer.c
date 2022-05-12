#include "Renderer.h"

HANDLE s_consoleHandle;
HANDLE s_screens[2];
int32 s_backIndex;

bool Renderer_Init(void) {
	//1. �ֿܼ� ���� �ڵ��� ��´�.
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == s_consoleHandle) {
		return false;
	}

	//2. ��ũ���� �����.
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

	// 1. �� ���۷� ȭ���� ����.
	SetConsoleActiveScreenBuffer(s_screens[s_backIndex]);

	// 2. �� ���۸� �ٲ��ش�.
	s_backIndex = !s_backIndex; //0�̸� 1��, 1�̸� 0����

	// 3. �� ���ۿ� �ִ� ȭ���� �����ش�.
	clear(s_screens[s_backIndex]);
}

void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y)
{
	// 1. �� ���ۿ� ���� �ڵ��� �����´�.
	HANDLE backBuffer = s_screens[s_backIndex];

	// 2. Ŀ�� ��ġ�� �Ű��ش�.
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 3. �� ���ۿ� �ؽ�Ʈ�� ����Ѵ�.
	for (int32 i = 0; i < numberOfChar; ++i)
	{
		//�� ���ڸ��� �Ӽ��� �޶� ���� ���
		SetConsoleTextAttribute(backBuffer, text[i].Attributes);
		WriteConsole(backBuffer, &text[i].Char, 1, NULL, NULL);
	}
	SetConsoleTextAttribute(backBuffer, TEXT_COLOR_WHITE);
}