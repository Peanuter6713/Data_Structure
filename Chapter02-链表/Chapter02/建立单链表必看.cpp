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

// 指针类型别名 LinkList p 等于 Node *p 或者如下定义 细细体会
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

void CreateListByHead(LinkList &L)       // 头插法建表  共有5种建立节点的方式 头插法2种 尾插法3种
{
	LinkList s;
	int i;
	L = new Node;   // 第一种 C++方式
	L->next = NULL;
	for (i = 0; i < 10; i++)
	{
		s = (LinkList)malloc(sizeof(LinkList));  // 第二种 
		s->data = rand() % 50;
		s->next = L->next;  // 将之前的节点地址放入s 第一次执行时 可使s.next = NULL
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)      // 尾插法建表
{
	int i;
	LinkList s, r;
	L = (LinkList)malloc(sizeof(Node));      //   第三种
	L->next = NULL;
	r = L;        // 不可用L代替 
	for (i = 0; i < 10; i++)
	{
		s = (Node *)malloc(sizeof(LinkList));  //第四、第五种  s = (Node *)malloc(sizeof(Node));
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