#include <iostream>
using namespace std;
#define MaxLen 20
#define Elemtype int 



typedef struct
{
	Elemtype data[MaxLen];
	int length;
} Seqlist;
/*
void createList(Seqlist &L)
{
	int i;
	for (i = 0; i < 5; i++)
		L.data[i] = i;
	L.length = i;
}
*/
void createList(Seqlist &L)  
{	
	int i;
	cout << "Input the length of the Seqlist: " << endl;
	cin >> L.length;
	cout << "Input the numbers of the data array :" << endl;
	for (i = 0; i < L.length; i++)
		cin >> L.data[i];

}
 
void insert(Seqlist &L, Elemtype x) 
{
	int i = 0, j;
	while (i<L.length && x>L.data[i])
		i++;
	for (j = L.length - 1; j >= i; j--)
		L.data[j + 1] = L.data[j];
	L.data[i] = x;
	L.length++;
}

void reverse(Seqlist &L)
{
	int i;
	Elemtype x;
	for (i = 0; i < L.length / 2; i++)
	{
		x = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = x;
	}
}

void Print(Seqlist L)
{
	int i = 0;
	while (i < L.length)
	{
		cout << L.data[i] << " ";
		i++;
	}
}

int main()
{
	Seqlist L;
	Elemtype;	 
	createList(L);	 
	cout << "Input the number you want to insert:" << endl;
	cin >> x;
	insert(L, x);
	Print(L);
	 
	 
	 
	 

}