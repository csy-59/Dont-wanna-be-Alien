#pragma once

#include "Type.h"

// ���� �ʱ�ȭ
bool Random_Init();

// ������ ������ �����´�.
// [minInclusive, maxInclusive) ������ ������ ������ �����´�.
int32 Random_GetNumberFormRange(int32 minInclusive, int32 maxExclusive);

// ������ �Ǽ��� �����´�.
// [minInclusive, maxInclusive] ������ ������ ������ �����´�.
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive);