#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

typedef struct DNode
{
	int data;
	struct DNode *prior;
	struct DNode *next;
} Node, *DLinkList;

void CreateByHead(DLinkList &L);
void CreateByTail(DLinkList &L);
void Display(DLinkList L);
int  FindNode(DLinkList L, int x);
int  Insert(DLinkList &L, int i, int x);
int	 Delete(DLinkList &L, int i);

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
		if (L->next != NULL)    //   indispensible
			L->next->prior = s;
		L->next = s;
		s->prior = L;
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

int FindNode(DLinkList L,int x)
{
	DLinkList p = L->next;
	int i = 1;
	while (p != NULL && p->data != x)
	{
		i++;
		p = p->next;
	}
	if (p == NULL) return 0;
	else return i;
}

int Insert(DLinkList &L, int i, int x)
{
	int j = 0;
	DLinkList p = L, s;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
	{
		s = new Node;
		s->data = x;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return 1;
	}
}

int Delete(DLinkList &L, int i)
{
	DLinkList p = L, q;
	int j = 0;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
	{
		q = p->next;
		if (q == NULL)
			return 0;
		p->next = q->next;
		if (p->next != NULL)
			p->next->prior = p;
		free(q);
		return 1;
	}
}

void main()
{
	DLinkList L;
	srand(time(0));
	CreateByHead(L);
	Display(L);
	Insert(L, 3, 13);
	cout << "Inserted successfully:" << endl;
	Display(L);
	Delete(L, 3);
	cout << "Deleted succeed: " << endl;
	Display(L);
	system("pause");

}