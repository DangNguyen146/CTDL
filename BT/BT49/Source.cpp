#include<iostream>
#include<string>
using namespace std;
struct node
{
	int key;
	int test = 1;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
int Insertnode(Tree& T, int x)
{
	if (T) {
		if (T->key == x)
		{
			T->test++;
			return 1;
		}
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
int DeleteNode(Tree& T)
{
	if (T != NULL)
	{
		if(T->pRight !=NULL)
			return DeleteNode(T->pRight);
		else
		{
			cout << T->key << endl;
			if (T->test != 1)
				T->test--;
			else if(T->test == 1)
			{
				node* p = T;
				if (T->pLeft == NULL)
					T = T->pRight;
				else
				{
					if (T->pRight == NULL)
						T = T->pLeft;
				}
				delete p;
				return 1;
			}
		}
	}
}
int main()
{
	Tree T=NULL;
	char a;
	while (1)
	{
		cin >> a;
		if (a == 'U')
		{
			int b;
			cin >> b;
			Insertnode(T, b);
			cin.ignore();
		}
		if (a == 'E')
			break;
		if (a == 'O')
		{
			if (T != NULL)
			{
				DeleteNode(T);
				cin.ignore();
			}
			else
			{
				cout << "NULL" << endl;
			}
		}

	}
	return 0;
}