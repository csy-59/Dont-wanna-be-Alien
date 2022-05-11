#include "Common.h"
#include "Input.h"

#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))

bool s_prevKeyState[256];
bool s_curKeyState[256];

// 입력부를 초기화한다.
bool Input_Init(void) {
	return true;
}

// 입력부를 업데이트한다.
// 이전 프레임의 키 내용 저장 및 현재 프레임의 키 상태를 가져와야함
void Input_Update(void) {
	//메모리 자체를 복사하는 명령어
	memcpy(s_prevKeyState, s_curKeyState, 256);

	for (int vkey = 0; vkey < 256; vkey++) {
		if (IS_KEY_DOWN(vkey)) {
			s_curKeyState[vkey] = true;
		}
		else {
			s_curKeyState[vkey] = false;
		}
		
	}

	/*
	if (0x8000 & GetAsyncKeyState(Up)) {
		s_curInput[s_curInputCount++] = Up;
	}

	if (0x8000 & GetAsyncKeyState(Down)) {
		s_curInput[s_curInputCount++] = Down;
	}
	
	if (0x8000 & GetAsyncKeyState(Left)) {
		s_curInput[s_curInputCount++] = Left;
	}
	
	if (0x8000 & GetAsyncKeyState(Right)) {
		s_curInput[s_curInputCount++] = Right;
	}
	*/
}

// 현재 프레임에 키가 눌렸다면 true, 아니면 false
// vkey :가상 키코드
// 처음 눌렀을 때만 true
bool Input_GetKeyDown(uint8 vkey) {
	if (s_prevKeyState[vkey] == false && s_curKeyState[vkey] == true) {
		return true;
	}

	return false;
}

// 현재 프레임에 키가 떼졌다면 true, 아니면 false
// vkey :가상 키코드
bool Input_GetKeyUp(uint8 vkey) {
	if (s_prevKeyState[vkey] == true && s_curKeyState[vkey] == false) {
		return true;
	}

	return false;

}

// 이전 프레임과 현재 프레임에 모두 키가 눌렸다면 true, 아니면 false
// vkey :가상 키코드
// 계속 눌렸을 때만 true
bool Input_GetKey(uint8 vkey) {
	if (s_prevKeyState[vkey] == true && s_curKeyState[vkey] == true) {
		return true;
	}

	return false;
}