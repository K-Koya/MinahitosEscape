#pragma once

/// <summary>���t���[���`�悵�������̂����鎞�Ɍp��</summary>
class Renderable 
{
public:

	/// <summary>�V�[������Ăяo���A���t���[���`�惁�\�b�h</summary>
	void doRender();

	/// <summary>true : ���t���[���`�悷��</summary>
	bool _isActive;

private:

	/// <summary>���t���[���`�悷�鏈�����L�q</summary>
	virtual void render() = 0;
};
