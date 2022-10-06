#pragma once
#include "DxLib.h"
#include <math.h>

/// <summary>��]���</summary>
class Quaternion {
public:

	Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
	~Quaternion();

	float x;
	float y;
	float z;
	float w;

	/// <summary>�����w�肵�ă��W�A���p��������]������N�H�[�^�[�j�I�������߂Đ�������</summary>
	/// <param name="rad">���W�A���p�x�l</param>
	/// <param name="shaft">��]��</param>
	/// <returns>��]�N�H�[�^�[�j�I��</returns>
	static Quaternion* AngleAxis(const float rad, VECTOR shaft);

	/// <summary>�Ƃ���x�N�g�����N�H�[�^�[�j�I�����g���ĉ�]������</summary>
	/// <param name="target">��]���������x�N�g��</param>
	/// <param name="rQot">��]���N�H�[�^�[�j�I��</param>
	/// <returns>��]��̃x�N�g��</returns>
	static VECTOR* Rotate(const VECTOR target, const Quaternion rQot);

	/// <summary>���ʓI�ɉ�]�ʂ�⊮����</summary>
	/// <param name="from">��]��</param>
	/// <param name="to">��]��</param>
	/// <param name="ratio">1��̎��s�ɂ��⊮�ʂ̊���(0.0 �` 1.0)</param>
	/// <returns>��]�N�H�[�^�[�j�I��</returns>
	static Quaternion* SphereLerp(Quaternion from, const Quaternion to, const float ratio);

	/// <summary>�P�ʃN�H�[�^�[�j�I�������߂�</summary>
	/// <returns>�P�ʃN�H�[�^�[�j�I��</returns>
	inline Quaternion norm() const {
		return Quaternion(x, y, z, w) / sqrtf(x * x + y * y + z * z + w * w);
	}

	/// <summary>�t�N�H�[�^�[�j�I�������߂�</summary>
	/// <returns>�t�N�H�[�^�[�j�I��</returns>
	inline Quaternion inv() const {
		float absSqr = x * x + y * y + z * z + w * w;
		Quaternion ans = Quaternion(-x, -y, -z, w);
		return ans / absSqr;
	}

	/// <summary>���������ׂĔ��]�����N�H�[�^�[�j�I�������߂�</summary>
	/// <returns>���������ׂĔ��]�����N�H�[�^�[�j�I��</returns>
	inline Quaternion operator-() const {
		return Quaternion(-x, -y, -z, -w);
	}

	/// <summary>�N�H�[�^�[�j�I���̃X�J���[�{</summary>
	/// <param name="multiple">�����鐔</param>
	/// <returns>��</returns>
	inline Quaternion operator*(const float multiple) const {
		return Quaternion(x * multiple, y * multiple, z * multiple, w * multiple);
	}

	/// <summary>�N�H�[�^�[�j�I���̃X�J���[���Z</summary>
	/// <param name="divide">���鐔</param>
	/// <returns>��</returns>
	inline Quaternion operator/(const float divide) const {
		return Quaternion(x / divide, y / divide, z / divide, w / divide);
	}

	/// <summary>�N�H�[�^�[�j�I���̐ρi�����s�j</summary>
	/// <param name="calcQot">�����鐔</param>
	/// <returns>��</returns>
	inline Quaternion operator*(const Quaternion& calcQot) const {
		Quaternion ans = Quaternion();
		ans.x = w * calcQot.x - z * calcQot.y + y * calcQot.z + x * calcQot.w;
		ans.y = z * calcQot.x + w * calcQot.y - x * calcQot.z + y * calcQot.w;
		ans.z = -y * calcQot.x + x * calcQot.y + w * calcQot.z + z * calcQot.w;
		ans.w = -x * calcQot.x - y * calcQot.y - z * calcQot.z + w * calcQot.w;
		return ans;
	}
};