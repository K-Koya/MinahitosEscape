#include "DxLib.h"
#include "MapSample.h"

MapSample::MapSample()
{
	_position = new VECTOR();
	_posture = new Quaternion();
	*_position = VGet(200.0f, 100.0f, 0.0f);
	int handle = MV1LoadModel("Resource/Models/Map/SampleMap.mv1");
	_useModelHandlers.emplace_back(handle);
	MV1SetPosition(handle, *_position);
	_isUpdating = true;
	_isRendering = true;
}

MapSample::~MapSample()
{
	for (int handle : _useModelHandlers) {
		MV1DeleteModel(handle);
	}
}

void MapSample::update(const float deltaTime) {

	//ˆÊ’uÀ•W
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		_position->x += 0.5f;
	}
	else if(CheckHitKey(KEY_INPUT_LEFT)) {
		_position->x -= 0.5f;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		_position->z += 0.5f;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) {
		_position->z -= 0.5f;
	}

	//‰ñ“]Žp¨
	float rad = 0.0f;
	if (CheckHitKey(KEY_INPUT_COMMA)) {
		rad = 0.1f;
	}
	else if (CheckHitKey(KEY_INPUT_PERIOD)) {
		rad = -0.1f;
	}
	_posture->addAngleAxis(rad, { 0.0f, 1.0f, 0.0f });
		
	//Ý’è
	for (int handle : _useModelHandlers) {

		MV1SetMatrix(handle, MMult(_posture->getMatrix(), MGetTranslate(*_position)));
	}
}

void MapSample::render() {

	for (int handle : _useModelHandlers) {
		MV1DrawModel(handle);
	}
}
