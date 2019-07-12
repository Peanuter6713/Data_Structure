#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

#define MaxLen 20
#define ElemType int

typedef struct
{
	ElemType data[MaxLen];
	int length;
}SeqList;

void CreateList(SeqList &L);
void DeleteSame(SeqList &L);
void Display(SeqList L);
void Merge(SeqList A, SeqList &B);

void CreateList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	sort(L.data, L.data + L.length);
	DeleteSame(L);
}

void DeleteSame(SeqList &L)
{
	int i, j = 0, k;
	for (i = 1; i < L.length; i++)
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

void Display(SeqList L)
{
	int i;
	cout << "The numbers of the SeqList:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void Merge(SeqList A, SeqList &B)
{
	int i = 0, j = 0, k;
	while (i < A.length)
	{
		if (A.data[i] > B.data[B.length - 1])
		{
			B.data[B.length] = A.data[i];
			B.length++;
			i++;
		}
		else if (A.data[i] < B.data[j])
		{
			for (k = B.length - 1; k >= j; k--)
				B.data[k + 1] = B.data[k];
			B.data[j] = A.data[i];
			B.length++;
			i++;
			j++;
		}
		else
			j++;
	}
}

int main()
{
	srand(time(NULL));
	SeqList A, B;
	CreateList(A);
	Display(A);
	CreateList(B);
	Display(B);
	Merge(A, B);
	DeleteSame(B);
	Display(B);
	system("pause");
	return 0;
}