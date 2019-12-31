#include <iostream>
using namespace std;
#define MaxLen 20
#define Elemtype int

typedef struct
{
	Elemtype data[MaxLen];
	int length;
}SeqList;
/*
void createList(SeqList &L)
{
	int i, len;
	cout << "Input the length of the array:" << endl;
	cin >> len;
	cout << "Input the numbers of the array:" << endl;
	for (i = 0; i < len; i++)
		cin >> L.data[i];
	L.length = len;
}
*/

void createList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = i;
	L.length = i;
}

void Print(SeqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void reverse(int R[], int left, int right)
{
	int k = left, j = right, tmp = 0;
	while (k < j)
	{
		tmp = R[k];
		R[k] = R[j];
		R[j] = tmp;
		k++;
		j--;
	}
	
}

void leftShift(int R[], int n, int p)
{
	if (p > 0 && p < n)
	{
		reverse(R, 0, n - 1);
		reverse(R, 0, n - p - 1);
		reverse(R, n - p, n - 1);
	}
}

int main()
{
	SeqList L;
	createList(L);	
	cout << "Original: " << endl;
	Print(L);
	cout << "leftShift: " << endl;
	leftShift(L.data, L.length, 3);
	Print(L);
	system("pause");
	return 0;
}