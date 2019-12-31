#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct DNode
{
	int data;
	int freq;
	struct DNode *next;
	struct DNode *prior;
}Node, *DLinkList;

void CreateByHead(DLinkList &L);
void CreateByTail(DLinkList &L);
void Display(DLinkList L);
int LocateNode(DLinkList &L, int x);

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
	Node *s, *r;
	L = (Node*)malloc(sizeof(Node));
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
	int temp;
	int freqq;
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
			{
				temp = p->data;
				p->data = pre->data;
				pre->data = temp;
				freqq = p->freq;
				p->freq = pre->freq;
				pre->freq = freqq;
				p = pre;
				pre = pre->prior;
			}
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