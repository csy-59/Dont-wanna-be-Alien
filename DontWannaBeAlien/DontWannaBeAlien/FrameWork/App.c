#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"

bool App_Init() {
	if (false == Renderer_Init()) {
		return false;
	}
	return true;
}

void precessInput() {

}

int32 s_FPS = 0;
float elapsedTime;
bool canShow = false;
void update() {
	/*
	//fps�� ����غ���
	// ��ʽ�
	// ������ : �ð�
	// 1 : deltaTime = fps : 1
	// 1 = deltaTime * fps
	// fps = 1 / deltaTime
	char str[128] = "";
	//str�� ���
	sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1/Timer_GetDeltaTime()));
	Renderer_DrawText(str, strlen(str));
	//Renderer_DrawText("Hello Game", sizeof("Hello Game"));
	*/

	// 0.5�ʸ��� �����̴� �ؽ�Ʈ�� ����ÿ�.
	/*
	* //������: �۷�����
	int32 tempFPS = (int32)(1 / Timer_GetDeltaTime());

	if ( (s_FPS + tempFPS) > 500) {
		//char str[128] = "";
		////str�� ���
		//sprintf_s(str, sizeof(str), "%d", deltaT);
		//Renderer_DrawText(str, strlen(str));
		Renderer_DrawText("�ȳ�!", sizeof("�ȳ�!"));
		Renderer_DrawText("�ȳ�!", sizeof("�ȳ�!"));
		s_FPS = 0;
	}
	else {
		s_FPS += tempFPS;
	}
	//60 >> 1�и� ������ >> 1000 == 1�� >> 500 60* 500 >> 30000
	*/
	//������ ����
	elapsedTime += DELTA_TIME;
	if (elapsedTime >= 0.5) {
		elapsedTime = 0.0f;
		canShow = !canShow;
	}

	if (canShow) {
		Renderer_DrawText("Hell��", sizeof("Hell��"));
	}

}

void render() {
	Renderer_Flip();
}

void cleanup() {
	Renderer_Cleanup();
}

int32 App_Run() {

	//������ ������ �ڵ����� ����
	atexit(cleanup);

	Timer_Init(60);
	//Game Loop : ������ ���۽�Ű�� ����
	while(true) { //���� �ܼ��� ���� ����!
		//DeltaTime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ ������ �ɸ� �ð�.
		//�ð��� ������Ʈ ���� ������ ���� ���� ����
		if (Timer_Update()) {
			precessInput(); // �Է� ó��
			update(); // ���� ������Ʈ
			render(); // ���� ���
		}
	} //<< �� �����ϳ��� frame�̶�� �Ѵ�. (FPS�� �̰��� ����)
	//FPS = Frame Per Second, 60������ >>> 1�ʿ� 60��, 120������ >>> 1�ʿ� 120��

	return 0;
}
