#include "BinTree.h"
bool FLAG = true;

 

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
	BinTree T1=NULL, T2=NULL,T3=NULL;
	int n=0, h=0;
	int choice;
	char str[] = { "ABC##D##EF##G##" };
	ch = str;
	CreateCharTree(T1);	
	int array[] = { 1,2,3,-1,-1,5,-1,-1,6,7,-1,-1};
	p = array;	
	CreateIntTree(T2);	 
	int array2[] = { 22,3,8,9,6,12,4,32,53 };
	CreateBST(T3,array2,9);
	while (FLAG)
	{
		cout << "1.charTree  2.intTree 3.BinSortTree" << endl;
		cout << "Input choice :" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:keyType=true;Operation(T1,n,h); break;
		case 2:keyType = false; Operation(T2, n, h); break;
		case 3:keyType = false; Operation(T3, n, h); break;
		default:FLAG = false; break;
		}
		cout << endl;
	}
	
	return 0;
}