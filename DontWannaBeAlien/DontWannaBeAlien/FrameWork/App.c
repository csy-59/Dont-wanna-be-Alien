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
	//Game Loop : 게임을 동작시키는 루프

	while(true) { //가장 단순한 게임 구조!
		precessInput(); // 입력 처리
		update(); // 게임 업데이트
		render(); // 게임 출력
	} //<< 이 과정하나를 frame이라고 한다. (FPS가 이것을 뜻함)
	//FPS = Frame Per Second, 60프래임 >>> 1초에 60번, 120프래임 >>> 1초에 120번

	return 0;
}
