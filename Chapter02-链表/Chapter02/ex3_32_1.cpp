#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define ElemType int

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}Node, *LinkList;

void CreateListByHead(LinkList &L);
void CreateListByTail(LinkList &L);
void Display(LinkList L);
void Merge(LinkList L1, LinkList L2, LinkList &L3);

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 10;
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

void Merge(LinkList L1, LinkList L2, LinkList &L3)
{
	LinkList p = L1->next, q = L2->next, t;
	L3 = L1;
	t = L3;
	free(L2);
	while (p != NULL && q != NULL)
	{
		t->next = p;	t = p;		p = p->next;
		t->next = q;    t = q;		q = q->next;
	}
	t->next = NULL;
	if (q != NULL)
		p = q;
	t->next = p;
}

int main()
{
	LinkList L1, L2, L3;
	srand(time(NULL));
	CreateListByHead(L1);
	Display(L1);
	CreateListByHead(L2);
	Display(L2);
	Merge(L1, L2, L3);
	Display(L3);
	system("pause");
	return 0;
}