#pragma once
#include <iostream>
#include "Mylist.h"

template <class Tmp>
class ForkList : public MyList<Tmp> {
public:

	ForkList(Tmp tmp) : MyList<Tmp>(tmp) {
		_parent = nullptr;
		_childFirst = nullptr;
	}

	~ForkList() {
		for (ForkList<Tmp>* forked : _children) {
			forked.delete();
		}
	}

	ForkList* _parent;
	ForkList* _childFirst;

	/// <summary>�����v�f�������̐e�ɐݒ�</summary>
	/// <param name="parent">�e�ɂ������v�f</param>
	void setParent(ForkList* parent);
	/// <summary>�����v�f�������̎q�ɐݒ�</summary>
	/// <param name="child">�q�ɂ������v�f</param>
	void setChild(ForkList* child);
	/// <summary>�����̐e�̗v�f���擾</summary>
	/// <returns>�e�̗v�f</returns>
	ForkList* getParent();
	/// <summary>�����̎q�̗v�f���擾</summary>
	/// /// <param name="index">�v�f�ԍ�</param>
	/// <returns>�q�̗v�f</returns>
	ForkList* getChild(int index);
};

template <class Tmp>
ForkList<Tmp>* ForkList<Tmp>::getParent() {
	return _parent;
}

template <class Tmp>
ForkList<Tmp>* ForkList<Tmp>::getChild(int index) {
	ForkList* current = _childFirst;

	for (int i = 0; i < index; i++) {

	}

	return current;
}