#pragma once
#include <iostream>
#include "clsMyQueueArr.h"
#include "clsDblLinkedList.h"
#include "clsDynamicArray.h"
using namespace std;
template <class T>
class clsMyStackArr : public clsMyQueueArr <T>
{
public:
	void push(T item) {
		clsMyQueueArr <T>::_Array.InsertAtBeginning(item);
	}

	T Top() {
		return clsMyQueueArr <T>::front();
	}
	T Bottom() {
		return clsMyQueueArr <T>::back();
	}
};

