#pragma once

#include "Common.h"

//각 글자마다의 속성(폰트색, 배경색 등)을 함께 넣어두는 구조체 설정
typedef CHAR_INFO Text;

//속성값을 편하게 갖고오기 위해서
enum TextColor
{
	TEXT_COLOR_BACK,//0
	TEXT_COLOR_BLUE = FOREGROUND_BLUE,
	TEXT_COLOR_RED = FOREGROUND_RED,
	TEXT_COLOR_GREEN = FOREGROUND_GREEN,
	TEXT_COLOR_CYAN = TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
	TEXT_COLOR_MAGENTA = TEXT_COLOR_RED | TEXT_COLOR_BLUE,
	TEXT_COLOR_YELLOW = TEXT_COLOR_RED | TEXT_COLOR_GREEN,
	TEXT_COLOR_WHITE = TEXT_COLOR_RED | TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
	TEXT_COLOR_STRONG = FOREGROUND_INTENSITY
};

//
enum BackgroundColor
{
	BACK_COLOR_BLACK,
	BACK_COLOR_BLUE = BACKGROUND_BLUE,
	BACK_COLOR_RED = BACKGROUND_RED,
	BACK_COLOR_GREEN = BACKGROUND_GREEN,
	BACK_COLOR_CYAN = BACK_COLOR_BLUE | BACK_COLOR_GREEN,
	BACK_COLOR_MAGENTA = BACK_COLOR_RED | BACK_COLOR_BLUE,
	BACK_COLOR_YELLOW = BACK_COLOR_RED | BACK_COLOR_GREEN,
	BACK_COLOR_WHITE = BACK_COLOR_RED | BACK_COLOR_BLUE | BACK_COLOR_GREEN,
	BACK_COLOR_STRONG = BACKGROUND_INTENSITY
};

//텍스트 복사
void TextCopy(Text* dest, const WCHAR* src, WORD attribute);
int32 TextLen(const Text* text);

#define TextCopyWithWhite(dest, src) TextCopy(dest, src, TEXT_COLOR_WHITE);