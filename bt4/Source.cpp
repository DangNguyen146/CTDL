#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int info;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
void CreateTree(Tree& T)
{
	T = NULL;
}
node* CreateNode(int x)
{
	node* p = new node;
	if (p == NULL)
		return 0;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insertnode(Tree& T, int x)
{
	if (T) {
		if (T->info == x)
			return 0;
		if (T->info > x)
			return Insertnode(T->pLeft, x);
		else
			return Insertnode(T->pRight, x);
	}
	T = new node;
	T->info = x;
	T->pLeft = NULL;
	T->pRight = NULL;
	return 1;
}
void input(Tree& T)
{
	while (1)
	{
		long int x;
		cin >> x;
		if (x == 0)
			break;
		Insertnode(T, x);
	}
}
int ChieuCao(Tree T)
{
	if (T != NULL)
	{
		return 0;
		int a = ChieuCao(T->pLeft);
		int b = ChieuCao(T->pRight);
		if (a > b)
			return a + 1;
		else
			return b + 1;
	}
}
int DemTheoMuc(Tree T)
{
	int dem = 0;
	queue<Tree>a;
	a.push(T);
	while (!a.empty())
	{
		node* p = a.front();
		while (!a.empty())
		{
			node* p = a.front();
			cout <<a.size()<<": "<< p->info << " ";
			a.pop();
			if (p->pLeft != NULL)
			{
				a.push(p->pLeft);
			}
			if (p->pRight != NULL)
			{
				a.push(p->pRight);
			}
			dem++;
		}

	}
	return dem;
}
int main()
{
	Tree T;
	int x;
	CreateTree(T);
	input(T);
	cout<<"Tong cac muc la"<<DemTheoMuc(T);
	return 0;
}