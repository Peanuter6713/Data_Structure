#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define MaxLen 20
#define ElemType int

typedef struct
{
	ElemType data[MaxLen];
	int length;
}SeqList;

void CreateList(SeqList &L)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10 + 6;
	L.length = i;
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

int main()
{
	SeqList L;
	CreateList(L);
	Display(L);
	DeleteSame(L);
	Display(L);
	system("pause");
	return 0;
}