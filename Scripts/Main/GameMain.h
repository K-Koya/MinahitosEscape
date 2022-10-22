#pragma once
#include <stdio.h>
#include <string>
#include <chrono>
#include "DxLib.h"
#include "../DataType/Quaternion.h"
#include "../Virtual/SceneBase.h"
#include "../Main/Scene/TitleScene.h"


/// <summary>これとclockEndの時間の差からアップデート間時間を求める</summary>
static std::chrono::system_clock::time_point ClockStart;
/// <summary>これとclockStartの時間の差からアップデート間時間を求める</summary>
static std::chrono::system_clock::time_point ClockEnd;

/// <summary>これとfpsClockEndの時間の差からフレーム間時間を求める</summary>
static std::chrono::system_clock::time_point FpsClockStart;
/// <summary>これとfpsClockStartの時間の差からフレーム間時間を求める</summary>
static std::chrono::system_clock::time_point FpsClockEnd;

/// <summary>true : フルスクリーン表示する</summary>
static bool IsFullScreen;

/// <summary>ウィンドウの横幅</summary>
static int WindowSizeWidth;
/// <summary>ウィンドウの縦幅</summary>
static int WindowSizeHeight;

/// <summary>true : ゲーム終了</summary>
static bool IsGameEnd;

/// <summary>1秒あたりの描画回数</summary>
static float FpsMax;


/// <summary>再生中のシーン</summary>
static SceneBase* PlayingScene;



/*
const Test* Function (Test* test){}
=> 戻り値のメンバ変数は書き換えはしない

Test* const Function (Test* test){}
=> 戻り値のポインタの参照先は変更しない

Test* Function (const Test* test){}
=> メソッド内部で引数の値の書き換えはしない

Test* Function (Test* test) const {}
=> メソッド内部で他のメンバ変数の書き換えはしない

*/