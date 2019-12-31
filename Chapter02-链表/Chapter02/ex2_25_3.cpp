/* 主要与书上的两表无不重复元素的要求不一样 懒得用输入的方法建表 所以修改了伪代码部分 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

#define MaxLen 25
#define ElemType int

typedef struct
{
	ElemType data[MaxLen];
	int length;
}SeqList;

void CreateList(SeqList &L);   // 重载函数
void CreateList(SeqList &L, int &lengthA);
void DeleteSame(SeqList &L);
void Merge(SeqList &A, int m);
void MergeAB(SeqList &A, SeqList B);
void Display(SeqList L);

void CreateList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	sort(L.data, L.data + L.length);
	DeleteSame(L);
}

void CreateList(SeqList &L, int &lengthA)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	sort(L.data, L.data + L.length);
	DeleteSame(L);
	lengthA = L.length;    // 应该还可以放入DeleteSame函数  未尝试
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

void Merge(SeqList &A, int m)
{
	int i = 0, j = m, k;
	ElemType temp;
	while (j < A.length && i < j)
	{
		if (A.data[j] > A.data[j - 1])
			break;
		else if (A.data[j] <= A.data[i])
		{
			temp = A.data[j];
			for (k = j - 1; k >= i; k--)
				A.data[k + 1] = A.data[k];
			A.data[i] = temp;
			i++;
			j++;
		}
		else 
			i++;
	}
}

void MergeAB(SeqList &A, SeqList B)  // 用于生成符合条件的线性表
{
	int i;
	for (i = 0; i < B.length; i++)
	{
		A.data[A.length] = B.data[i];
		A.length++;
	}
		
}

void Display(SeqList L)
{
	int i;
	cout << "The numbers of the SeqList:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(NULL));
	SeqList A, B;
	int lengthA;  //  用于记住A的长度
	CreateList(A,lengthA);
	CreateList(B);
	MergeAB(A, B);
	Display(A);
	Merge(A, lengthA);
	Display(A);
	cout << "After deleting the same elemt:" << endl;
	DeleteSame(A);
	Display(A);
	system("pause");
	return 0;

}