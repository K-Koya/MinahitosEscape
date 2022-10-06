#pragma once

/// <summary>毎フレーム呼び出したいメソッドがある時に継承</summary>
class Updatable 
{
public:

	/// <summary>シーンから呼び出す、毎フレーム実行メソッド</summary>
	void doUpdate(float deltaTime);

	/// <summary>true : 毎フレーム実行する</summary>
	bool _isActive;

protected: 

	/// <summary>毎フレーム実行させたい処理を記述</summary>
	/// <param name="deltaTime">1フレームあたりの時間</param>
	virtual void update(float deltaTime) = 0;

private:


};