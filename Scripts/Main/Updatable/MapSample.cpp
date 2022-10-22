#include "DxLib.h"
#include "MapSample.h"

MapSample::MapSample()
{
	int handle = MV1LoadModel("Resource/Models/Map/SampleMap.mv1");
	_useModelHandlers.emplace_back(handle);
	MV1SetPosition(handle, VGet(0.0f, 0.0f, 0.0f));
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

}

void MapSample::render() {

	for (int handle : _useModelHandlers) {
		MV1DrawModel(handle);
	}
}
