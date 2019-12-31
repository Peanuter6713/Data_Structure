#include <iostream>
#include <time.h>
#include <stdlib.h>
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
void SeparateC_AB(LinkList &A, LinkList &B,LinkList &C);

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
	cout << "The elements are below:" << endl;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void SeparateC_AB(LinkList &A, LinkList &B, LinkList &C)
{
	LinkList p = C->next, ra, rb;
	A = C;           // use the head node of C as its own head node
	ra = A;	      
	B = new Node;
	//B->next = NULL;
	rb = B;
	while (p != NULL)
	{
		ra->next = p;    // 将奇数序号节点链到A后
		ra = p;
		p = p->next;
		rb->next = p;
		rb = p;
		p = p->next;
	}
	ra->next = rb->next = NULL;
}

int main()
{
	LinkList A, B, C;
	srand(time(NULL));
	CreateListByHead(C);
	Display(C);
	SeparateC_AB(A, B, C);
	Display(A);
	Display(B);
	system("pause");
	return 0;
}