#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

#define MaxLen 30
#define ElemType int 

typedef struct
{
	ElemType data[MaxLen];
	int length;
}SeqList;

void CreateList(SeqList &L);
void DeleteSame(SeqList &L);
void Merge(SeqList &A, int m, int n);
void Display(SeqList L);
void GenerateA(SeqList &A, SeqList AA, int &lenA, int &lenAA);


void CreateList(SeqList &L)  
{	
	int i;	
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 100;
	L.length = i;
	sort(L.data, L.data + L.length);	 
	DeleteSame(L);
}

void Merge(SeqList &A, int m, int n)
{
	SeqList B, C;           // 建立两个临时顺序表
	int i, j , k = 0;
	for (i = m, j = 0; i < m + n; i++, j++)  // 将A的后部分复制到B中
		B.data[j] = A.data[i];
	i = 0, j = 0;
	while (i < m && j < n)       // 将A、B归并到C中
	{
		if (A.data[i] < B.data[j])
		{
			C.data[k] = A.data[i];
			i++; k++;
		}
		else
		{
			C.data[k] = B.data[j];
			j++; k++;
		}
	}

	while (i < m)
	{
		C.data[k] = A.data[i];
		i++;
		k++;
	}
	
	while (j < n)
	{
		C.data[k] = B.data[j];
		j++; 
		k++;
	}
	for (i = 0; i < m + n; i++)    // Copy C into A
  		A.data[i] = C.data[i];

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

void Display(SeqList L)
{
	int i;
	cout << "The numbers are:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void GenerateA(SeqList &A, SeqList AA, int &lenA, int &lenAA)  // 生成长度为 m+n 的顺序表
{
	int i;
	lenA = A.length;
	lenAA = AA.length;
	for (i = 0; i < AA.length; i++)
	{
		A.data[A.length] = AA.data[i];
		A.length++;
	}
		
}

int main()
{
	srand(time(NULL));
	SeqList A, AA;	
	int lenA, lenAA;    // 保存两表的长度 用于 m n
	CreateList(A);
	Display(A);
	CreateList(AA);
	Display(AA);
	GenerateA(A, AA, lenA, lenAA);
	Display(A);
	Merge(A,lenA,lenAA);
	Display(A);
	DeleteSame(A);
	Display(A);
	system("pause");
	return 0;
}