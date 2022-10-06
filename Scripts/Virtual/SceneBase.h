#pragma once
#include <functional>

class SceneBase {
public:

	SceneBase() {}
	~SceneBase() {}

	/// <summary>毎フレーム実行メソッド</summary>
	virtual void update(float deltaTime) = 0;

	/// <summary>描画メソッド</summary>
	virtual void render() = 0;
};
