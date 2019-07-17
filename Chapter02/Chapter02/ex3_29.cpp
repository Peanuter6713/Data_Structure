#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
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
void SeparateAB(LinkList &A, LinkList &B);

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < 10; i++)
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
	for (int i = 0; i < 10; i++)
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
	cout << "The numbers are:" << endl;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void SeparateAB(LinkList &A, LinkList &B)
{
	LinkList p = A->next, ra, rb;
	ra = A;
	B = new Node;
	rb = B;
	while (p != NULL)
	{
		if (p->data % 2 == 0)
		{
			ra->next = p;
			ra = p;
			p = p->next;
		}
		else
		{
			rb->next = p;
			rb = p;
			p = p->next;
		}
	}
	ra->next = rb->next = NULL;
}

int main()
{
	LinkList A, B;
	srand(time(NULL));
	CreateListByHead(A);
	Display(A);
	SeparateAB(A, B);
	Display(A);
	Display(B);
	system("pause");
	return 0;
}