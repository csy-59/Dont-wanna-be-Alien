#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include "Text.h"

bool App_Init() {
	if (false == Renderer_Init()) {
		return false;
	}

	if (false == Input_Init()) {
		return false;
	}

	if (false == Random_Init()) {
		return false;
	}

	return true;
}

void precessInput() {
	Input_Update();
}

Text text[128];
char str[128];
//int32 s_FPS = 0;
//float elapsedTime;
//bool canShow = false;
void update() {
	//Timer �ǽ�
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
	

	// 0.5�ʸ��� �����̴� �ؽ�Ʈ�� ����ÿ�.
	/*
	//* //������: �۷�����
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
	
	//������ ����
	elapsedTime += DELTA_TIME;
	if (elapsedTime >= 0.5) {
		elapsedTime = 0.0f;
		canShow = !canShow;
	}

	if (canShow) {
		Renderer_DrawText("Hell��", sizeof("Hell��"));
	}
	*/


	//Input �ǽ�
	/*
	// ���� ȭ��ǥ�� ���ȴ��� Ȯ��
	//0x0000 : Ű�� ����
	//0x8000 : Ű�� ����
	if (0x8000 & GetAsyncKeyState(VK_UP)) { //MSB�� ���ȴ��� Ȯ���ϱ� ���� & ������ ���
		// ���ȴٸ� "���� ȭ��ǥ ����" ���
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
	}
	else {
		//������ �ʾҴٸ� "���� ȭ��ǥ ��" ���
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ��");
	}
	sprintf_s(str, sizeof(str), "���� �Է� ����");

	if (Input_GetKey(VK_UP)) {
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_DOWN)) {
		sprintf_s(str, sizeof(str), "�Ʒ��� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT)) {
		sprintf_s(str, sizeof(str), "����, ������ ȭ��ǥ ���� ����");
	}
	*/

	//Random �ǽ�
	/*
	float num1 = Random_GetFNumberFromRange(0.0, 0.1);
	if (num1 < 0 || num1 > 4) {
		sprintf_s(str, sizeof(str), "��û�� ��¥ ����û��");
	}
	else {
		sprintf_s(str, sizeof(str), "%f", num1);
	}
	Sleep(500);
	*/
	
	//Text �ǽ�
	TextCopyWithWhite(text, TEXT("�츮���� ������ �������̴�."));
	
}

void render() {
	Renderer_DrawText(text, TextLen(text), 10, 10);
	Renderer_Flip();
}

void cleanup(void) {
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
