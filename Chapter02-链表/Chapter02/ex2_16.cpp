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
		L.data[i] = rand() % 13 - 7;
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

void Move(SeqList &L)
{
	ElemType temp;
	int i = 0, j = L.length - 1;
	while (i < j)
	{
		while (i < j && L.data[i] < 0)
			i++;
		while (i < j && L.data[j] > 0)
			j--;
		if (i < j)
		{
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
}

int main()
{
	SeqList L;
	CreateList(L);
	Display(L);
	Move(L);
	Display(L);
	system("pause");
	return 0;
}
















