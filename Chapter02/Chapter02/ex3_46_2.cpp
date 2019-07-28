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
void Operation(LinkList &A, LinkList B, LinkList C);

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
	Node *s, *r;
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
	Node *s;
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
	LinkList p = L->next, postq, q, t;
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

void Operation(LinkList &A, LinkList B, LinkList C)
{
	LinkList pa = A->next, pb = B->next, pc = C->next, t;
	t = A;
	while (pa != NULL && pb != NULL)
	{
		while (pb != NULL && pc != NULL)
		{
			if (pb->data > pc->data)
				pb = pb->next;
			else if (pb->data > pc->data)
				pc = pc->next;
			else
				break;
		}
		if (pb != NULL && pc != NULL)
		{
			while (pa != NULL && pa->data < pb->data)
			{
				t->next = pa;
				t = pa;
				pa = pa->next;
			}
			if (pa->data == pb->data)
			{
				t->next = pa;
				t = pa;
				pa = pa->next;
				pb = pb->next;
				pc = pc->next;
			}
			else
			{
				t->next = pb;
				t = pb;
				pb = pb->next;
				pc = pc->next;
			}
		}
		while (pa != NULL)
		{
			t->next = pa;
			t = pa;
			pa = pa->next;
		}
		t->next = NULL;
	}
}

void main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByHead(A);
	cout << "LinkList A :" << endl;
	Display(A);
	CreateListByTail(B);
	cout << "LinkList B:" << endl;
	Display(B);
	CreateListByHead(C);
	cout << "LinkList C: " << endl;
	Display(C);
	Operation(A, B, C);
	Display(A);
	system("pause");


}