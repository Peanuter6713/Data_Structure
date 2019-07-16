/* 此代码风格混乱， 作为测试使用*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

#define ElemType int

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}Node, *LinkList;

void CreateListByHead(LinkList &L);
void CreateListByTail(Node *&L);
void Display(Node *L);  
void DeleteALL(LinkList &L);

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

void CreateListByTail(Node *&L)
{
	LinkList s, r;
	L = new Node;		// L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	r = L;
	for (int i = 0; i < 10; i++)
	{
		s = new Node;
		s->data = rand() % 10;
		r->next = s;
		r = s;
	}
	r->next = NULL;

}

void Display(Node *L)
{
	LinkList s;
	s = L->next;
	cout << "The numbers are:" << endl;
	
	while (s != NULL)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;

}

void DeleteALL(LinkList &L)
{
	LinkList pre = L,p = L->next;
	while (p != NULL)
	{
		free(pre);				 //  destroy the Head
		pre = p;
		p = p->next;
	}	
	free(p);
}

int main()
{
	LinkList L;
	srand(time(NULL));
	CreateListByHead(L);
	Display(L);
	DeleteALL(L);	 
	system("pause");
	return 0;

}