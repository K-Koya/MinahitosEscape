#pragma once
#include "../../Virtual/Updatable.h"
#include "../../Virtual/Transform.h"
#include "../../Virtual/Renderable.h"


class MapSample : public Updatable, public Transform, public Renderable
{
public:
	MapSample();
	~MapSample();

	void update(float deltaTime) override;
	void render() override;

private:

};