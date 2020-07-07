#include<iostream>
#include<string>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* themPhanTuVaoCay(node*& root, int x)
{
	if (root != NULL)
	{
		if (root->data > x)
			return themPhanTuVaoCay(root->left, x);
		else
			return themPhanTuVaoCay(root->right, x);
	}
	root = new node;
	root->data = x;
	root->left = root->right = NULL;
	return NULL;
}

void inDanhSachGiamDan(node* TREE)
{
	if (TREE != NULL)
	{
		inDanhSachGiamDan(TREE->right);
		cout << TREE->data << " ";
		inDanhSachGiamDan(TREE->left);
	}
}
bool kiemTraDoiXung(string s)
{
	int dodai = s.length();
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[dodai - i - 1])
			return false;
		
	}
	return true;
}

string chuyenNhiPhan(int x)
{
	string s;
	while (x != 0)
	{
		int doi = x % 2;
		s += (doi + '0');
		x = x / 2;
	}
	return s;
}
void demSoChuoiDoiXung(node* TREE, int& cnt)
{
	if (TREE != NULL)
	{
		demSoChuoiDoiXung(TREE->left, cnt);
		string s = chuyenNhiPhan(TREE->data);
		if (kiemTraDoiXung(s))
			cnt++;
		demSoChuoiDoiXung(TREE->right, cnt);
	}
}
int main() {	
	node* TREE = NULL;
	int x, cnt = 0;
	while (scanf_s("%d", &x)) {
		if (x == 0) {
			inDanhSachGiamDan(TREE);
			cout << endl;
			demSoChuoiDoiXung(TREE, cnt);
			cout << "Co " << cnt << " node thoa de bai." << endl;
			break;
		}
		else
			themPhanTuVaoCay(TREE, x);
	}
}