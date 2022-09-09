#pragma once
#include "DxLib.h"
#include "Position.h"
#include "../DataType/Quaternion.h"

/// <summary>ˆÊ’u‚ÆŒü‚«‚Ìî•ñ‚ğ‚¿‚½‚¢‚Æ‚«‚ÉŒp³</summary>
class Transform : public Position {
public:
	/// <summary>‰ñ“]î•ñ</summary>
	Quaternion* _Rotation;

};