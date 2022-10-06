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

	/// <summary>引数要素を自分の親に設定</summary>
	/// <param name="parent">親にしたい要素</param>
	void setParent(ForkList* parent);
	/// <summary>引数要素を自分の子に設定</summary>
	/// <param name="child">子にしたい要素</param>
	void setChild(ForkList* child);
	/// <summary>自分の親の要素を取得</summary>
	/// <returns>親の要素</returns>
	ForkList* getParent();
	/// <summary>自分の子の要素を取得</summary>
	/// /// <param name="index">要素番号</param>
	/// <returns>子の要素</returns>
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