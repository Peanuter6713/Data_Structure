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
 
void DeleteSame(SeqList &L);

void CreateList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	sort(L.data, L.data + L.length);
	DeleteSame(L);
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

void Merge(SeqList A, SeqList B, SeqList &C)
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
		else
		{
			C.data[k] = B.data[j];
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
/* A B 中有重复元素 */
int main()
{
	srand(time(NULL));
	SeqList A, B, C;
	CreateList(A);
	Display(A);
	CreateList(B);
	Display(B);
	Merge(A, B, C);
	DeleteSame(C);
	Display(C);
	system("pause");
	return 0;
}