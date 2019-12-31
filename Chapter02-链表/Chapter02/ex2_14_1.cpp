#include <iostream>
using namespace std;
#define MaxLen 10
#define ElemType int

typedef struct 
{
	ElemType data[MaxLen];
	int length;
}SeqList;

void CreateList(SeqList &L)
{
	int i, len;
	cout << "Input the length of the list:" << endl;
	cin >> len;
	cout << "Input the numbers:" << endl;
	for (i = 0; i < len; i++)
		cin >> L.data[i];
	L.length = len;
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
	int i, k = 0;
	for(i=0; i<L.length; i++)
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];
			k++;
		}
	L.length = k;
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