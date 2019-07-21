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

void DelSame(LinkList &L)
{
	LinkList p = L->next, q, postq, t;
	while (p)
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

void main()
{
	LinkList L;
	srand(time(NULL));
	CreateListByHead(L);
	cout << "L has been created." << endl;
	Display(L);
	DelSame(L);
	cout << "The same element has been deleted." << endl;
	Display(L);
	cout << "Sorted:" << endl;
	Sort(L);
	Display(L);
	system("pause");
	
}