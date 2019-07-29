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
int  Subseq(LinkList A, LinkList B);

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 100 + 1; i++)
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
	Node *s, *r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 2; i++)
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
	Node *s;
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

void DelSame(LinkList &L)
{
	LinkList p = L->next, postq, q, t;
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

int Subseq(LinkList A, LinkList B)
{
	LinkList pa = A->next, pb, q;
	while (pa != NULL)
	{
		pb = B->next;
		while (pa != NULL && pa->data != pb->data)
			pa = pa->next;
		q = pa;
		while (q != NULL && pb != NULL && q->data == pb->data)
		{
			q = q->next;
			pb = pb->next;
		}
		if (pb == NULL)
			return 1;
		else if (pa != NULL)
			pa = pa->next;
	}
	return 0;
}

void main()
{
	LinkList A, B;
	srand(time(0));
	CreateListByHead(A);
	cout << "LinkList A :" << endl;
	Display(A);
	CreateListByTail(B);
	cout << "LinkList B: " << endl;
	Display(B);
	if (Subseq(A, B))
		cout << "Ture" << endl;
	else
		cout << "False." << endl;
	system("pause");
}