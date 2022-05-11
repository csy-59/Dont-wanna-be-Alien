#pragma once

#include "Type.h"

// 입력부를 초기화한다.
bool Input_Init(void);

// 입력부를 업데이트한다.
// 이전 프레임의 키 내용 저장 및 현재 프레임의 키 상태를 가져와야함
void Input_Update(void);

// 현재 프레임에 키가 눌렸다면 true, 아니면 false
// vkey :가상 키코드
// 처음 눌렀을 때만 true
bool Input_GetKeyDown(uint8 vkey);

// 현재 프레임에 키가 떼졌다면 true, 아니면 false
// vkey :가상 키코드
bool Input_GetKeyUp(uint8 vkey);

// 이전 프레임과 현재 프레임에 모두 키가 눌렸다면 true, 아니면 false
// vkey :가상 키코드
// 계속 눌렸을 때만 true
bool Input_GetKey(uint8 vkey);