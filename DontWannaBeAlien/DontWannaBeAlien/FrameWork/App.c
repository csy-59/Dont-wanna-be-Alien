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
	//Timer 실습
	/*
	//fps를 출력해보장
	// 비례식
	// 프레임 : 시간
	// 1 : deltaTime = fps : 1
	// 1 = deltaTime * fps
	// fps = 1 / deltaTime
	char str[128] = "";
	//str에 출력
	sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1/Timer_GetDeltaTime()));
	Renderer_DrawText(str, strlen(str));
	//Renderer_DrawText("Hello Game", sizeof("Hello Game"));
	

	// 0.5초마다 깜빡이는 텍스트를 만드시오.
	/*
	//* //내버전: 글러먹음
	int32 tempFPS = (int32)(1 / Timer_GetDeltaTime());

	if ( (s_FPS + tempFPS) > 500) {
		//char str[128] = "";
		////str에 출력
		//sprintf_s(str, sizeof(str), "%d", deltaT);
		//Renderer_DrawText(str, strlen(str));
		Renderer_DrawText("안녕!", sizeof("안녕!"));
		Renderer_DrawText("안녕!", sizeof("안녕!"));
		s_FPS = 0;
	}
	else {
		s_FPS += tempFPS;
	}
	//60 >> 1밀리 세컨드 >> 1000 == 1초 >> 500 60* 500 >> 30000
	
	//교수님 버전
	elapsedTime += DELTA_TIME;
	if (elapsedTime >= 0.5) {
		elapsedTime = 0.0f;
		canShow = !canShow;
	}

	if (canShow) {
		Renderer_DrawText("Hell로", sizeof("Hell로"));
	}
	*/


	//Input 실습
	/*
	// 위쪽 화살표가 눌렸는지 확인
	//0x0000 : 키가 때짐
	//0x8000 : 키가 눌림
	if (0x8000 & GetAsyncKeyState(VK_UP)) { //MSB가 눌렸는지 확인하기 위해 & 연산자 사용
		// 눌렸다면 "위쪽 화살표 눌림" 출력
		sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
	}
	else {
		//눌리지 않았다면 "위쪽 화살표 땜" 출력
		sprintf_s(str, sizeof(str), "위쪽 화살표 땜");
	}
	sprintf_s(str, sizeof(str), "현재 입력 없음");

	if (Input_GetKey(VK_UP)) {
		sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_DOWN)) {
		sprintf_s(str, sizeof(str), "아래쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT)) {
		sprintf_s(str, sizeof(str), "왼쪽, 오른쪽 화살표 동시 눌림");
	}
	*/

	//Random 실습
	/*
	float num1 = Random_GetFNumberFromRange(0.0, 0.1);
	if (num1 < 0 || num1 > 4) {
		sprintf_s(str, sizeof(str), "멍청아 진짜 개멍청해");
	}
	else {
		sprintf_s(str, sizeof(str), "%f", num1);
	}
	Sleep(500);
	*/
	
	//Text 실습
	TextCopyWithWhite(text, TEXT("우리반의 존잘은 안재현이다."));
	
}

void render() {
	Renderer_DrawText(text, TextLen(text), 10, 10);
	Renderer_Flip();
}

void cleanup(void) {
	Renderer_Cleanup();
}

int32 App_Run() {

	//게임이 끝나면 자동으로 실행
	atexit(cleanup);

	Timer_Init(60);
	//Game Loop : 게임을 동작시키는 루프
	while(true) { //가장 단순한 게임 구조!
		//DeltaTime : 프레임 간의 시간. 이전 프레임으로부터 현재 프레임을 시작할 때까지 걸린 시간.
		//시간이 업데이트 됐을 때에만 게임 루프 실행
		if (Timer_Update()) {
			precessInput(); // 입력 처리
			update(); // 게임 업데이트
			render(); // 게임 출력
		}
	} //<< 이 과정하나를 frame이라고 한다. (FPS가 이것을 뜻함)
	//FPS = Frame Per Second, 60프래임 >>> 1초에 60번, 120프래임 >>> 1초에 120번

	return 0;
}
