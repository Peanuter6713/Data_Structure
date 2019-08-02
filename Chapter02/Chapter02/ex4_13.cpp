#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct DNode
{
	int data;
	struct DNode *prior;
	struct DNode *next;
}Node, *DLinkList;

void CreateByHead(DLinkList &L);
void CreateByTail(DLinkList &L);
void Display(DLinkList L);
int  Swap(DLinkList &L, int x);

void CreateByHead(DLinkList &L)
{
	Node *s;
	L = new Node;
	L->next = L->prior = NULL;
	for (int i = 0; i < rand() % 20 + 1; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		s->prior = L;
		L->next = s;
	}
}

void CreateByTail(DLinkList &L)
{
	Node *s, *r;
	L = new Node;
	L->next = L->prior = NULL;
	r = L;
	for (int i = 0; i < rand() % 20 + 1; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

void Display(DLinkList L)
{
	Node *s;
	s = L->next;
	while (s != NULL)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

int Swap(DLinkList &L, int x)
{
	DLinkList p = L->next, q;
	while (p != NULL && p->data != x)
		p = p->next;
	if (p == NULL)
		return 0;
	else
	{
		q = p->next;
		if (p != NULL)
		{
			p->prior->next = q;
			q->prior = p->prior;
			p->next = q->next;
			if (q->next != NULL)
				q->next->prior = p;
			q->next = p;
			p->prior = q;
			return 1;
		}
		else
			return 0;
	}
}

void main()
{
	DLinkList L;
	int x;
	srand(time(0));
	CreateByTail(L);
	cout << " L has been created. :" << endl;
	Display(L);
	cout << "Input x : " << endl;
	cin >> x;
	Swap(L, x);
	cout << "After swapping .:" << endl;
	Display(L);
	system("pause");
}