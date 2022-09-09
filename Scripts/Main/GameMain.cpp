#include "GameMain.h";
#include <stdio.h>
#include <string>
#include "../DataType/Quaternion.h";

/// <summary>ここに各種オブジェクトの毎フレーム実行関数を定義</summary>
/// <param name="deltaTime">1フレーム当たりの時間</param>
void Update(float deltaTime) {


}


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	IsFullScreen = false;
	WindowSizeWidth = 1280;
	WindowSizeHeight = 720;
	FpsMax = 60.0f;

	//画面サイズと使用する色バイト値を指定する
	SetGraphMode(WindowSizeWidth, WindowSizeHeight, 16);
	ChangeWindowMode(!IsFullScreen);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 計測開始時間
	ClockStart = std::chrono::system_clock::now();

	IsGameEnd = false;
	while (!IsGameEnd) {

		// フレーム間の経過時間
		// マイクロ秒で計測して秒に変換
		ClockEnd = std::chrono::system_clock::now();
		double microSeconds = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(ClockEnd - ClockStart).count());
		float deltaTime = static_cast<float>(microSeconds / 1000.0 / 1000.0);
		ClockStart = ClockEnd;

		if (ProcessMessage() == -1) {
			break;
		}

		FpsClockStart = std::chrono::system_clock::now();

		// 画面をクリア
		ClearDrawScreen();

		// フレーム数表示
		char fps[8];
		snprintfDx(fps, 8, "%f", 1.0f / deltaTime);
		DrawString(0, 0, fps, GetColor(255, 255, 255));

		// 各ゲーム内処理をここで更新
		Update(deltaTime);

		// 裏側で組み立てていた画面を表に表示
		ScreenFlip();

		// 1フレームあたりの時間を調整するための遅延行為
		FpsClockEnd = std::chrono::system_clock::now();
		double fpsMicroSec = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(FpsClockEnd - FpsClockStart).count());
		float fpsMiliSec = static_cast<float>(fpsMicroSec / 1000.0);
		float fpsLimit = 1000.0f / FpsMax;

		if (fpsLimit > fpsMiliSec) {
			Sleep(DWORD(fpsLimit - fpsMiliSec));
		}
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了 
	return 0;
}