#pragma once

#include "Type.h"

/// <summary>
/// �������� �ʱ�ȭ
/// </summary>
/// <returns>�ʱ�ȭ ���� �� true, �ƴϸ� false</returns>
bool Renderer_Init(void);

/// <summary>
/// �������� �����Ѵ�.
/// </summary>
void Renderer_Cleanup(void);

/// <summary>
/// ȭ���� �ٲ۴�.
/// </summary>
void Renderer_Flip(void);

/// <summary>
/// �ؽ�Ʈ�� ����Ѵ�.
/// </summary>
void Renderer_DrawText(const char* text, int32 numberOfChar);