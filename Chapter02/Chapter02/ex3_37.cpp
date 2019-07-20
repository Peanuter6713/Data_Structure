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
void Sort(LinkList &L);
void Display(LinkList L);
void DelNodes(LinkList &L, int min, int max);

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

void DelNodes(LinkList &L, int min, int max)
{
	LinkList pre = L, p = pre->next, post;
	while (p)
	{
		if (p->data >= min && p->data <= max)
		{
			post = p->next;
			pre->next = post; // pre->next = p->next;
			free(p);
			p = post;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void main()
{
	LinkList L;
	srand(time(NULL));
	CreateListByHead(L);
	cout << "Here are the numbers:" << endl;
	Display(L);
	DelNodes(L,3,9);
	cout << "Between 3 and 9 have been deleted:" << endl;
	Sort(L);
	Display(L);
	
	system("pause");
}