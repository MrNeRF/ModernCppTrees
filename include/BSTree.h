#include <iostream>
#include <memory>


template<typename ValueType>
class BSTree
{
	public:
		BSTree() = default;	
		~BSTree() = default;
	public:
		void insert(ValueType val)
		{
			insert(val, rootNode);
		};
		void inorder();
	private:

		template<typename T> 
		struct Node 
		{
			Node(T val) : value(val) {};
			T value;
			std::unique_ptr<Node<T>> leftChild;
			std::unique_ptr<Node<T>> rightChild;
		};

	private:
		void insert(ValueType val, std::unique_ptr<Node<ValueType>> &Node);
		void inorder(std::unique_ptr<Node<ValueType>> &rootNode);
	private:
		std::unique_ptr<Node<ValueType>> rootNode;
};


template<typename ValueType>
void BSTree<ValueType>::insert(ValueType valToInsert, std::unique_ptr<Node<ValueType>> &rootNode)
{
	if (rootNode  == nullptr)
	{
		rootNode = std::make_unique<Node<ValueType>>(valToInsert);
		return;
	}

	if (rootNode->value < valToInsert)
	{
		return insert(valToInsert, rootNode->rightChild);
	}
	else if (rootNode->value > valToInsert)
	{
		return insert(valToInsert, rootNode->leftChild);
	}

	return;
}

template<typename ValueType>
void BSTree<ValueType>::inorder()
{
	inorder(rootNode);	
}

template<typename ValueType>
void BSTree<ValueType>::inorder(std::unique_ptr<Node<ValueType>> &rootNode)
{
	if(rootNode == nullptr)	
	{
		return;
	}

	std::cout << rootNode->value << std::endl;
	inorder(rootNode->leftChild);
	inorder(rootNode->rightChild);

	return;
}
