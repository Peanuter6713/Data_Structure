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
void CreateListByTail(LinkList &L);
void Display(LinkList L);
int  JudgeIncrease(LinkList L);

void CreateListByHead(LinkList &L)
{
	LinkList s;
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < 10; i++)
	{
		s = new Node;
		s->data = rand() % 10;
		s->next = L->next;
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)
{
	LinkList s, r;
	L = new Node;
	L->next = NULL;
	r = L;
	for (int i = 0; i < 10; i++)
	{
		s = new Node;
		s->data = i;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void Display(LinkList L)
{
	Node *s;
	s = L->next;
	cout << "The numbers are:" << endl;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

int JudgeIncrease(LinkList L)
{
	LinkList pre = L->next, p;
	p = pre->next;
	while (p)
	{
		if (p->data >= pre->data)
		{
			pre = p;
			p = p->next;
		}
		else return 0;
	}
	return 1;
}

int main()
{
	LinkList A, B;
	srand(time(NULL));
	CreateListByHead(A);
	Display(A);
	CreateListByTail(B);
	Display(B);
	if (JudgeIncrease(A))
		cout << "A is increased." << endl;
	else
		cout << "A is not increased." << endl;
	if (JudgeIncrease(B))
		cout << "B is increased" << endl;
	else
		cout << "B is not increased.";
	system("pause");
	return 0;
}