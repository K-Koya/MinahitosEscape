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

	/// <summary>所属リストの先頭にある要素を取得</summary>
	/// <returns>先頭にある要素</returns>
	MyList* getFirst();
	/// <summary>所属リストの後尾にある要素を取得</summary>
	/// <returns>後尾にある要素</returns>
	MyList* getLast();
	/// <summary>次に要素を追加</summary>
	/// <param name="tmp">中身</param>
	void pushNext(Tmp tmp);
	/// <summary>後ろに要素を追加</summary>
	/// <param name="tmp">中身</param>
	void pushBack(Tmp tmp);
	/// <summary>この要素と引数の要素とで順番入れ替え</summary>
	/// <param name="tmp">順番の入れ替わり先</param>
	void swap(MyList* element);
	/// <summary>この要素をリストから離脱</summary>
	void pop();
	/// <summary>この要素と引数の要素とで順番入れ替え</summary>
	/// <param name="tmp">探したい中身</param>
	/// <returns>その中身を持つリスト要素</returns>
	MyList<Tmp>* find(Tmp tmp);


};



template <class Tmp>
MyList<Tmp>* MyList<Tmp>::getFirst() {
	MyList* current = this;

	//前の要素がNULLになるか、自身と同じ要素になるまでリストをさかのぼる
	int cnt = 0;
	while (current->_prev != nullptr && current != current->_prev) {
		current = current->_prev;
	}

	return current;
}

template <class Tmp>
MyList<Tmp>* MyList<Tmp>::getLast() {
	MyList* current = this;

	//次の要素がNULLになるか、自身と同じ要素になるまでリストを下る
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

	//お古の次要素を、あればそのアクセッサの操作
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

	//お古の前要素を、あればそのアクセッサの操作
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
	//メソッド呼び出し元の要素から後に一つずつデータの突き合わせをする
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
