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
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void Delete_X_Y(SeqList &L, ElemType x, ElemType y)
{
	int i, k = 0;
	for (i=0; i<L.length; i++)
		if (!(L.data[i] >= x && L.data[i] <= y))
		{
			L.data[k] = L.data[i];
			k++;
		}
	L.length = k;

}

int main()
{
	SeqList L;
	ElemType x, y;
	CreateList(L);
	cout << "Original:" << endl;
	Display(L);
	cout << "Input x & y:" << endl;
	cin >> x >> y;
	Delete_X_Y(L, x, y);
	cout << "after deleting:" << endl;
	Display(L);
	system("pause");
	return 0;
}