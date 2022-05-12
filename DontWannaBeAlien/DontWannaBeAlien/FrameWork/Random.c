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

	int32 range = maxExclusive - minInclusive;
	int32 count = 1 + range / RAND_MAX;

	int32 result = 0;
	for (int32 i = 0; i < count; i++) {
		result += rand() % range;
	}
	result += minInclusive;

	return result;
}

// 무작위 실수를 가져온다.
// [minInclusive, maxInclusive] 범위의 무작위 실수를 가져온다.
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive) {
	float result = (float)rand() / RAND_MAX * (maxInclusive - minInclusive) + minInclusive;

	return result;
}