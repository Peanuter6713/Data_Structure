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

// ָ�����ͱ��� LinkList p ���� Node *p �������¶��� ϸϸ���
/*
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkList;

void CreateList(LinkList *&L)
{
	LinkList *s;    L = (LinkList *)malloc(sizeof(LinkList));
}
*/

void CreateListByHead(LinkList &L)       // ͷ�巨����  ����5�ֽ����ڵ�ķ�ʽ ͷ�巨2�� β�巨3��
{
	LinkList s;
	int i;
	L = new Node;   // ��һ�� C++��ʽ
	L->next = NULL;
	for (i = 0; i < 10; i++)
	{
		s = (LinkList)malloc(sizeof(LinkList));  // �ڶ��� 
		s->data = rand() % 50;
		s->next = L->next;  // ��֮ǰ�Ľڵ��ַ����s ��һ��ִ��ʱ ��ʹs.next = NULL
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)      // β�巨����
{
	int i;
	LinkList s, r;
	L = (LinkList)malloc(sizeof(Node));      //   ������
	L->next = NULL;
	r = L;        // ������L���� 
	for (i = 0; i < 10; i++)
	{
		s = (Node *)malloc(sizeof(LinkList));  //���ġ�������  s = (Node *)malloc(sizeof(Node));
		s->data = rand() % 50;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void Display(LinkList L)
{
	LinkList s;
	s = L->next;
	cout << "Numbers:" << endl;
	while (s)
	{
		cout << s->data <<" ";
		s = s->next;
	}
	cout << endl;
}


void Sort(LinkList &L)
{
	Node *p = L->next, *pre, *r;
	r = p->next;
	p->next = NULL;			// ����ֻ����һ�����ݽڵ�������
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;   //  ��pre֮�����p   ͷ�巨
		pre->next = p;
		p = r;
	}
}

int main()
{
	srand(time(NULL));
	LinkList A,B;
	CreateListByHead(A);
	Display(A);
	CreateListByTail(B);
	Display(B);
	system("pause");
	return 0;
}