#pragma once
#include "DxLib.h"
#include "Position.h"
#include "../DataType/MyList.h"
#include "../DataType/Quaternion.h"

/// <summary>ˆÊ’u‚ÆŒü‚«‚Ìî•ñ‚ğ‚¿‚½‚¢‚Æ‚«‚ÉŒp³</summary>
class Transform : public Position {
public:
	/// <summary>p¨î•ñ</summary>
	Quaternion* _posture;

	/// <summary>e‚Æ‚È‚éˆÊ’u‚ÆŒü‚«‚Ìî•ñ</summary>
	Transform* _parent;
};