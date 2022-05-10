#include "App.h"
#include "Common.h"
#include "Renderer.h"

bool App_Init() {
	if (false == Renderer_Init()) {
		return false;
	}
	return true;
}

void precessInput() {

}

void update() {
	Renderer_DrawText("Hello Game", sizeof("Hello Game"));
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

	//Game Loop : ������ ���۽�Ű�� ����
	while(true) { //���� �ܼ��� ���� ����!
		precessInput(); // �Է� ó��
		update(); // ���� ������Ʈ
		render(); // ���� ���
	} //<< �� �����ϳ��� frame�̶�� �Ѵ�. (FPS�� �̰��� ����)
	//FPS = Frame Per Second, 60������ >>> 1�ʿ� 60��, 120������ >>> 1�ʿ� 120��

	return 0;
}
