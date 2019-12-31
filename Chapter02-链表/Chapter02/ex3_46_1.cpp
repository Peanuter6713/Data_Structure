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
void DelSame(LinkList &L);
void Union(LinkList &A, LinkList B);
void InterSet(LinkList &A, LinkList B);

void CreateListByHead(LinkList &L)
{
	Node *s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 20 + 1; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		L->next = s;
	}
	Sort(L);
	DelSame(L);
}

void CreateListByTail(LinkList &L)
{
	LinkList s, r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 20 + 1; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	Sort(L);
	DelSame(L);
}

void Display(LinkList L)
{
	LinkList s;
	s = L->next;
	while (s != NULL)
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

void DelSame(LinkList &L)
{
	LinkList p = L->next, q, postq, t;
	while (p != NULL)
	{
		q = p;
		postq = p->next;
		while (postq != NULL)
		{
			if (postq->data == p->data)
			{
				t = postq->next;
				q->next = t;
				free(postq);
				postq = t;
			}
			else
			{
				q = postq;
				postq = postq->next;
			}
		}
		p = p->next;
	}
}

void Union(LinkList &A, LinkList B)
{
	LinkList pa = A->next, pb = B->next, r;
	r = A;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			r->next = pb;
			r = pb;
			pb = pb->next;
		}
		else
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}
	if (pb != NULL)
		pa = pb;
	while (pa != NULL)
	{
		r->next = pa;
		r = pa;
		pa = pa->next;
	}
	r->next = NULL;
}

void InterSet(LinkList &A, LinkList B)   // A相当于B  B相当于C
{
	LinkList pa = A->next, pb = B->next, r;
	r = A;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pa->data > pb->data)
			pb = pb->next;
		else
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}
	r->next = NULL;
}

void main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByHead(A);
	Display(A);
	CreateListByTail(B);
	Display(B);
	CreateListByHead(C);
	Display(C);
	cout << "B && C:" << endl;
	InterSet(B, C);
	Display(B);
	cout << "A && B:" << endl;
	Union(A, B);
	Display(A);
	system("pause");
}