#pragma once
#include <iostream>

template <class Tmp>
class MyList {
public:

	MyList(Tmp tmp) {
		_value = tmp;
		_next = nullptr;
		_prev = nullptr;
	}
	~MyList() {
		pop();
	};

	Tmp _value;
	MyList* _next;
	MyList* _prev;

	/// <summary>�������X�g�̐擪�ɂ���v�f���擾</summary>
	/// <returns>�擪�ɂ���v�f</returns>
	MyList* getFirst();
	/// <summary>�������X�g�̌���ɂ���v�f���擾</summary>
	/// <returns>����ɂ���v�f</returns>
	MyList* getLast();
	/// <summary>���ɗv�f��ǉ�</summary>
	/// <param name="tmp">���g</param>
	void pushNext(Tmp tmp);
	/// <summary>���ɗv�f��ǉ�</summary>
	/// <param name="tmp">���g</param>
	void pushBack(Tmp tmp);
	/// <summary>���̗v�f�ƈ����̗v�f�Ƃŏ��ԓ���ւ�</summary>
	/// <param name="tmp">���Ԃ̓���ւ���</param>
	void swap(MyList* element);
	/// <summary>���̗v�f�����X�g���痣�E</summary>
	void pop();
	/// <summary>���̗v�f�ƈ����̗v�f�Ƃŏ��ԓ���ւ�</summary>
	/// <param name="tmp">�T���������g</param>
	/// <returns>���̒��g�������X�g�v�f</returns>
	MyList<Tmp>* find(Tmp tmp);


};



template <class Tmp>
MyList<Tmp>* MyList<Tmp>::getFirst() {
	MyList* current = this;

	//�O�̗v�f��NULL�ɂȂ邩�A���g�Ɠ����v�f�ɂȂ�܂Ń��X�g�������̂ڂ�
	int cnt = 0;
	while (current->_prev != nullptr && current != current->_prev) {
		current = current->_prev;
	}

	return current;
}

template <class Tmp>
MyList<Tmp>* MyList<Tmp>::getLast() {
	MyList* current = this;

	//���̗v�f��NULL�ɂȂ邩�A���g�Ɠ����v�f�ɂȂ�܂Ń��X�g������
	while (current->_next != nullptr && current != current->_next) {
		current = current->_next;
	}

	return current;
}

template <class Tmp>
void MyList<Tmp>::pushNext(Tmp tmp) {

	MyList* oldNext = _next;
	_next = new MyList<Tmp>(tmp);
	_next->_prev = this;

	//���Â̎��v�f���A����΂��̃A�N�Z�b�T�̑���
	if (oldNext != nullptr) {
		oldNext->_prev = _next;
		_next->_next = oldNext;
	}
}

template <class Tmp>
void MyList<Tmp>::pushBack(Tmp tmp) {

	MyList* oldPrev = _prev;
	_prev = new MyList<Tmp>(tmp);
	_prev->_next = this;

	//���Â̑O�v�f���A����΂��̃A�N�Z�b�T�̑���
	if (oldPrev != nullptr) {
		oldPrev->_next = _prev;
		_prev->_prev = oldPrev;
	}
}

template <class Tmp>
void MyList<Tmp>::swap(MyList* element) {
	Tmp tmp = element->_value;
	element->_value = _value;
	_value = tmp;
}

template <class Tmp>
void MyList<Tmp>::pop() {
	MyList* hadPrev = _prev;
	_prev->_next = _next;
	_next->_prev = hadPrev;
}

template <class Tmp>
MyList<Tmp>* MyList<Tmp>::find(Tmp tmp) {
	//���\�b�h�Ăяo�����̗v�f�����Ɉ���f�[�^�̓˂����킹������
	MyList* current = this;
	MyList* returnal = nullptr;

	while (current != nullptr) {

		if (current->_value == tmp) return current;
		else
		{
			current = current->_next;
		}
	}

	current = this;
	while (current != nullptr) {

		if (current->_value == tmp) return current;
		else
		{
			current = current->_prev;
		}
	}

	return nullptr;
}
