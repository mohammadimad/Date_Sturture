#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;
template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;
public :
	void push(T item) {
		_MyList.InsertAtEnd(item);
	}
	void pop() {
		_MyList.DeleteFirstNode();
	}
	int Size() {
		return _MyList.Size();
	}
	void Print() {
		_MyList.PrintList();
	}
	T front() {
		//clsDblLinkedList<int>GetItem(0);
		return _MyList.GetItem(0);
	}
	T back() {
		return _MyList.GetItem(Size() - 1);
	}
	void Reverse() {
		_MyList.Reverse();
	}
	bool UpdateItem(int Index, T value) {
		return _MyList.UpdateItem(Index, value);
	}
	bool InsertAfter(int Index, T value) {
		return _MyList.InsertAfter(Index, value);
	}
	void InsertAtFront(T value) {
		 _MyList.InsertAtBeginning(value);
	}
	void InsertAtBack(T value) {
	     _MyList.InsertAtEnd(value);
	}
    void Clear() {
		_MyList.Clear();
	}
	T GetItem(int Index) {
		return _MyList.GetItem(Index);
	}
};

