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
void Reverse(DLinkList &L);

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

void Reverse(DLinkList &L)
{
	DLinkList p = L->next, q;
	L->next = NULL;	
	while (p != NULL)						// 遍历原双链表的所有数据节点
	{
		q = p->next;						// q 临时保存p节点的后继节点
		p->next = L->next;					// 将 p 节点插到新链表前端
		if (L->next != NULL)
			L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;
	}
}

void main()
{
	DLinkList L;
	srand(time(0));
	CreateByHead(L);
	cout << "DLinkList L: " << endl;
	Display(L);
	Reverse(L);
	cout << "L has been reversed. " << endl;
	Display(L);
	system("pause");
}