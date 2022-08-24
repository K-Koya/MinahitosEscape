#pragma once
#include "DxLib.h"
#include <chrono>;

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

