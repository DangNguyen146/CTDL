#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pleft;
	node* pright;
};
typedef node* TREE;

node* Createnode(int x)
{
	node* p;
	p = new node;
	p->key = x;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
int Insertnode(TREE& T, int x)
{
	if (T) {
		if (T->key == x)
			return 0;
		if (T->key > x)
			return Insertnode(T->pleft, x);
		else return Insertnode(T->pright, x);
	}
	T = new node;
	if (T == NULL) return -1;
	T->key = x;
	T->pleft = T->pright = NULL;
	return 1;
}
int DoCao(TREE t)
{
	if (t == NULL)
		return 0;
	int a = DoCao(t->pleft);
	int b = DoCao(t->pright);
	if (a > b)
		return a + 1;
	else
		return b + 1;
}
void InNodeMucm(TREE t, int i, int m, int& count)
{
	if (t != NULL)
	{
		if (i == m)
			count++;
		InNodeMucm(t->pleft, i + 1, m, count);
		InNodeMucm(t->pright, i + 1, m, count);
	}

}
void Xuat(TREE t)
{

	for (int i = 0; i < DoCao(t); i++)
	{
		int count = 0;
		InNodeMucm(t, 0, i, count);
		cout << "So node muc " << i << " cua cay la: " << count;
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	TREE t = NULL;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		Insertnode(t, x);
	}
	Xuat(t);

}