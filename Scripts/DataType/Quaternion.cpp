#include "Quaternion.h"
#include <math.h>;

Quaternion::Quaternion(float x, float y, float z, float w) {
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

Quaternion::~Quaternion() {

}

MATRIX Quaternion::getMatrix() const {

	MATRIX result = MATRIX();
	result.m[0][0] = 2.0f * w * w + 2.0f * x * x - 1.0f;
	result.m[0][1] = 2.0f * x * y - 2.0f * z * w;
	result.m[0][2] = 2.0f * x * z + 2.0f * y * w;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 2.0f * x * y + 2.0f * z * w;
	result.m[1][1] = 2.0f * w * w + 2.0f * y * y - 1.0f;
	result.m[1][2] = 2.0f * y * z - 2.0f * x * w;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 2.0f * x * z - 2.0f * y * w;
	result.m[2][1] = 2.0f * y * z + 2.0f * x * w;
	result.m[2][2] = 2.0f * w * w + 2.0f * z * z - 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

void Quaternion::addAngleAxis(const float rad, const VECTOR shaft) {

	Quaternion result = AngleAxis(rad, shaft);
	float bx = x;
	float by = y;
	float bz = z;
	float bw = w;

	x = bw * result.x - bz * result.y + by * result.z + bx * result.w;
	y = bz * result.x + bw * result.y - bx * result.z + by * result.w;
	z = -by * result.x + bx * result.y + bw * result.z + bz * result.w;
	w = -bx * result.x - by * result.y - bz * result.z + bw * result.w;
}

Quaternion Quaternion::AngleAxis(const float rad, const VECTOR shaft) {

	VECTOR nShaft = VNorm(shaft);
	Quaternion result = Quaternion();
	result.w = (float)cos(rad / 2.0f);
	result.x = (float)sin(rad / 2.0f) * nShaft.x;
	result.y = (float)sin(rad / 2.0f) * nShaft.y;
	result.z = (float)sin(rad / 2.0f) * nShaft.z;
	
	return result;
}

VECTOR Quaternion::Rotate(const VECTOR target, const Quaternion rQot) {

	VECTOR result = VECTOR(target);
	Quaternion pQot = Quaternion();
	
	pQot.x = target.x;
	pQot.y = target.y;
	pQot.z = target.z;
	pQot.w = 1.0f;

	pQot = rQot * pQot * rQot.inv();

	result.x = pQot.x;
	result.y = pQot.y;
	result.z = pQot.z;

	return result;
}

Quaternion Quaternion::SphereLerp(Quaternion from, const Quaternion to, const float ratio) {

	float dotOfLerped = from.x * to.x + from.y * to.y + from.z * to.z + from.w * to.w;
	if (dotOfLerped < 0.0f) {
		from = -from;
		dotOfLerped *= -1.0f;
	}

	float arcAngle = acosf(dotOfLerped);

	float term1 = sinf(arcAngle * (1.0f - ratio)) / sinf(arcAngle);
	float term2 = sinf(arcAngle * ratio) / sinf(arcAngle);

	Quaternion result = Quaternion();
	result.x = term1 * from.x + term2 * to.x;
	result.y = term1 * from.y + term2 * to.y;
	result.z = term1 * from.z + term2 * to.z;
	result.w = term1 * from.w + term2 * to.w;
	return result;
}