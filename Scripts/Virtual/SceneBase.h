#pragma once

class SceneBase {
public:

	SceneBase() {}
	virtual ~SceneBase() {}

	/// <summary>���������\�b�h</summary>
	virtual void initialzie() = 0;

	/// <summary>�`�惁�\�b�h</summary>
	virtual void render() {}
};
