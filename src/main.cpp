#include "BSTree.h"


int main()
{
	BSTree<int> tree;
	tree.insert(std::make_unique<int>(2));
	tree.insert(std::make_unique<int>(1));
	tree.insert(std::make_unique<int>(4));
	tree.insert(std::make_unique<int>(6));
	tree.insert(std::make_unique<int>(3));

	tree.inorder();
}
