#pragma once

class Updatable 
{
public:

	/// <summary>毎フレーム実行させたい処理を記述</summary>
	/// <param name="deltaTime">1フレームあたりの時間</param>
	virtual void Update(float deltaTime) = 0;

private:


};