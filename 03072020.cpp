//бінарне берево
#include <iostream>
using namespace std;
class NodeTree
{
	int val;
public:
	NodeTree* left;
	NodeTree* right;
	NodeTree(int v);
	int GetVal() const;
	void Print()const;
};
NodeTree::NodeTree(int v) : val(v) { left = nullptr; right = nullptr; }
int NodeTree::GetVal() const
{
	return val;
}
void NodeTree::Print() const
{
	cout << val << '\t';
}

class Tree
{
	NodeTree* root;
	void Print(NodeTree* node); // по порядку
public:
	void Insert(int v);
	Tree() { root = 0; }
	NodeTree* Insert(NodeTree* node, int v);
	void Print();
	void Clear(NodeTree* node);
	void Clear();
	~Tree();
	NodeTree* Find(NodeTree* node, int v);
	NodeTree* Find(int v);

};

void Tree::Print(NodeTree* node)
{
	if (node) //якщо вказівник існує
	{
		Print(node->left);
		node->Print(); // якщо міняти місцями виводитиме по різному
		Print(node->right);
	}
}
void Tree::Insert(int v)
{
	if (!root) root = new NodeTree(v);
	else
	{
		Insert(root, v);
	}
}
NodeTree* Tree::Insert(NodeTree* node, int v)
{
	if (!node)
		return new NodeTree(v);
	if (node->GetVal() == v)
		return node;
	if (node->GetVal() < v)
		node->right = Insert(node->right, v);
	else
		node->left = Insert(node->left, v);
	return node;
}
void Tree::Print()
{
	Print(root);
}
void Tree::Clear(NodeTree* node)
{
	if (node)
	{
		Clear(node->left);
		Clear(node->right);
		delete node;
	}
}
void Tree::Clear()
{
	Clear(root);
	root = nullptr;
}
Tree::~Tree()
{
	Clear();
}

NodeTree* Tree::Find(NodeTree* node, int v)
{
	if (!node)
		return nullptr;
	if (node->GetVal() == v)
		return node;
	if (node->GetVal() > v)
		return Find(node->left, v);
	else
		return Find(node->right, v);
}

NodeTree* Tree::Find(int v)
{
	return Find(root, v);
}

int main()
{
	Tree D;
	D.Insert(50);
	D.Insert(60);
	D.Insert(40);
	D.Insert(30);
	D.Insert(45);
	D.Insert(55);
	D.Insert(70);
	D.Print();
	//	D.Clear();
		//D.Print();
	NodeTree* f = D.Find(40);
	if (f)
	{
		cout << endl;
		f->Print();
	}
	else
		cout << "\nNema takogo !" << endl;
	cout << "\nThe end" << endl;

}