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

	int32 result = ((int64)rand() * rand() * 4) % ((int64)maxExclusive - minInclusive) + minInclusive;

	return result;
}

// ������ �Ǽ��� �����´�.
// [minInclusive, maxInclusive] ������ ������ �Ǽ��� �����´�.
float Random_GetFNumberFromRange(float minInclusive, float maxInclusive) {
	float result = (float)rand() / RAND_MAX * (maxInclusive - minInclusive) + minInclusive;

	return result;
}