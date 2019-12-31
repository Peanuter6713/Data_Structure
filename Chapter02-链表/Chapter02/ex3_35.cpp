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

void CreateListByHead(LinkList &L)
{
	Node *s;
	L = new Node;
	L->next = NULL;
	for(int i=0; i<rand()%20; i++)
	{
		s = new Node;
		s->data = rand() % 10;
		s->next = L->next;
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)
{
	Node *s, *r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 10;
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

void main()
{
	LinkList L1, L2;
	srand(time(NULL));
	CreateListByHead(L1);
	cout << "The elements of the L1:" << endl;
	Display(L1);
	cout << "The sorted L1:" << endl;
	Sort(L1);
	Display(L1);
	 
	CreateListByTail(L2);
	cout << "The elements of the L2:" << endl;
	Display(L2);
	cout << "The sorted L1:" << endl;
	Sort(L2);
	Display(L2);
	system("pause");
	 
}