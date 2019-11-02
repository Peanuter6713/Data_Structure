#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
using namespace std;
#include <malloc.h>

#define ElemType char

char *ch;
int *p;
bool keyType = true; // 此情况下为 charTree

typedef struct BinNode
{
	char data;
	int key;
	struct BinNode *lchild;
	struct BinNode *rchild;
}BinNode, *BinTree;

void CreateCharTree(BinTree &T);
void CreateIntTree(BinTree &T);
void PreOrder(BinTree T);
void InOrder(BinTree T);
void PostOrder(BinTree T);
void CountLeaf(BinTree T, int &n);
void Height(BinTree T, int &h);
void InvertTree(BinTree &T); 

void CreateCharTree(BinTree &T)
{
	if (*ch++ == '#')
		T = NULL;
	else
	{
		T = new BinNode;  // T = (BinNode *)malloc(sizeof(BinNode));
		T->data = *(ch - 1);
		CreateCharTree(T->lchild);
		CreateCharTree(T->rchild);
	}
}

void CreateIntTree(BinTree &T)
{
	if (*p++ < 0)
		T = NULL;
	else
	{
		T = new BinNode;
		T->key = *(p - 1);
		CreateIntTree(T->lchild);
		CreateIntTree(T->rchild);
	}
}

void PreOrder(BinTree T)
{
	if (T)
	{
		if (keyType)
			cout << T->data << " ";
		else
			cout << T->key << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BinTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		if (keyType)
			cout << T->data << " ";
		else
			cout << T->key << " ";
		InOrder(T->rchild);
	}
}

void PostOrder(BinTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		if (keyType)
			cout << T->data << " ";
		else
			cout << T->key << " ";
	}
}

void CountLeaf(BinTree T, int &n)
{
	if (T)
	{
		CountLeaf(T->lchild, n);
		if (!T->lchild && !T->rchild)
			n++;
		CountLeaf(T->rchild, n);
	}
}

void Height(BinTree T, int &h)
{
	int hl, hr;
	if (!T)
		h = 0;
	else
	{
		Height(T->lchild, hl);
		Height(T->rchild, hr);
		h = hl > hr ? hl + 1 : hr + 1;
	}
}

void InvertTree(BinTree &T)
{
	BinNode *tmp;
	if(T)
	{
		tmp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = tmp;
		InvertTree(T->lchild);
		InvertTree(T->rchild);
	}
}

  
#endif // !HEAD_H
