#include "Common.h"
#include "Random.h"

// 랜덤 초기화
bool Random_Init() {
	srand(time(NULL));

	return true;
}

// 무작위 정수를 가져온다.
// [minInclusive, maxInclusive) 범위의 무작위 정수를 가져온다.
int32 Random_GetNumberFormRange(int32 minInclusive, int32 maxExclusive) {
	if (minInclusive > maxExclusive) {
		return ;
	}
	if (minInclusive == maxExclusive) {
		return minInclusive;
	}

	int32 result = ((int64)rand() * rand() * 4) % ((int64)maxExclusive - minInclusive) + minInclusive;

	return result;
}

// 무작위 실수를 가져온다.
// [minInclusive, maxInclusive] 범위의 무작위 실수를 가져온다.
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive) {
	float result = (float)rand() / RAND_MAX * (maxInclusive - minInclusive) + minInclusive;

	return result;
}