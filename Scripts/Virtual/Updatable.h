#pragma once

/// <summary>���t���[���Ăяo���������\�b�h�����鎞�Ɍp��</summary>
class Updatable 
{
public:

	/// <summary>�V�[������Ăяo���A���t���[�����s���\�b�h</summary>
	void doUpdate(const float deltaTime);

	/// <summary>true : ���t���[�����s����</summary>
	bool _isUpdating;

protected: 

	/// <summary>���t���[�����s���������������L�q</summary>
	/// <param name="deltaTime">1�t���[��������̎���</param>
	virtual void update(const float deltaTime) = 0;

private:


};