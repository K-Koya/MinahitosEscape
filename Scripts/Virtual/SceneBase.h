#pragma once
#include <vector>
#include "Transform.h"
#include "Updatable.h"
#include "Renderable.h"

class SceneBase {
public:

	SceneBase();
	virtual ~SceneBase();

	/// <summary>�ʒu�E�p���������I�u�W�F�N�g</summary>
	std::vector<Transform*> _transformObjects;

	/// <summary>���t���[�����s���������\�b�h������I�u�W�F�N�g</summary>
	std::vector<Updatable*> _updateObjects;

	/// <summary>��ʏ�ɕ\�����������I�u�W�F�N�g</summary>
	std::vector<Renderable*> _renderObjects;

	/// <summary>true : �������ς݂ł���</summary>
	bool _isInitialized = false;

	/// <summary>���߂̃t���[���������s���鏉�������\�b�h</summary>
	virtual void initialize() {};

	/// <summary>���t���[�����s���\�b�h</summary>
	void update(const float deltaTime);

	/// <summary>�`�惁�\�b�h</summary>
	void render();
};

inline SceneBase::SceneBase() {
	_isInitialized = false;
}

inline SceneBase::~SceneBase() {

	//���ɍ폜
	auto txObj_it = _transformObjects.begin();
	while (txObj_it != _transformObjects.end()) {
		txObj_it = _transformObjects.erase(txObj_it);
		txObj_it++;
	}
	auto updObj_it = _updateObjects.begin();
	while (updObj_it != _updateObjects.end()) {
		updObj_it = _updateObjects.erase(updObj_it);
		updObj_it++;
	}
	auto rndObj_it = _renderObjects.begin();
	while (rndObj_it != _renderObjects.end()) {
		rndObj_it = _renderObjects.erase(rndObj_it);
		rndObj_it++;
	}
}

inline void SceneBase::update(const float deltaTime) {
	if (!_isInitialized) {
		initialize();
		_isInitialized = true;
	}

	auto updObj_it = _updateObjects.begin();
	while (updObj_it != _updateObjects.end()) {
		(*updObj_it)->doUpdate(deltaTime);
		updObj_it++;
	}
}

inline void SceneBase::render() {
	auto rndObj_it = _renderObjects.begin();
	while (rndObj_it != _renderObjects.end()) {
		(*rndObj_it)->doRender();
		rndObj_it++;
	}
}