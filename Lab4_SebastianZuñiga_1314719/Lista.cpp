#include "Lista.h"

using namespace System;

void Lista::Push(int val) {
	Nodo^ New = gcnew Nodo();
	New->Value = val;
	New->Next = Head;
	Head = New;
	Length++;
	if (Tail == nullptr)
		Tail = New;
}
void Lista::PushS(String^ val) {
	Nodo^ New = gcnew Nodo();
	New->SValue = val;
	New->Next = Head;
	Head = New;
	Length++;
}
int Lista::GetLength() {
	return Length;
}

bool Lista::Push2(int val, int index) {
	if (Head == nullptr) {
		Push(val);
		return true;
	}
	int i = 0;
	Nodo^ Current = Head;
	while (i < (index - 1) && Current != nullptr)
	{
		i++;
		Current = Current->Next;
	}
	if (Current == nullptr)
		return false;

	Nodo^ New = gcnew Nodo();
	New->Value = val;
	New->Next = Current->Next;
	Current->Next = New;
	Length++;
	return true;
}

int Lista::Search(int val) {
	int index = 0;
	Nodo^ Current = Head;
	while (Current->Value != val && Current != nullptr)
	{
		Current = Current->Next;
		index++;
	}
	if (Current == nullptr)
		return -1;
	else
	{
		return index;
	}
}

bool Lista::Delete(int val) {
	int index = Search(val);
	if (index == -1)
	{
		return false;
	}
	return DeleteIndex(val);
}

String^ Lista::Print() {
	int Text = 0;
	Nodo^ Current;
	String^ TextFinal = "";
	Current = Head;
	while (Current != nullptr)
	{
		Text = Current->Value;
		Current = Current->Next;
		TextFinal = Text + "";

	}
	return TextFinal;
}

int Lista::GetIndex(int index) {
	Nodo^ Current;
	Current = Head;
	int Retorno = 0;
	while (Current != nullptr && Retorno < index)
	{
		Current = Current->Next;
		Retorno++;
	}
	return Current->Value;
}

bool Lista::DeleteIndex(int index) {
	Nodo^ Anterior = Head;
	int i = 0;
	while (i < (index - 1))
	{
		Anterior = Anterior->Next;
		i++;
	}
	Nodo^ ToDelete = Anterior->Next;
	Anterior->Next = ToDelete->Next;
	delete ToDelete;
	Length--;
	return true;
}


bool Lista::IsSorted() {
	Nodo^ Current = Head;
	while (Current != nullptr && Current->Next != nullptr)
	{
		if (Current->Value > Current->Next->Value) {
			return false;
		}
	}
	return true;
}
bool Lista::IsEmpty() {
	if (Head == nullptr)
		return true;
	else
		return false;
}

String^ Lista::Pop() {
	if (IsEmpty())
		return nullptr;
	Length--;
	Nodo^ ToDelete = Head;
	Nodo^ Retorno = gcnew Nodo();
	Retorno->SValue = Head->SValue;
	String^ ValR = Retorno->SValue;
	Head = Head->Next;
	delete ToDelete;
	return ValR;
}

int Lista::PopNum() {
	if (IsEmpty())
		return 0;
	Length--;
	Nodo^ ToDelete = Head;
	Nodo^ Retorno = gcnew Nodo();
	Retorno->Value = Head->Value;
	int ValR = Retorno->Value;
	Head = Head->Next;
	delete ToDelete;
	return ValR;
}

void Lista::Show() {
}