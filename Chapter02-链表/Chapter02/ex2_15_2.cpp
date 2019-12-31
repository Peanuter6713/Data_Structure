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
		L.data[i] = rand() % 6 + 7;
	L.length = i;
}

void Diaplay(SeqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void Delete_X_Y(SeqList &L, ElemType x, ElemType y)
{
	int i = 0, k = 0;
	while (i < L.length)
	{
		if (L.data[i] >= x && L.data[i] <= y)
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
	ElemType x, y;
	CreateList(L);
	cout << "The numbers of the List:" << endl;
	Diaplay(L);
	cout << "Input x & y:" << endl;
	cin >> x >> y;
	Delete_X_Y(L, x, y);
	cout << "between x & y has been deleted." << endl;
	Diaplay(L);
	system("pause");
	return 0;
}