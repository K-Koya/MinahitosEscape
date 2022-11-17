#pragma once
#include "DxLib.h"
#include "Position.h"
#include "../DataType/MyList.h"
#include "../DataType/Quaternion.h"

/// <summary>�ʒu�ƌ����̏������������Ƃ��Ɍp��</summary>
class Transform : public Position {
public:
	/// <summary>�p�����</summary>
	Quaternion* _posture;

	/// <summary>�e�ƂȂ�ʒu�ƌ����̏��</summary>
	Transform* _parent;
};