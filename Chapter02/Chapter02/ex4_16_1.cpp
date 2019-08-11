#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct DNode
{
	int data;
	int freq;
	struct DNode *prior;
	struct DNode *next;
}Node, *DLinkList;

void CreateByHead(DLinkList &L);
void CreateByTail(DLinkList &L);
void Display(DLinkList L);
int LocateNode(DLinkList &L, int x);

void CreateByHead(DLinkList &L)
{
	Node *s;
	L = new Node;
	L->prior = L->next = NULL;
	L->freq = 0;
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

int LocateNode(DLinkList &L, int x)
{
	DLinkList p = L->next, pre;
	while (p != NULL && p->data != x)
		p = p->next;
	if (p == NULL)
		return 0;
	else
	{
		p->freq++;
		pre = p->prior;
		if (pre != L)
		{
			while (pre != L && pre->freq < p->freq)
				pre = pre->prior;
			p->prior->next = p->next;
			if (p->next != NULL)
				p->next->prior = p->prior;
			p->next = pre->next;     // 头插法开始
			if (pre->next != NULL)
				pre->next->prior = p;
			pre->next = p;
			p->prior = pre;
		}
		return 1;
	}
}

void main()
{
	DLinkList L;
	int x;
	srand(time(0));
	CreateByHead(L);
	cout << "The L : " << endl;
	Display(L);
	cout << "Input the x: " << endl;
	cin >> x;
	LocateNode(L, x);
	cout << "It's changed. " << endl;
	Display(L);
	system("pause");
}