#pragma once
#include <vector>

/// <summary>毎フレーム描画したいものがある時に継承</summary>
class Renderable 
{
public:

	/// <summary>レンダリングするオブジェクトのハンドル変数</summary>
	std::vector<int> _useModelHandlers;

	/// <summary>true : 毎フレーム描画する</summary>
	bool _isRendering;

	/// <summary>シーンから呼び出す、毎フレーム描画メソッド</summary>
	void doRender();


private:

	/// <summary>毎フレーム描画する処理を記述</summary>
	virtual void render() = 0;
};
