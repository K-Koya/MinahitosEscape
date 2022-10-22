#pragma once
#include <vector>
#include "Transform.h"
#include "Updatable.h"
#include "Renderable.h"

class SceneBase {
public:

	SceneBase();
	virtual ~SceneBase();

	/// <summary>位置・姿勢情報を持つオブジェクト</summary>
	std::vector<Transform*> _transformObjects;

	/// <summary>毎フレーム実行したいメソッドがあるオブジェクト</summary>
	std::vector<Updatable*> _updateObjects;

	/// <summary>画面上に表示させたいオブジェクト</summary>
	std::vector<Renderable*> _renderObjects;

	/// <summary>true : 初期化済みである</summary>
	bool _isInitialized = false;

	/// <summary>初めのフレームだけ実行する初期化メソッド</summary>
	virtual void initialize() {};

	/// <summary>毎フレーム実行メソッド</summary>
	void update(const float deltaTime);

	/// <summary>描画メソッド</summary>
	void render();
};

inline SceneBase::SceneBase() {
	_isInitialized = false;
}

inline SceneBase::~SceneBase() {

	//順に削除
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