#pragma once

#include "Type.h"

/// <summary>
/// Ÿ�̸� �ʱ�ȭ
/// </summary>
/// <param name = "fps"> ������ FPS</param>
void Timer_Init(int32 fps);

/// <summary>
/// Ÿ�̸� ������Ʈ
/// </summary>
/// <return> ������Ʈ�� �����ߴٸ� true, �ƴϸ� false
bool Timer_Update(void);

/// <summary>
/// ��ŸŸ�� ���ϱ�
/// </summary>
/// <return> DetaTime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ ������ �ɸ� �ð� </return>
float Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime()