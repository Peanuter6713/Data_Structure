#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}Node, *LinkList;

 
void CreateListByTail(LinkList &L);
void Sort(LinkList &L);
void Display(LinkList L);
void InsertX(LinkList &L, int x);

 
void CreateListByTail(LinkList &L)
{
	Node *s, *r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < rand() % 20; i++)
	{
		s = new Node;
		s->data = rand() % 20;;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void Sort(LinkList &L)
{
	Node *p = L->next, *pre, *r;
	r = p->next;
	p->next = NULL;			// 构造只含有一个数据节点的有序表
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;   //  在pre之后插入p   头插法
		pre->next = p;
		p = r;  
	}
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

void InsertX(LinkList &L, int x)
{
	Node *pre = L, *p = pre->next, *s;
	s = new Node;
	s->data = x;  s->next = NULL;
	while (p != NULL && p->data < x)
	{
		pre = p;
		p = p->next;
	}
	s->next = p;    // s->next = pre->next;
	pre->next = s;
}

int main()
{
	LinkList L;
	srand(time(NULL));
	CreateListByTail(L);
	Sort(L);
	Display(L);
	InsertX(L, 6);
	Display(L);
	system("pause");
	return 0;
}