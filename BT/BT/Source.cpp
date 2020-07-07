#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int info;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
node* CreateNode(int x)
{
	node* p = new node;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int InsertNode(Tree& T, int x)
{
	if (T)
	{
		if (T->info == x)
			return 0;
		if (T->info > x)
			return InsertNode(T->pLeft, x);
		else
		{
			return InsertNode(T->pRight, x);
		}
	}
	T = new node;
	if (T == NULL)
		return -1;
	T->info = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}
int ChieuCao(Tree T)
{
	if (!T)
		return 0;
	int a =1+ ChieuCao(T->pLeft);
	int b =1+ ChieuCao(T->pRight);
	if (a > b)
		return a;
	else
	{
		return b;
	}
}
int main()
{
	Tree T =NULL;
	int n;
	cin >> n;
	int dem;
	for (int i = 0; i < n; i++)
	{
		cin >> dem;
		InsertNode(T, dem);
	}
	cout << "Chieu cao cua cay la: " << ChieuCao(T);
	return 0;
}