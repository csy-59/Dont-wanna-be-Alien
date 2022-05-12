#include "Common.h"
#include "Random.h"

// ���� �ʱ�ȭ
bool Random_Init() {
	srand(time(NULL));

	return true;
}

// ������ ������ �����´�.
// [minInclusive, maxInclusive) ������ ������ ������ �����´�.
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

// ������ �Ǽ��� �����´�.
// [minInclusive, maxInclusive] ������ ������ �Ǽ��� �����´�.
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive) {
	float result = (float)rand() / RAND_MAX * (maxInclusive - minInclusive) + minInclusive;

	return result;
}