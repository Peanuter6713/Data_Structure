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
void DelMax(DLinkList &L);

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
		L->next = s;
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
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void DelMax(DLinkList &L)
{
	DLinkList p = L->next, maxp=p;
	while (p != NULL)
	{
		if (p->data > maxp->data)
			maxp = p;
		p = p->next;
	}
	maxp->prior->next = maxp->next;  // delete maxp node
	if (maxp->next != NULL)
		maxp->next->prior = maxp->prior;
	free(maxp);
}

void main()
{
	DLinkList L;
	srand(time(0));
	CreateByHead(L);
	cout << "The elements of the L: " << endl;
	Display(L);
	DelMax(L);
	cout << "The max node has been deleted." << endl;
	Display(L);
	system("pause");
}