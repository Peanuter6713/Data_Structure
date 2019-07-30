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
int	 InsBefore(DLinkList &L, int x, int y);   
int  InsAfter(DLinkList &L, int x, int y);

void CreateByHead(DLinkList &L)
{
	DLinkList s;
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
	}
}

void CreateByTail(DLinkList &L)
{
	DLinkList s, r;
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

void Display(DLinkList  L)
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

int InsBefore(DLinkList &L, int x, int y)
{
	DLinkList p = L->next, s;
	while (p != NULL && p->data != x)
		p = p->next;
	if (p == NULL)
		return 0;
	else
	{
		s = new Node;
		s->data = y;
		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
		return 1;		
	}
}

int InsAfter(DLinkList &L, int x, int y)
{
	DLinkList p = L->next, s;
	while (p != NULL && p->data != x)
		p = p->next;
	if (p == NULL)
		return 0;
	else
	{
		s = new Node;
		s->data = y;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return 1;
	}
}

void main()
{
	DLinkList L;
	int x;
	srand(time(0));
	CreateByHead(L);
	Display(L);
	cout << "Input x:" << endl;
	cin >> x;
	InsBefore(L, x, 13);
	cout << "13 has been inserted successfully before x:" << endl;
	Display(L);
	InsAfter(L, x, 31);
	cout << "31 has been inserted after x:" << endl;
	Display(L);
	system("pause");
	 

}