#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
typedef struct CNode
{
	int data;
	struct CNode *next;
}Node, *CLinkList;

void CreateByHead(CLinkList &L)
{
	CLinkList s;
	L = new Node;
	L->next = L;                     //   attention
	for (int i = 0; i < rand() % 20 + 3; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		s->next = L->next;
		L->next = s;
	}
}

void CreateByTail(CLinkList &L)
{
	Node *s, *r;
	L = new Node;
	r = L;
	for (int i = 0; i < rand() % 20 + 3; i++)
	{
		s = new Node;
		s->data = rand() % 20;
		r->next = s;
		r = s;
	}
	r->next = L;
} 

void Display(CLinkList L)
{
	Node *s;
	s = L->next;
	while (s != L)         //  care
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void Count(CLinkList L)
{
	CLinkList p = L->next;
	int n = 0;
	while (p != L)
	{
		n++;
		p = p->next;
	}
	cout << "The count is :" << n << endl;
}

void main()
{
	CLinkList L;
	srand(time(0));
	CreateByHead(L);
	Display(L);
	Count(L);
	system("pause");
}