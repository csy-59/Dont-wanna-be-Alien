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

	//게임이 끝나면 자동으로 실행
	atexit(cleanup);

	//Game Loop : 게임을 동작시키는 루프
	while(true) { //가장 단순한 게임 구조!
		precessInput(); // 입력 처리
		update(); // 게임 업데이트
		render(); // 게임 출력
	} //<< 이 과정하나를 frame이라고 한다. (FPS가 이것을 뜻함)
	//FPS = Frame Per Second, 60프래임 >>> 1초에 60번, 120프래임 >>> 1초에 120번

	return 0;
}
