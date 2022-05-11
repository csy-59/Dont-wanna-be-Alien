#include "Common.h"
#include "Timer.h"

clock_t s_prevTick; //���� ƽ
float s_deltaTime;
float s_fixedTime; //���� �ð�

void Timer_Init(int32 fps) {
	//���� �ð��� ����Ѵ�.
	s_fixedTime = 1.0 / fps;

	//������ ����
	s_prevTick = clock(); 
}

bool Timer_Update(void) {
	clock_t currentTick = clock(); //1. ���� ������ ����

	// 2. ���� ������ ���� ������ ���̸� ���� �帥 �ð��� ���Ѵ�.
	//Ŭ���� �� ������ ��ȯ����. �帥�ð��� �ʴ�����.
	//������ int������ ��ȯ�Ǵ� float�� ���ϱ� ������ ����ȯ
	
	//��� ������ �ð��� ������ update�� �����Ѵ�.
	float deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC; //�̰� ��ü�� clock�� �ʴ����� ��ȯ�Ѱ�
	if (deltaTime < s_fixedTime) {
		return false;
	}
	//���� �ð��� ������ ������Ʈ
	s_deltaTime = deltaTime;
	s_prevTick = currentTick; //���� ���� ������Ʈ
	return true;
}

float Timer_GetDeltaTime(void) {
	return s_deltaTime; // �ð� ��ȯ
}
