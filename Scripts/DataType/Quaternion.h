#pragma once
#include "DxLib.h"
#include <math.h>

/// <summary>回転情報</summary>
class Quaternion {
public:

	Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
	~Quaternion();

	float x;
	float y;
	float z;
	float w;

	/// <summary>軸を指定してラジアン角分だけ回転させるクォーターニオンを求めて生成する</summary>
	/// <param name="rad">ラジアン角度値</param>
	/// <param name="shaft">回転軸</param>
	/// <returns>回転クォーターニオン</returns>
	static Quaternion* AngleAxis(const float rad, VECTOR shaft);

	/// <summary>とあるベクトルをクォーターニオンを使って回転させる</summary>
	/// <param name="target">回転させたいベクトル</param>
	/// <param name="rQot">回転情報クォーターニオン</param>
	/// <returns>回転後のベクトル</returns>
	static VECTOR* Rotate(const VECTOR target, const Quaternion rQot);

	/// <summary>球面的に回転量を補完する</summary>
	/// <param name="from">回転元</param>
	/// <param name="to">回転先</param>
	/// <param name="ratio">1回の実行による補完量の割合(0.0 ～ 1.0)</param>
	/// <returns>回転クォーターニオン</returns>
	static Quaternion* SphereLerp(Quaternion from, const Quaternion to, const float ratio);

	/// <summary>単位クォーターニオンを求める</summary>
	/// <returns>単位クォーターニオン</returns>
	inline Quaternion norm() const {
		return Quaternion(x, y, z, w) / sqrtf(x * x + y * y + z * z + w * w);
	}

	/// <summary>逆クォーターニオンを求める</summary>
	/// <returns>逆クォーターニオン</returns>
	inline Quaternion inv() const {
		float absSqr = x * x + y * y + z * z + w * w;
		Quaternion ans = Quaternion(-x, -y, -z, w);
		return ans / absSqr;
	}

	/// <summary>符号をすべて反転したクォーターニオンを求める</summary>
	/// <returns>符号をすべて反転したクォーターニオン</returns>
	inline Quaternion operator-() const {
		return Quaternion(-x, -y, -z, -w);
	}

	/// <summary>クォーターニオンのスカラー倍</summary>
	/// <param name="multiple">かける数</param>
	/// <returns>積</returns>
	inline Quaternion operator*(const float multiple) const {
		return Quaternion(x * multiple, y * multiple, z * multiple, w * multiple);
	}

	/// <summary>クォーターニオンのスカラー除算</summary>
	/// <param name="divide">割る数</param>
	/// <returns>除</returns>
	inline Quaternion operator/(const float divide) const {
		return Quaternion(x / divide, y / divide, z / divide, w / divide);
	}

	/// <summary>クォーターニオンの積（交換不可）</summary>
	/// <param name="calcQot">かける数</param>
	/// <returns>積</returns>
	inline Quaternion operator*(const Quaternion& calcQot) const {
		Quaternion ans = Quaternion();
		ans.x = w * calcQot.x - z * calcQot.y + y * calcQot.z + x * calcQot.w;
		ans.y = z * calcQot.x + w * calcQot.y - x * calcQot.z + y * calcQot.w;
		ans.z = -y * calcQot.x + x * calcQot.y + w * calcQot.z + z * calcQot.w;
		ans.w = -x * calcQot.x - y * calcQot.y - z * calcQot.z + w * calcQot.w;
		return ans;
	}
};