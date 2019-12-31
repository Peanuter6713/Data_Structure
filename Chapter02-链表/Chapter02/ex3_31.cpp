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
void SeparateC_AB(LinkList &A, LinkList &B, LinkList &C);

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
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = (LinkList)malloc(sizeof(LinkList));
		s->data = rand() % 10;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void Display(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void SeparateC_AB(LinkList &A, LinkList &B, LinkList &C)
{
	LinkList p = C->next,ra,q;
	A = C;
	ra = A; 
	B = new Node;
	B->next = NULL;
	while (p)
	{
		ra->next = p;
		ra = p;
		p = p->next;
		q = p->next;
		p->next = B->next;
		B->next = p;
		p = q;
	}
	ra->next = NULL;
}

int main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByTail(C);
	cout << "The elements of the C" << endl;
	Display(C);
	SeparateC_AB(A, B, C);
	cout << "The elements of the A:" << endl;
	Display(A);
	cout << "The elements of the B(reverse):" << endl;
	Display(B);
	system("pause");
	return 0;
}