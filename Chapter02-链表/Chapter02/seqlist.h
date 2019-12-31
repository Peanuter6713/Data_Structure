/*   This is a test  */
#include <iostream>
using namespace std;

#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#define MaxLen 20
#define ElemType int 

typedef struct
{
	ElemType data[MaxLen];
	int length;
}SeqList;

void CreateList(SeqList &L);
void DeleteSame(SeqList &L);
void Union(SeqList A, SeqList B, SeqList &C);

void CreateList(SeqList &L)
{
	int i;
	for (i = 0; i < 10; i++)
		L.data[i] = rand() % 10;
	L.length = i;
	sort(L.data, L.data + L.length);
}


void Display(SeqList L)
{
	int i;
	cout << "The numbers of the SeqList:" << endl;
	for (i = 0; i < L.length; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

#endif
