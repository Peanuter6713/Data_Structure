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
void InterSet(LinkList A, LinkList B, LinkList &C);

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
	Sort(L);
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
	Sort(L);
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
	while (p != NULL)
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

void InterSet(LinkList A, LinkList B, LinkList &C)
{
	LinkList pa = A->next, pb = B->next, s, rc;
	C = new Node;
	rc = C;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pa->data > pb->data)
			pb = pb->next;
		else
		{
			s = new Node;
			s->data = pa->data;
			rc->next = s;
			rc = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	rc->next = NULL;
}

void main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByHead(A);
	cout << "*****A*****:" << endl;
	Display(A);
	CreateListByTail(B);
	cout << "*****B*****:" << endl;
	Display(B);
	InterSet(A, B, C);
	cout << "*****C*****:" << endl;
	Display(C);

	system("pause");
}