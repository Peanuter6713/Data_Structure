#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

#define MaxSize 20
#define ElemType int

typedef struct List
{
    ElemType data[MaxSize];
    int length;
} SeqList;

void CreateSeqList(SeqList &L)
{
    srand(time(NULL));
    int len = rand() % 20 + 1;
    for (int i = 0; i < len; i++)
    {
        L.data[i] = rand() % 20 + rand() % 10;
    }
    L.length = len;
    sort(L.data, L.data + L.length);
}

void PrintSeqList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void InsertSeqList(SeqList &L, ElemType x)
{
    L.length++;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] > x && i != L.length - 1)
        {
            for (int j = L.length; j > i; j--)
            {
                L.data[j] = L.data[j - 1];
            }
            L.data[i] = x;
            break;
        }
        else
        {
            L.data[L.length - 1] = x;
        }
    }
}

int main()
{
    SeqList L;
    CreateSeqList(L);
    PrintSeqList(L);
    int x;
    cout << "Input data:" << endl;
    cin >> x;
    cout << "After insertion." << endl;
    InsertSeqList(L, x);
    PrintSeqList(L);
}
