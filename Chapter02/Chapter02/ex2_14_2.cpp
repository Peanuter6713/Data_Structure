#include <iostream>
#include <cstdlib>
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
	srand(time(NULL));
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
}

void Display(SeqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void Delete_X(SeqList &L, ElemType x)
{
	int i = 0, k = 0;
	while (i < L.length)
	{
		if (L.data[i] == x)
			k++;
		else
			L.data[i - k] = L.data[i];
		i++;
	}
	L.length -= k;
}

int main()
{
	SeqList L;
	ElemType x;
	CreateList(L);
	cout << "before deleting:" << endl;
	Display(L);
	cout << "Input X:" << endl;
	cin >> x;
	Delete_X(L, x);
	cout << "after deleting:" << endl;
	Display(L);
	system("pause");
	return 0;
}