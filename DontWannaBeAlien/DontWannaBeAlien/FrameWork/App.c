#include "App.h"
#include "Common.h"

bool App_Init() {
	
	return true;
}

void precessInput() {

}

void update() {

}

void render() {
	system("cls");
	puts("Hello Game");
}

int32 App_Run() {
	//Game Loop : ������ ���۽�Ű�� ����

	while(true) { //���� �ܼ��� ���� ����!
		precessInput(); // �Է� ó��
		update(); // ���� ������Ʈ
		render(); // ���� ���
	} //<< �� �����ϳ��� frame�̶�� �Ѵ�. (FPS�� �̰��� ����)
	//FPS = Frame Per Second, 60������ >>> 1�ʿ� 60��, 120������ >>> 1�ʿ� 120��

	return 0;
}
