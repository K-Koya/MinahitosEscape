#pragma once
#include "DxLib.h"

/// <summary>�ʒu�������������Ƃ��Ɍp�����Ďg�p</summary>
class Position
{
public:
	/// <summary>3�������W�l</summary>
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