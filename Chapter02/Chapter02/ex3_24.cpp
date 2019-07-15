#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

#define ElemType int

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}Node, *LinkList;

void CreateListByHead(LinkList &L);
void CreateListByTail(LinkList &L);
void Display(LinkList L);
int  DeletePre(LinkList &L, ElemType x);

void CreateListByHead(LinkList &L)
{
	int i;
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (i = 0; i < 10; i++)
	{
		s = new Node;
		s->data = rand() % 10;
		s->next = L->next;
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)
{
	LinkList s, r;
	int i;
	L = new Node;
	L->next = NULL;
	r = L;
	for (i = 0; i < 10; i++)
	{
		s = new Node;
		s->data = rand() % 10;
		r->next = s;
		r = s;
	}
	r->next = NULL;  // Don't forget this
}

void Display(LinkList L)
{
	LinkList s;
	s = L->next;
	cout << "The numbers are :" << endl;
	while (s)
	{
		cout <<s->data<< " ";
		s = s->next;
	}
	cout << endl;
}

int DeletePre(LinkList &L, ElemType x)
{
	LinkList prepre = L, pre = prepre->next, p;
	p = pre->next;										 // Don't forget it !
	if (pre->data == x)
		return 0;

	while (p != NULL && p->data != x)
	{
		prepre = pre;
		pre = p;
		p = p->next;
	}
	if (p)   // p != NULL
	{
		prepre->next = p;  //  equals   prepre->next = pre->next;		
		free(pre);
		return 1;
	}
	else return 0;
}

int main()
{
	LinkList L;
	ElemType x;
	//CreateListByHead(L);
	CreateListByTail(L);
	Display(L);
	cout << "Input the x:" << endl;
	cin >> x;
	DeletePre(L, x);
	cout << "The number before x is deleted:" << endl;
	Display(L);
	system("pause");
	return 0;

}