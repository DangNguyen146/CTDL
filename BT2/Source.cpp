#include<iostream>
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
node* SearchNode(Tree& T,int x)
{
	if (T != NULL)
	{
		if (T->info = x)
			return T;
		else
		{
			if (T->info < x)
				return	SearchNode(T->pRight, x);
			else
			{
				return SearchNode(T->pLeft, x);
			}
		}
	}
	return NULL;
}
int Dem(Tree& T,int x)
{
	if (T == NULL)
		return 0;
	if (T->pLeft != NULL && T->pRight != NULL && T->info == x)
		return 1+Dem(T->pRight, x);
}
int main()
{
	Tree T;
	int x;
	CreateTree(T);
	input(T);
	while (1)
	{
		cin >> x;
		Insertnode(T, x);
		if (x == 0)
			break;
		cout << "SO con co key =x la: " << Dem(T, x) << endl;
	}
	return 0;
}