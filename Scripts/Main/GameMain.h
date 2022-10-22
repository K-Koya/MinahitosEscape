#pragma once
#include <stdio.h>
#include <string>
#include <chrono>
#include "DxLib.h"
#include "../DataType/Quaternion.h"
#include "../Virtual/SceneBase.h"
#include "../Main/Scene/TitleScene.h"


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


/// <summary>�Đ����̃V�[��</summary>
static SceneBase* PlayingScene;



/*
const Test* Function (Test* test){}
=> �߂�l�̃����o�ϐ��͏��������͂��Ȃ�

Test* const Function (Test* test){}
=> �߂�l�̃|�C���^�̎Q�Ɛ�͕ύX���Ȃ�

Test* Function (const Test* test){}
=> ���\�b�h�����ň����̒l�̏��������͂��Ȃ�

Test* Function (Test* test) const {}
=> ���\�b�h�����ő��̃����o�ϐ��̏��������͂��Ȃ�

*/