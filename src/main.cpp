#include "BSTree.h"


int main()
{
	BSTree<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(4);
	tree.insert(6);
	tree.insert(3);

	tree.inorder();
}