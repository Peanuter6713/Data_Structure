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

void CreateList(SeqList &L)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10 + rand() % 6;
	L.length = i;
	sort(L.data,L.data+L.length);
}

void Display(SeqList L)
{
	int i;
	cout << "The numbers of the SeqList:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void DelSame(SeqList &L)
{
	int i, k = 1;
	ElemType e;
	e = L.data[0];
	for (i = 1; i < L.length; i++)
	{
		if (L.data[i] != e)
		{
			L.data[k] = L.data[i];
			k++;
			e = L.data[i];
		}
	}
	L.length = k;
}

int main()
{
	SeqList L;
	CreateList(L);
	Display(L);
	DelSame(L);
	Display(L);
	system("pause");
	return 0;
}

