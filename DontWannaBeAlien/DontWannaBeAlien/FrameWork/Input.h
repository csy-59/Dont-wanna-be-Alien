#pragma once

#include "Type.h"

// �Էºθ� �ʱ�ȭ�Ѵ�.
bool Input_Init(void);

// �Էºθ� ������Ʈ�Ѵ�.
// ���� �������� Ű ���� ���� �� ���� �������� Ű ���¸� �����;���
void Input_Update(void);

// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey :���� Ű�ڵ�
// ó�� ������ ���� true
bool Input_GetKeyDown(uint8 vkey);

// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
// vkey :���� Ű�ڵ�
bool Input_GetKeyUp(uint8 vkey);

// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey :���� Ű�ڵ�
// ��� ������ ���� true
bool Input_GetKey(uint8 vkey);