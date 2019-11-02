#include "BinTree.h"
#define INF -1

 

void Operation(BinTree T,int n,int h)
{
	cout << "Pre Order Traverse :" << endl;
	PreOrder(T);	 cout << endl;
	cout << "In Order Traverse :" << endl;
	InOrder(T);		 cout << endl;
	cout << "Post Order Traverse :" << endl;
	PostOrder(T);    cout << endl;
	CountLeaf(T, n);
	cout << "The amount of the Leaf Node :" << n << endl;
	Height(T, h);
	cout << "The height of the Tree :" << h << endl;
	InvertTree(T);
	cout << "After invert :" << endl;
	PreOrder(T); cout << endl;
}



int main()
{
	BinTree T1=NULL, T2=NULL;
	int n=0, h=0;
	int choice;
	char str[] = { "ABC##D##EF##G##" };
	ch = str;
	CreateCharTree(T1);	
	int array[] = { 1,2,3,-99,-99,-99,-99};
	p = array;
	CreateIntTree(T2);
	 
	while (1)
	{
		cout << "1.charTree  2.intTree" << endl;
		cout << "Input choice :" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:Operation(T1,n,h); break;
		default:keyType = false; Operation(T2, n, h); break;
		}
		cout << endl;
	}
	
	return 0;
}