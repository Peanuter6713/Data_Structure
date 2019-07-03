#include <iostream>
using namespace std;
#define MaxLen 20
#define Elemtype int

typedef struct
{
	Elemtype data[MaxLen];
	int length;
}SeqList;

void createList(SeqList &L)
{
	int i;
	for (i = 0; i < 5; i++)
		L.data[i] = i;
	L.length = i;
}

void Print(SeqList L)
{
	int j;
	for (j = 0; j < L.length; j++)
		cout << L.data[j] << " ";
	cout << endl;
}

void reverse(SeqList &L)
{
	int k;
	Elemtype x;
	for (k = 0; k < L.length/2; k++)
	{
		x = L.data[k];
		L.data[k] = L.data[L.length - k - 1];
		L.data[L.length - k - 1] = x;
	}
}

int main()
{
	SeqList L;
	createList(L);
	cout << "before reversing: " << endl;
	Print(L);
	cout << "after reversing:" << endl;
	reverse(L);
	Print(L);
	system("pause");
	return 0;
}