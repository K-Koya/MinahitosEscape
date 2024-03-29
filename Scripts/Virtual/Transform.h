#pragma once
#include "DxLib.h"
#include "Position.h"
#include "../DataType/MyList.h"
#include "../DataType/Quaternion.h"

/// <summary>位置と向きの情報を持ちたいときに継承</summary>
class Transform : public Position {
public:
	/// <summary>姿勢情報</summary>
	Quaternion* _posture;

	/// <summary>親となる位置と向きの情報</summary>
	Transform* _parent;
};