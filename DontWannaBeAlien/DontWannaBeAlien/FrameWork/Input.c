#include "Common.h"
#include "Input.h"

#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))

bool s_prevKeyState[256];
bool s_curKeyState[256];

// �Էºθ� �ʱ�ȭ�Ѵ�.
bool Input_Init(void) {
	return true;
}

// �Էºθ� ������Ʈ�Ѵ�.
// ���� �������� Ű ���� ���� �� ���� �������� Ű ���¸� �����;���
void Input_Update(void) {
	//�޸� ��ü�� �����ϴ� ��ɾ�
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

// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey :���� Ű�ڵ�
// ó�� ������ ���� true
bool Input_GetKeyDown(uint8 vkey) {
	if (s_prevKeyState[vkey] == false && s_curKeyState[vkey] == true) {
		return true;
	}

	return false;
}

// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
// vkey :���� Ű�ڵ�
bool Input_GetKeyUp(uint8 vkey) {
	if (s_prevKeyState[vkey] == true && s_curKeyState[vkey] == false) {
		return true;
	}

	return false;

}

// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey :���� Ű�ڵ�
// ��� ������ ���� true
bool Input_GetKey(uint8 vkey) {
	if (s_prevKeyState[vkey] == true && s_curKeyState[vkey] == true) {
		return true;
	}

	return false;
}