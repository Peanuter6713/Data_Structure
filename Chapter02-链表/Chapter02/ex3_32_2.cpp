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
void Merge(LinkList L1, LinkList L2, LinkList &L3);

void CreateListByHead(LinkList &L)
{
	Node *s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = (Node *)malloc(sizeof(Node));
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

void Merge(LinkList L1, LinkList L2, LinkList &L3)
{
	Node *p = L1->next, *q = L2->next, *s, *r;
	L3 = new Node;
	L3->next = NULL;
	r = L3;
	while (p != NULL && q != NULL)
	{
		s = new Node;
		s->data = p->data;
		r->next = s;
		r = s;
		p = p->next;
		s = new Node;
		s->data = q->data;
		r->next = s;
		r = s;
		q = q->next;
	}
	if (q != NULL)
		p = q;
	while (p != NULL)
	{
		s = new Node;
		s->data = p->data;
		r->next = s;
		r = s;
		p = p->next;
	}
	r->next = NULL;
}

int main()
{
	LinkList L1, L2, L3;
	srand(time(NULL));
	cout << "L1:" << endl;
	CreateListByHead(L1);	
	Display(L1);
	cout << "L2: " << endl;
	CreateListByTail(L2);
	Display(L2);
	Merge(L1, L2, L3);
	cout << "L3:" << endl;
	Display(L3);
	system("pause");
	return 0;

}