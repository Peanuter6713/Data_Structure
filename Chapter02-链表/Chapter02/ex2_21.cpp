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
} SeqList;

void CreateList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	
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
	int i, j, k;
	for (i = 0; i < A.length; i++)
		C.data[i] = A.data[i];
	k = A.length;
	for (i = 0; i < B.length; i++)
	{
		j = 0;
		while (j < A.length && B.data[i] != A.data[j])
			j++;
		if (j == A.length)
			C.data[k++] = B.data[i];
	}
	C.length = k;
}

void Display(SeqList L)
{
	int i;
	cout << "The numbers of the SeqList:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(NULL));
	SeqList A, B, C;
	CreateList(A);
	Display(A);
	CreateList(B);
	Display(B);
	Union(A, B, C);
	DeleteSame(C);
	Display(C);
	system("pause");
	return 0;
}