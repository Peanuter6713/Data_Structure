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
void Pub(LinkList &A, LinkList B, LinkList C);

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
	Sort(L);
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

void Pub(LinkList &A, LinkList B, LinkList C)
{
	LinkList pa, pb, pc, q, r;
	pa = A->next;
	while (pa != NULL && pa->next != NULL) // delete the same elements of the LinkList A
	{
		q = pa->next;
		if (pa->data == q->data)
		{
			pa->next = q->next;
			free(q);
		}
		pa = pa->next;
	}
	pa->next = NULL;
	pa = A->next;
	r = A;
	r->next = NULL;
	pb = B->next;
	pc = C->next;
	while (pa != NULL)
	{
		while (pb != NULL && pb->data < pa->data)
		{
			q = pb;
			pb = pb->next;
			free(q);
		}
		while (pc != NULL && pc->data < pa->data)
		{
			q = pc;
			pc = pc->next;
			free(q);
		}
		if (pb != NULL && pc != NULL && pa->data == pb->data && pa->data == pc->data)
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
		}
		else
		{
			q = pa;
			pa = pa->next;
			free(q);
		}

	}
	r->next = NULL;
}

void main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByHead(A);
	cout << "LinkList A: " << endl;
	Display(A);
	CreateListByTail(B);
	cout << "LinkList B:  " << endl;
	Display(B);
	CreateListByHead(C);
	cout << "LinkList C:" << endl;
	Display(C);
	Pub(A, B, C);    // 随机生成好多次才有一个
	cout << "Pub A:" << endl;
	Display(A);
	system("pause");

}