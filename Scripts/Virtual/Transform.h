#pragma once
#include "DxLib.h"
#include "Position.h"
#include "../DataType/Quaternion.h"

/// <summary>�ʒu�ƌ����̏������������Ƃ��Ɍp��</summary>
class Transform : public Position {
public:
	/// <summary>��]���</summary>
	Quaternion* _Rotation;

};