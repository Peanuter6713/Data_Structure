#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
//#include "seqlist.h"  
using namespace std;


void CreateList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	sort(L.data, L.data + L.length);
}

void Display(SeqList L)
{
	int i;
	cout << "The numbers of the SeqList:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void DeleteSame(SeqList &L)
{
	int i, j = 0, k;
	for (i = 0; i < L.length; i++)
	{
		k = 0;
		while (k <= j && L.data[k] != L.data[i])
			k++;
		if (k > j)
		{
			j++;
			L.data[j] = L.data[i];
		}
	}
	L.length = j + 1;
}

void Union(SeqList A, SeqList B, SeqList &C)
{
	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length)
	{
		if (A.data[i] < B.data[j])
		{
			C.data[k] = A.data[i];
			i++;
			k++;
		}
		else if (A.data[i] > B.data[j])
		{
			C.data[k] = B.data[j];
			j++;
			k++;
		}
		else
		{
			C.data[k] = A.data[i];
			i++;
			j++;
			k++;
		}
	}
	
	while (i < A.length)
	{
		C.data[k] = A.data[i];
		i++; 
		k++;
	}

	while (j < B.length)
	{
		C.data[k] = B.data[j];
		j++;
		k++;
	}
	C.length = k;
}

int main()
{
	srand(time(NULL));
	SeqList A, B, C;
	CreateList(A);
	Display(A);
	CreateList(B);
	Display(B);
	Union(A,B,C);
	DeleteSame(C);
	Display(C);
	system("pause");
	return 0;

}