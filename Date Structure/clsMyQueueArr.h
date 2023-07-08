#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;
template <class T>
class clsMyQueueArr
{
protected :
	clsDynamicArray <T> _Array;
public :
	void push(T item) {
		_Array.InsertAtEnd(item);
	}
	void pop() {
		_Array.DeleteFirstItem();
	}
	
	int Size() {
		return _Array.Size();
	}
	void Print() {
		_Array.PrintList();
	}
	T front() {
		//clsDblLinkedList<int>GetItem(0);
		return _Array.GetItem(0);
	}
	T back() {
		return _Array.GetItem(Size() - 1);
	}
	void Reverse() {
		_Array.Reverse();
	}
	bool UpdateItem(int Index, T value) {
		return _Array.SetItem(Index, value);
	}
	bool InsertAfter(int Index, T value) {
		return _Array.InsertAfter(Index, value);
	}
	void InsertAtFront(T value) {
		_Array.InsertAtBeginning(value);
	}
	void InsertAtBack(T value) {
		_Array.InsertAtEnd(value);
	}
	void Clear() {
		_Array.Clear();
	}
	T GetItem(int Index) {
		return _Array.GetItem(Index);
	}
};

