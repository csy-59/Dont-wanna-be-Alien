#pragma once

#include "Type.h"

// 랜덤 초기화
bool Random_Init();

// 무작위 정수를 가져온다.
// [minInclusive, maxInclusive) 범위의 무작위 정수를 가져온다.
int32 Random_GetNumberFormRange(int32 minInclusive, int32 maxExclusive);

// 무작위 실수를 가져온다.
// [minInclusive, maxInclusive] 범위의 무작위 정수를 가져온다.
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive);