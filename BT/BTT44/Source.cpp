#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;

node* Createnode(int x)
{
	node* p = new node;
	p->key = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insertnode(Tree& T, int x)
{
	if (T) {
		if (T->key == x)
			return 0;
		if (T->key > x)
			return Insertnode(T->pLeft, x);
		else return Insertnode(T->pRight, x);
	}
	T = new node;
	if (T == NULL) return -1;
	T->key = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}
int DoCao(Tree T)
{
	if (T == NULL)
		return 0;
	int a = 1+ DoCao(T->pLeft);
	int b = 1+DoCao(T->pRight);
	if (a > b)
		return a ;
	else
		return b;
}
void InMuc(Tree& T, int i, int h)
{
	if (T != NULL)
	{
		if (i == h)
			cout << T->key << " ";
		InMuc(T->pLeft, i , h+1);
		InMuc(T->pRight, i , h+1);
	}
}
int main()
{
	Tree T = NULL;
	int n;
	cin >> n;
	while (n != 0)
	{
		Insertnode(T, n);
		cin >> n;
	}
	n = DoCao(T);
	for (int i = 0; i < n; i++)
	{
		int h = 0;
		cout << "Deep " << i + 1 << ": ";
		InMuc(T, i, h);
		cout << endl;
	}
	return 0;
}