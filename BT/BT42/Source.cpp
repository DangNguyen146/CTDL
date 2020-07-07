#include<iostream>
using namespace std;
struct tNode
{
	int key;
	tNode* tLeft;
	tNode* tRight;
};
typedef tNode* Tree;
int InsertTree(Tree& T, int x)
{
	if (T)
	{
		if (T->key > x)
			return InsertTree(T->tLeft, x);
		if (T->key < x)
			return InsertTree(T->tRight, x);
	}
	T = new tNode;
	T->key = x;
	T->tLeft = T->tRight = NULL;
	return 0;
}
tNode* Search(Tree T, int x, int& dem)
{
	if (T != NULL)
	{
		if (T->key == x)
		{
			if (T->tLeft != NULL)
				dem++;
			if (T->tRight != NULL)
				dem++;
			return T;
		}
		else
			if (T->key < x)
				Search(T->tRight, x, dem);
			else
				Search(T->tLeft, x, dem);
	}
	return NULL;
}
void LNR(Tree T)
{
	if (T)
	{
		LNR(T->tLeft);
		cout << T->key << " ";
		LNR(T->tRight);
	}
}
int main()
{
	Tree T = NULL;
	int x;
	cin >> x;
	while (x != 0)
	{
		InsertTree(T, x);
		cin >> x;
	}
	LNR(T);
	cout << endl;
	cin >> x;
	int dem = 0;
	while (x != 0)
	{
		dem = 0;
		cout << "Node " << x << " co bac la ";
		Search(T, x, dem);
		cout << dem << "." << endl;
		cin >> x;
	}
}