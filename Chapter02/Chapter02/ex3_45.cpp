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
void UnionSet(LinkList A, LinkList B, LinkList &C);

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 20 + 1; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		L->next = s;
	}
	DelSame(L);
	Sort(L);
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
	DelSame(L);
	Sort(L);
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
	LinkList p = L->next, postq, t, q;
	while (p != NULL)
	{
		q = p;
		postq = q->next;
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

void UnionSet(LinkList A, LinkList B, LinkList &C)
{
	LinkList pa = A->next, pb = B->next, s, r;
	C = new Node;
	r = C;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			s = new Node;
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			s = new Node;
			s->data = pb->data;
			r->next = s;
			r = s;
			pb = pb->next;
		}
		else
		{
			s = new Node;
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	while (pa != NULL)
	{
		s = new Node;
		s->data = pa->data;
		r->next = s;
		r = r;
		pa = pa->next;
	}
	while (pb != NULL)
	{
		s = new Node;
		s->data = pb->data;
		r->next = s;
		r = s;
		pb = pb->next;
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
	UnionSet(A, B, C);	 
	Sort(C);
	Display(C);
	system("pause");
}