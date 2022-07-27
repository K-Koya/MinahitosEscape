#include "GameMain.h";
#include <stdio.h>
#include <string>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	IsFullScreen = false;
	WindowSizeWidth = 1280;
	WindowSizeHeight = 720;
	FpsMax = 60;

	//��ʃT�C�Y�Ǝg�p����F�o�C�g�l���w�肷��
	SetGraphMode(WindowSizeWidth, WindowSizeHeight, 16);
	ChangeWindowMode(!IsFullScreen);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �v���J�n����
	ClockStart = std::chrono::system_clock::now();

	IsGameEnd = false;
	while (!IsGameEnd) {

		// �t���[���Ԃ̌o�ߎ���
		// �}�C�N���b�Ōv�����ĕb�ɕϊ�
		ClockEnd = std::chrono::system_clock::now();
		double microSeconds = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(ClockEnd - ClockStart).count());
		float deltaTime = static_cast<float>(microSeconds / 1000.0 / 1000.0);
		ClockStart = ClockEnd;

		if (ProcessMessage() == -1) {
			break;
		}

		FpsClockStart = std::chrono::system_clock::now();

		// ��ʂ��N���A
		ClearDrawScreen();

		// �t���[�����\��
		char fps[8];
		snprintfDx(fps, 8, "%f", 1.0f / deltaTime);
		DrawString(0, 0, fps, GetColor(255, 255, 255));

		// �e�Q�[���������������ōX�V



		// �����őg�ݗ��ĂĂ�����ʂ�\�ɕ\��
		ScreenFlip();

		// �t���[���l�𒲐�
		FpsClockEnd = std::chrono::system_clock::now();
		double fpsMicroSec = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(FpsClockEnd - FpsClockStart).count());
		float fpsMiliSec = static_cast<float>(fpsMicroSec / 1000.0);
		float fpsLimit = 1000.0f / FpsMax;


		if (fpsLimit > fpsMiliSec) {
			//timeBeginPeriod(1);
			Sleep(DWORD(fpsLimit - fpsMiliSec));
			//timeEndPeriod(1);
		}
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I�� 
	return 0;
}