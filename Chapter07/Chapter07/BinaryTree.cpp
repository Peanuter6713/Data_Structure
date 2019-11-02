#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

using namespace std;

typedef char ElemtType;
typedef struct Node
{
	ElemtType data;
	struct Node *lchild, *rchild;
} TNode, *BTree;

char *ch;

void PreCreate(BTree &T);
void PreOrder(BTree T);
void InOrder(BTree T);
void PostOrder(BTree T);
void Display(BTree T);
void CountLeaf(BTree T, int &n);
void High(BTree T, int &h);

void PreCreate(BTree &T)
{
	if (*ch++ == '#')
		T = NULL;
	else
	{
		T = (TNode *)malloc(sizeof(TNode));
		//T = new TNode;
		T->data = *(ch-1);
		PreCreate(T->lchild);
		PreCreate(T->rchild);
	}
}

void PreOrder(BTree T)
{
	if (T)
	{
		cout << T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	}
}

void PostOrder(BTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data;
	}
}

void Display(BTree T)
{
	if (T)
	{
		cout << T->data;
		Display(T->lchild);
		Display(T->rchild);
	}	
}

void CountLeaf(BTree T, int &n)
{
	if (T)
	{
		CountLeaf(T->lchild, n);
		if (!T->lchild && !T->rchild)
			n++;
		CountLeaf(T->rchild, n);
	}
}

void High(BTree T, int &h)
{
	int hl, hr;
	if (!T)
		h = 0;
	else
	{
		High(T->lchild, hl);
		High(T->rchild, hr);
		h = hl > hr ? hl + 1 : hr + 1;
	}
}

// 输入元素时 每个空的孩子节点以 # 表示
void main()
{
	BTree T;
	int n = 0, h = 0;
	char str[] = { "ABC##D##EF##G##" };
	ch = str;
	cout << "Input the elements of the tree :" << endl;
	PreCreate(T);
	cout << "The elements of the tree :" << endl;
	Display(T);
	cout << endl;
	cout << "Pre Traverse :" << endl;
	PreOrder(T); cout << endl;
	cout << "In Traverse :" << endl;
	InOrder(T); cout << endl;
	cout << " Post Traverse :" << endl;
	PostOrder(T); cout << endl;
	CountLeaf(T, n);
	cout << "The number of the Leaf Node is :" << n << endl;
	High(T, h);
	cout << "The height of the Tree is :" << h << endl;
	system("pause");
}
