#pragma once
#include <iostream>
#include "clsMyQueue.h"
using namespace std;
template <class T>
class clsDynamicArray : public clsMyQueue <T>
{
protected:
	int _Size = 0;
	T* _TempArray;
public:
	T* OriginalArray;
	clsDynamicArray(int Size = 0) {
		if (Size < 0)
			Size = 0;
		
		_Size = Size;
		OriginalArray = new T[_Size];
	}
	~clsDynamicArray() {
		delete[] OriginalArray;
	}
	bool SetItem(int Index, T value) {
		if (Index >= _Size || Index < 0)
			return false;
		OriginalArray[Index] = value;
		return true;
	}
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		return (_Size == 0) ? true : false;
	}
	void PrintList() {
		for (int i = 0; i < _Size; i++) {
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}
	void Resize(int NewSize) {
		if (NewSize < 0)
			NewSize = 0;
		if (NewSize < _Size)
			_Size = NewSize;

		_TempArray = new T[NewSize];
		for (int i = 0; i < _Size; i++) {
			_TempArray[i] = OriginalArray[i];
		}
		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	T GetItem(int Index) {
		return OriginalArray[Index];
	}
	void Reverse() {
		_TempArray = new T[_Size];
		for (int i = 0; i < _Size; i++)
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	bool DeleteItemAt(int Index) {
		
		if (Index >= _Size || Index < 0)
			return false;
		_Size--;
		_TempArray = new T[_Size];
		int counter = 0;
		for (int i = 0; i < Index; i++) {
			_TempArray[i] = OriginalArray[i];
		}
		for (int i = Index + 1; i < _Size + 1; i++) {
			_TempArray[i - 1] = OriginalArray[i];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	void DeleteFirstItem() {
		DeleteItemAt(0);
	}
	void DeleteLastItem() {
		DeleteItemAt(_Size - 1);
	}
	bool DeleteItem(T value) {
		return DeleteItemAt(Find(value));
	}
	int Find(T value) {
		for (int i = 0; i < _Size; i++) {
			if (value == OriginalArray[i])
				return i;
		}
		return -1;
	}
	bool InsertAt(int Index, T value) {
		
		if (Index > _Size || Index < 0)
			return false;
		_Size++;
		_TempArray = new T[_Size];
		
		for (int i = 0; i < Index; i++)
			_TempArray[i] = OriginalArray[i];
		_TempArray[Index] = value;
		for (int i = Index; i < _Size - 1; i++)
			_TempArray[i + 1] = OriginalArray[i];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	void InsertAtBeginning(T value) {
		InsertAt(0, value);
	}
	bool InsertAtEnd(T value) {
		return InsertAt(_Size, value);
	}
	bool InsertAfter(int Index,T value) {
		if (Index >= _Size)
			return InsertAt(_Size - 1, value);
		else
		    return InsertAt(Index + 1, value);
	}
	bool InsertBefore(int Index, T value) {
		if (Index < 1)
			return InsertAt(0, value);
		else
		    return InsertAt(Index - 1, value);
	}
};

