#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*   循环单链表
typedef struct CNode
{
	int data;
	struct CNode *next;
}Node, *CLinkList;

void CreateByHead(CLinkList &L)
{
	CLinkList s;
	L = new Node;
	L->next = L;
	for (int i = 0; i < rand() % 20 + 3; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		L->next = s;
	}
}

voidCreateByTail(CLinkList &L)
{
	Node *s, *r;
	L = new Node;
	r = L;
	for (int i = 0; i < rand() % 20 + 3; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		r = s;
	}
	r->next = L;
}*/ 

//   循环双链表
typedef struct CNode
{
	int data;
	struct CNode *next;
	struct CNode *prior;
}Node, *CLinkList;

void CreateByHead(CLinkList &L)
{
	Node *s;
	L = new Node;
	L->next = L->prior = L;
	for (int i = 0; i < rand() % 20 + 13; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void CreateByTail(CLinkList &L)
{
	Node *s, *r;
	L = new Node;
	r = L;
	for (int i = 0; i < rand() % 20 + 13; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
	L->prior = r;
}
