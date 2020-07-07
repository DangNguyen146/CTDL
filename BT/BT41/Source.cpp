#include<iostream>
using namespace std;
struct TNode
{
	int key;
	TNode* tLeft;
	TNode* tRight;
};
typedef TNode* Tree;
int InsertTree(Tree& T, int x)
{
	if (T)
	{
		if (T->key > x)
			return InsertTree(T->tLeft, x);
		if (T->key < x)
			return InsertTree(T->tRight, x);
	}
	T = new TNode;
	T->key = x;
	T->tLeft = T->tRight = NULL;
	return 0;
}

void ThayThe1(Tree& p, Tree& T)
{
	if (T->tLeft != NULL)
		ThayThe1(p, T->tLeft);
	else
	{
		p->key = T->key;
		p = T;
		T = T->tRight;
	}
}
void DeleteNodeX1(Tree& T, int x) {
	if (T != NULL)
	{
		if (T->key < x)
			DeleteNodeX1(T->tRight, x);
		else
		{
			if (T->key > x)
				DeleteNodeX1(T->tLeft, x);
			else //tim thấy Node có trường dữ liệu = x 
			{
				TNode* p;
				p = T;
				if (T->tLeft == NULL)
					T = T->tRight;
				else
				{
					if (T->tRight == NULL)
						T = T->tLeft;
					else
						ThayThe1(p, T->tRight);// tìm bên cây con phải
				}
				delete p;
			}
		}
	}

}
bool SNT(int x)
{
	if (x < 2)
		return false;

	for (int i = 2; i <= x / 2; i++)
		if (x % i == 0)
			return false;
	return true;
}
void LNRt(Tree& T, int& x)
{
	if (T)
	{
		LNRt(T->tLeft, x);
		if (SNT(T->key) == true && x == 1)
		{
			x = T->key;
		}
		LNRt(T->tRight, x);
	}
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
	if (x == 0)
	{
		cout << "Not found tree!";
		return 0;
	}

	while (x != 0)
	{
		InsertTree(T, x);
		cin >> x;
	}

	int n;
	cin >> n;
	int temp;

	for (int i = 0; i < n; i++)
	{
		int x = 1;
		LNRt(T, x);
		DeleteNodeX1(T, x);
	}
	if (T == NULL)
	{
		cout << "Not found tree!";
		return 0;
	}
	else
		LNR(T);

	return 0;
}