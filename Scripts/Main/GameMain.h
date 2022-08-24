#pragma once
#include "DxLib.h"
#include <chrono>;

/// <summary>�����clockEnd�̎��Ԃ̍�����A�b�v�f�[�g�Ԏ��Ԃ����߂�</summary>
static std::chrono::system_clock::time_point ClockStart;
/// <summary>�����clockStart�̎��Ԃ̍�����A�b�v�f�[�g�Ԏ��Ԃ����߂�</summary>
static std::chrono::system_clock::time_point ClockEnd;

/// <summary>�����fpsClockEnd�̎��Ԃ̍�����t���[���Ԏ��Ԃ����߂�</summary>
static std::chrono::system_clock::time_point FpsClockStart;
/// <summary>�����fpsClockStart�̎��Ԃ̍�����t���[���Ԏ��Ԃ����߂�</summary>
static std::chrono::system_clock::time_point FpsClockEnd;

/// <summary>true : �t���X�N���[���\������</summary>
static bool IsFullScreen;

/// <summary>�E�B���h�E�̉���</summary>
static int WindowSizeWidth;
/// <summary>�E�B���h�E�̏c��</summary>
static int WindowSizeHeight;

/// <summary>true : �Q�[���I��</summary>
static bool IsGameEnd;

/// <summary>1�b������̕`���</summary>
static float FpsMax;

