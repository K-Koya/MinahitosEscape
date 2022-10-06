#pragma once

/// <summary>毎フレーム描画したいものがある時に継承</summary>
class Renderable 
{
public:

	/// <summary>シーンから呼び出す、毎フレーム描画メソッド</summary>
	void doRender();

	/// <summary>true : 毎フレーム描画する</summary>
	bool _isActive;

private:

	/// <summary>毎フレーム描画する処理を記述</summary>
	virtual void render() = 0;
};
