#pragma once

#include "Type.h"

/// <summary>
/// 타이머 초기화
/// </summary>
/// <param name = "fps"> 고정할 FPS</param>
void Timer_Init(int32 fps);

/// <summary>
/// 타이머 업데이트
/// </summary>
/// <return> 업데이트를 성공했다면 true, 아니면 false
bool Timer_Update(void);

/// <summary>
/// 델타타임 구하기
/// </summary>
/// <return> DetaTime : 프레임 간의 시간. 이전 프레임으로부터 현재 프래임을 시작할 때까지 걸린 시간 </return>
float Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime()