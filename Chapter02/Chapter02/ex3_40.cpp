#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}Node, *LinkList;

void CreateListByHead(LinkList &L);
void CreateListByTail(LinkList &L);
void Display(LinkList L);
void Sort(LinkList &L);
void Intersection(LinkList &A, LinkList &B, LinkList &C);
 

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)
{
	LinkList s, r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	
}

void Display(LinkList L)
{
	LinkList s;
	s = L->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void Sort(LinkList &L)
{
	LinkList p = L->next, pre, r;
	r = p->next;
	p->next = NULL;
	p = r;
	while (p)
	{
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;

	}
}

void Intersection(LinkList &A, LinkList &B, LinkList &C)
{
	LinkList pa = A->next, pb, s, r;
	C = new Node;
	r = C;
	while (pa)
	{
		pb = B->next;
		while (pb != NULL && pb->data != pa->data)
			pb = pb->next;
		if (pb != NULL)
		{
			s = new Node;
			s->data = pa->data;
			r->next = s;
			r = s;      // β�巨
		}
		pa = pa->next;
	}
	r->next = NULL;
}

void main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByHead(A);
	cout << "A    :" << endl;
	Display(A);
	CreateListByTail(B);
	cout << "B-------:" << endl;
	Display(B);
	Intersection(A, B, C);
	Sort(C);
	cout << "C_______:" << endl;
	Display(C);
	system("pause");
}