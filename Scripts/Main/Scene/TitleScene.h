#pragma once
#include "../../Virtual/SceneBase.h"
#include "../Updatable/MapSample.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();

private:

};

TitleScene::TitleScene() : SceneBase()
{
	MapSample* mapSample = new MapSample();
	_updateObjects.emplace_back(mapSample);
	_renderObjects.emplace_back(mapSample);
}

TitleScene::~TitleScene()
{
	
}
