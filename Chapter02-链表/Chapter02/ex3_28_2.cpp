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
void Reverse(LinkList &L);

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

void Reverse(LinkList &L)
{
	LinkList pre = L->next, p, q;
	p = pre->next;            
	pre->next = NULL;
	while (p != NULL)
	{
		q = p->next;   
		p->next = pre;
		pre = p;
		p = q;
	}
	L->next = pre;
}

int main()
{
	LinkList L;
	srand(time(NULL));
	CreateListByHead(L);
	Display(L);
	Reverse(L);
	Display(L);
	system("pause");
	return 0;
}