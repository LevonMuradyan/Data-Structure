#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <iostream>
#include <queue>

template < typename T >
class BTree {
protected:
	struct Node {
		int key;
		Node* left;
		Node* right;

		Node() {}
		Node(
			const int& key,
			Node* left = nullptr,
			Node* right = nullptr)
			: left(left), right(right), key(key) {}
	};
public:
	BTree();
	virtual ~BTree();

	virtual void insert(const T& key);
	virtual Node* search(const T& key);
	virtual void inorder_print();

private:
	void destroy_tree(Node* root);
	void insert(const T& key, Node* root);
	Node* search(const T& key, Node* root);
	void inorder_print(Node* root);

private:
	Node* root;
};

template < typename T >
BTree<T>::BTree() {
	printf("Binary Tree Constructor\n");
	root = NULL;
}

template < typename T >
BTree<T>::~BTree() {
	printf("Binary Tree Destructor\n");
	destroy_tree(root);
}

template <typename T >
void BTree<T>::destroy_tree(BTree<T>::Node* root) {
	
	if (root != NULL) {
		destroy_tree(root->left);
		destroy_tree(root->right);
		delete root;
	}
}

///function to insert element in binary tree
template < typename T >
void BTree<T>::insert(const T& key, BTree<T>::Node* root)
{
	
	std::queue<Node*> q;
	q.push(root);

	/// Do level order traversal until we find 
	/// an empty place.  
	while (!q.empty()) {
		Node* root = q.front();
		q.pop();

		if (!root->left) {
			printf("Binary Tree insert function\n");
			root->left = new Node(key);
			break;
		}

		else {
			q.push(root->left);
		}

		if (!root->right) {
			printf("Binary Tree insert function\n");
			root->right = new Node(key);
			break;
		}

		else {
			q.push(root->right);
		}
	}
}

template < typename T >
void BTree<T>::insert(const T& key) {
	
	if (root != NULL) {
		insert(key, root);
	}
	else {
		printf("Binary Tree insert function\n");
		root = new Node(key);
	}
}

template < typename T >
typename BTree<T>::Node* BTree<T>::search(const T& key, BTree<T>::Node* root) {

	if (root != NULL) {
		if (key == root->key) {
			printf("Binary Tree search function\n");
			return root;
		}
		if (key < root->key) {
			return search(key, root->left);
		}
		else {
			return search(key, root->right);
		}
	}
	else {
		printf("Binary Tree search function\n");
		return NULL;
	}
}

template < typename T >
typename BTree<T>::Node* BTree<T>::search(const T& key) {
	return search(key, root);
}

template < typename T >
void BTree<T>::inorder_print(BTree<T>::Node* root) {
	if (root != NULL) {
		inorder_print(root->left);
		std::cout << root->key << ",";
		inorder_print(root->right);
	}
}

template < typename T >
void BTree<T>::inorder_print() {
	printf("Binary Tree inorder_print function\n");
	inorder_print(root);
	std::cout << "\n";
}

#endif // BINARY_TREE_HPP

