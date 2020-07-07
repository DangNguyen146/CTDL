#include<iostream>
using namespace std;
struct node
{
	int info;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
void CreateTree(Tree &T)
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


int Dem(Tree& T)
{
	if (T == NULL)
		return 0;
	if ((T->pLeft == NULL) && (T->pRight == NULL))
		return 1 + Dem(T->pLeft) + Dem(T->pRight);
	else

		return Dem(T->pLeft) + Dem(T->pRight);
}
int main()
{
	Tree T;
	int x;
	CreateTree(T);
	input(T);
	cout << "SO CAY CON BAC 2 la: " << Dem(T);
	return 0;
}