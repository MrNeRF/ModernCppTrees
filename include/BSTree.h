#include <iostream>
#include <memory>


template<typename ValueType>
class BSTree
{
	public:
		BSTree() = default;	
		~BSTree() = default;
	public:
		void insert(std::unique_ptr<ValueType> val)
		{
			if (val == nullptr)
			{
				return;
			}
			tmpVal = std::move(val);
			insertNode(rootNode);
		};
		void inorder();
	private:

		template<typename T> 
		struct Node 
		{
			Node(T* val) : value(std::make_unique<T>(*val)) {
				std::cout << "Value " << *value << " created" << std::endl;
			};
			~Node() 
			{
				
				std::cout << "Value " << *value << " destroyed" << std::endl;
			}
			std::unique_ptr<T> value;
			std::unique_ptr<Node<T>> leftChild;
			std::unique_ptr<Node<T>> rightChild;
		};

	private:
		void insertNode(std::unique_ptr<Node<ValueType>> &root);
		void inorder(std::unique_ptr<Node<ValueType>> &root);
		
	private:
		std::unique_ptr<Node<ValueType>> rootNode;
		std::unique_ptr<ValueType> tmpVal;
};


template<typename ValueType>
void BSTree<ValueType>::insertNode(std::unique_ptr<Node<ValueType>> &root)
{
	if (root  == nullptr)
	{
		root = std::make_unique<Node<ValueType>>(tmpVal.release());
		tmpVal = nullptr;
		return;
	}

	if (*root->value < *tmpVal)
	{
		insertNode(root->rightChild);
		return;
	}
	else if (*root->value > *tmpVal)
	{
		insertNode(root->leftChild);
		return;
	}

	return;
}

template<typename ValueType>
void BSTree<ValueType>::inorder()
{
	inorder(rootNode);	// rootNode aus den Membervariablen
}


template<typename ValueType>
void BSTree<ValueType>::inorder(std::unique_ptr<Node<ValueType>> &root)
{
	if(root == nullptr)	
	{
		return;
	}

	std::cout << *root->value << std::endl;
	inorder(root->leftChild);
	inorder(root->rightChild);

	return;
}
