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

void CreateListByHead(LinkList &L)        
{
	LinkList s;
	int i;
	L = new Node;   // 第一种 C++方式
	L->next = NULL;
	for (i = 0; i < 10; i++)
	{
		//s = (LinkList)malloc(sizeof(LinkList));   
		s = new Node;
		s->data = rand() % 50;
		s->next = L->next;  // 将之前的节点地址放入s 第一次执行时 可使s.next = NULL
		L->next = s;
	}
}

void CreateListByTail(LinkList &L)      // 尾插法建表
{
	int i;
	LinkList s, r;
	//L = (LinkList)malloc(sizeof(Node));      //   第三种
	L = new Node;
	L->next = NULL;
	r = L;        
	for (i = 0; i < 10; i++)
	{
		//s = (Node *)malloc(sizeof(LinkList));  //第四、第五种  s = (Node *)malloc(sizeof(Node));
		s = new Node;
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
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

int Delete(LinkList &L, ElemType x)
{
	LinkList pre = L, p = pre->next;  //  pre and p must be initialed
	while (p != NULL && p->data != x)
	{
		pre = p;        //  Move back at the same time
		p = p->next;
	}
	if (p != NULL)
	{
		pre->next = p->next;
		free(p);      //  Destroy this Node
		return 1;
	}
	else return 0;
} 

int main()
{
	srand(time(NULL));
	LinkList L;
	//CreateListByTail(L);
	CreateListByHead(L);
	Display(L);
	if (Delete(L, 6))
	{
		cout << "Delete succeeded." << endl;
		Display(L);
	}
	else
		cout << "Delete failed." << endl;
	system("pause");
	return 0;	
}