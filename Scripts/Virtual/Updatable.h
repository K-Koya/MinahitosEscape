#pragma once

/// <summary>毎フレーム呼び出したいメソッドがある時に継承</summary>
class Updatable 
{
public:

	/// <summary>毎フレーム実行させたい処理を記述</summary>
	/// <param name="deltaTime">1フレームあたりの時間</param>
	virtual void Update(float deltaTime) = 0;

private:


};