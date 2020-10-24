#include "Ordenamiento.h"
#include "Lista.h"
using namespace System;

void Ordenamiento::BurbujaOpe(Lista^ lis) {
	int i;
	int IndexCambio;
	i = lis->Length - 1;
	while (i > 0)
	{
		IndexCambio = 0;
		for (int j = 0; j < i; j++)
		{
			if (lis->GetIndex(j + 1) < lis->GetIndex(j)) {
				Swap(lis, j, j + 1);
				IndexCambio = j;
			}
			i = IndexCambio;
		}
	}
}

void Ordenamiento::Shuffle(Lista^ lis) {
	for (int i = 0; i < lis->Length; i++)
	{
		Random rnd;
		Swap(lis, i, rnd.Next(0, lis->Length));
	}
}

void Ordenamiento::Swap(Lista^ lis, int i, int j) {
	int aux = lis->GetIndex(i);
	int aux2 = lis->GetIndex(j);
	lis->DeleteIndex(i);
	lis->Push2(aux2, i);
	lis->DeleteIndex(j);
	lis->Push2(aux, j);
}

void Ordenamiento::StupidOpe(Lista^ lis) {
	while (!lis->IsSorted())
	{
		Shuffle(lis);
	}
}