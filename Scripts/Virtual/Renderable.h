#pragma once
#include <vector>

/// <summary>���t���[���`�悵�������̂����鎞�Ɍp��</summary>
class Renderable 
{
public:

	/// <summary>�����_�����O����I�u�W�F�N�g�̃n���h���ϐ�</summary>
	std::vector<int> _useModelHandlers;

	/// <summary>true : ���t���[���`�悷��</summary>
	bool _isRendering;

	/// <summary>�V�[������Ăяo���A���t���[���`�惁�\�b�h</summary>
	void doRender();


private:

	/// <summary>���t���[���`�悷�鏈�����L�q</summary>
	virtual void render() = 0;
};
