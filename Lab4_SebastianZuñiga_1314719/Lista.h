#pragma once
#include "Nodo.h"
using namespace System;

ref class Lista
{
public:
	Nodo^ Head;
	Nodo^ Tail;

public:
	int Length;
	int GetLength();
	void Push(int val);
	void PushS(String^ Val);
	bool Push2(int val, int index);
	String^ Print();
	int Search(int val);
	bool Delete(int val);
	int GetIndex(int index);
	bool DeleteIndex(int index);
	bool IsSorted();
	String^ Pop();
	int PopNum();
	bool IsEmpty();
	void Show();
};

