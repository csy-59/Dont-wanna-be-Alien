#include "Common.h"
#include "Timer.h"

clock_t s_prevTick; //이전 틱
float s_deltaTime;
float s_fixedTime; //고정 시간

void Timer_Init(int32 fps) {
	//고정 시간을 계산한다.
	s_fixedTime = 1.0 / fps;

	//시점을 찍어둠
	s_prevTick = clock(); 
}

bool Timer_Update(void) {
	clock_t currentTick = clock(); //1. 현재 시점을 찍음

	// 2. 현재 시점과 이전 시점의 차이를 통해 흐른 시간을 구한다.
	//클럭을 초 단위로 변환해줌. 흐른시간을 초단위로.
	//원래는 int형으로 변환되는 float로 원하기 때문에 형변환
	
	//적어도 고정된 시간이 지나야 update를 실행한다.
	float deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC; //이거 자체가 clock을 초단위로 변환한것
	if (deltaTime < s_fixedTime) {
		return false;
	}
	//일정 시간이 지나면 업데이트
	s_deltaTime = deltaTime;
	s_prevTick = currentTick; //이전 시점 업데이트
	return true;
}

float Timer_GetDeltaTime(void) {
	return s_deltaTime; // 시간 반환
}
