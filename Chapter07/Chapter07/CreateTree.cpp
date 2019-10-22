#include <iostream>
#include <string.h>
#include <malloc.h>
using namespace std;

typedef char ElemtType;
typedef struct Node
{
	ElemtType data;
	struct Node *lchild, *rchild;
} TNode, *Tree;

void Create(Tree &T);
void PreOrder(Tree T);
void InOrder(Tree T);
void PostOrder(Tree T);
void Display(Tree T);

void Create(Tree &T)
{
	//cout << "Input the elemt :" << endl;
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = (TNode *)malloc(sizeof(TNode));
		//T = new TNode;
		T->data = ch;
		Create(T->lchild);
		Create(T->rchild);
	}
}

void PreOrder(Tree T)
{
	if (T)
	{
		cout << T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void Display(Tree T)
{
	if (T)
	{
		cout << T->data;
		Display(T->lchild);
		Display(T->rchild);
	}	
}
// 输入元素时 每个空的孩子节点以 # 表示
void main()
{
	Tree T;
	cout << "Input the elements of the tree :" << endl;
	Create(T);
	cout << "The elements of the tree :" << endl;
	Display(T);
	cout << endl;
	cout << "Pre Traverse :" << endl;
	PreOrder(T);
	system("pause");
}
