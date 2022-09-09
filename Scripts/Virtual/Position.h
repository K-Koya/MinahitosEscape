#pragma once
#include "DxLib.h"

/// <summary>位置情報を持ちたいときに継承して使用</summary>
class Position
{
public:
	/// <summary>3次元座標値</summary>
	VECTOR* _position;

	inline Position(float x = 0.0f, float y = 0.0f, float z = 0.0f) {
		_position = new VECTOR();
		_position->x = x;
		_position->y = y;
		_position->z = z;
	}

	inline ~Position() {
		delete(_position);
	}

private:
	
};