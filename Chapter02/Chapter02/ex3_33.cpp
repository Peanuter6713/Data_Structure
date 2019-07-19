#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}Node, *LinkList;

void CreateListByHead(LinkList &L);
void CreateListByTail(LinkList &L);
void Display(LinkList L);
void DeleteOddIndex(LinkList &L);

void CreateListByHead(LinkList &L)
{
	Node *s;
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
	Node *s;
	s = L->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void DeleteOddIndex(LinkList &L)
{
	Node *pre =L, *p = pre->next;
	while (p)
	{
		pre->next = p->next;
		free(p);
		pre = pre->next;
		if (pre == NULL)
			break;
		p = pre->next;
	}
}

int main()
{
	LinkList L;
	srand(time(NULL));
	CreateListByHead(L);
	Display(L);
	DeleteOddIndex(L);
	Display(L);
	system("pause");
	return 0;
}