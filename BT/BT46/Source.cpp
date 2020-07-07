#include<iostream>
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
void Dembac1(Tree T,int &dem)
{
	if (T != NULL)
	{
		Dembac1(T->pLeft, dem);
		Dembac1(T->pRight, dem);
		if((T->pLeft!=NULL && T->pRight==NULL)|| (T->pLeft == NULL && T->pRight != NULL))
			dem++;
	}
}
int main()
{
	Tree T = NULL;
	int n;
	cin >> n;
	int dem; int k = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> dem;
		InsertNode(T, dem);
	}
	Dembac1(T, k);
	cout << "So node bac 1 cua cay la: " << k;
	return 0;
}