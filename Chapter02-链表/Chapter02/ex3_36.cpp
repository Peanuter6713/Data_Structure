#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}Node, *LinkList;

void CreateListByHead(LinkList &L);
void CreateListByTail(LinkList &L);
void Sort(LinkList &L);
void Display(LinkList L);
void DelNodes(LinkList &L, int min, int max);

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		L->next = s;
	}
	Sort(L);
}

void CreateListByTail(LinkList &L)
{
	LinkList s, r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	Sort(L);
}

void Display(LinkList L)
{
	LinkList s;
	s = L->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void Sort(LinkList &L)
{
	LinkList p = L->next, pre, r;
	r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}

void DelNodes(LinkList &L, int min, int max)
{
	LinkList p = L->next, q, r = L;
	while (p != NULL && p->data < min)
	{
		r = p;   // r 为 p 的前驱节点
		p = p->next;
	}
	q = p;
	while (q != NULL && q->data <= max)
		q = q->next;
	r->next = q;
	r = p->next;  // 即将删除的第一个节点
	while (r != q)
	{
		free(p);
		p = r;
		r = r->next;
	}
}

void main()
{
	LinkList L1,L2;
	srand(time(NULL));
	CreateListByHead(L1);
	cout << "The elements of the L1:" << endl;
	Display(L1);
	cout << "L1 has been deleted:" << endl; 
	DelNodes(L1, 2, 7);
	Display(L1);	
	
	CreateListByTail(L2);
	cout << "The elements of the L2:" << endl;
	Display(L2);
	cout << "Delete successfully:" << endl;
	DelNodes(L2, 5, 10);
	Display(L2);
	system("pause");
}