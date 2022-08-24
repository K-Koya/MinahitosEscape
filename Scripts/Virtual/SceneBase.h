#pragma once

class SceneBase {
public:

	SceneBase() {}
	virtual ~SceneBase() {}

	/// <summary>初期化メソッド</summary>
	virtual void initialzie() = 0;

	/// <summary>描画メソッド</summary>
	virtual void render() {}
};
