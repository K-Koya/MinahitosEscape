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

Quaternion* Quaternion::AngleAxis(const float rad, VECTOR shaft) {

	shaft = VNorm(shaft);
	Quaternion* result = new Quaternion();
	result->w = (float)cos(rad / 2.0f);
	result->x = (float)sin(rad / 2.0f) * shaft.x;
	result->y = (float)sin(rad / 2.0f) * shaft.y;
	result->z = (float)sin(rad / 2.0f) * shaft.z;
	
	return result;
}

VECTOR* Quaternion::Rotate(const VECTOR target, const Quaternion rQot) {

	VECTOR* result = new VECTOR(target);
	Quaternion pQot = Quaternion();
	
	pQot.x = target.x;
	pQot.y = target.y;
	pQot.z = target.z;
	pQot.w = 1.0f;

	pQot = rQot * pQot * rQot.inv();

	result->x = pQot.x;
	result->y = pQot.y;
	result->z = pQot.z;

	return result;
}

Quaternion* Quaternion::SphereLerp(Quaternion from, const Quaternion to, const float ratio) {

	float dotOfLerped = from.x * to.x + from.y * to.y + from.z * to.z + from.w * to.w;
	if (dotOfLerped < 0.0f) {
		from = -from;
		dotOfLerped *= -1.0f;
	}

	float arcAngle = acosf(dotOfLerped);

	float term1 = sinf(arcAngle * (1.0f - ratio)) / sinf(arcAngle);
	float term2 = sinf(arcAngle * ratio) / sinf(arcAngle);

	Quaternion* result = new Quaternion();
	result->x = term1 * from.x + term2 * to.x;
	result->y = term1 * from.y + term2 * to.y;
	result->z = term1 * from.z + term2 * to.z;
	result->w = term1 * from.w + term2 * to.w;
	return result;
}