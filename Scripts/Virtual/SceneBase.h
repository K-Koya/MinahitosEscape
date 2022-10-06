#pragma once
#include <functional>

class SceneBase {
public:

	SceneBase() {}
	~SceneBase() {}

	/// <summary>���t���[�����s���\�b�h</summary>
	virtual void update(float deltaTime) = 0;

	/// <summary>�`�惁�\�b�h</summary>
	virtual void render() = 0;
};
