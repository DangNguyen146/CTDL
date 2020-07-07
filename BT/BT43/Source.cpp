#include<iostream>
using namespace std;
struct node
{
	int info;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
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
void InMuc(Tree T, int info, int k,int &dem)
{
	if (T == NULL)
		return;
	if (T->info == info && dem == 0)
	{
		cout << k << " ";
		dem = 1;
	}
	InMuc(T->pLeft, info, k + 1, dem);
	InMuc(T->pRight, info , k + 1, dem);
}
int main()
{
	Tree T = NULL;
	int n;
	cin >> n;
	while (n != 0)
	{
		InsertNode(T, n);
		cin >> n;
	}
	cin >> n;
	while (n != 0)
	{
		int k = 0;
		int dem = 0;
		InMuc(T, n, k, dem);
		if (dem == 0)
			cout << -1;
		cout << endl;
		cin >> n;
	}
}