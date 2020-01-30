#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>
#include "binary_tree.hpp"

template < typename T >
class BSTree : public BTree<T> {
public:
	BSTree();
	~BSTree() override;

	void insert(const T& key) override;
	typename BTree<T>::Node* search(const T& key) override;
	void inorder_print() override;

private:
	void destroy_tree(typename BTree<T>::Node* root);
	void insert(const T& key, typename BTree<T>::Node* root);
	typename BTree<T>::Node* search(const T& key, typename BTree<T>::Node* root);
	void inorder_print(typename BTree<T>::Node* root);

private:
	typename BTree<T>::Node* root;

};

template < typename T >
BSTree<T>::BSTree() {
	printf("Binary Search Tree Constructor\n\n");
	root = NULL;
}

template < typename T >
BSTree<T>::~BSTree() {
	printf("Binary Search Tree Destructor\n");
	destroy_tree(root);
}

template <typename T >
void BSTree<T>::destroy_tree(typename BTree<T>::Node* root) {
	if (root != NULL) {
		destroy_tree(root->left);
		destroy_tree(root->right);
		delete root;
	}
}


///function to insert element in binary search tree
template < typename T >
void BSTree<T>::insert(const T& key, typename BTree<T>::Node* root)
{
	if (key < root->key) {
		if (root->left != NULL) {
			insert(key, root->left);
		}
		else {
			printf("Binary Search Tree insert function\n");
			root->left = new typename BTree<T>::Node(key);
		}
	}
	else if (key >= root->key) {
		if (root->right != NULL) {
			insert(key, root->right);
		}
		else {
			printf("Binary Search Tree insert function\n");
			root->right = new typename BTree<T>::Node(key);
		}
	}
}

template < typename T >
void BSTree<T>::insert(const T& key) {

	if (root != NULL) {
		insert(key, root);
	}
	else {
		printf("Binary Search Tree insert function\n");
		root = new typename BTree<T>::Node(key);
	}
}

template < typename T >
typename BTree<T>::Node* BSTree<T>::search(const T& key, typename BTree<T>::Node* root) {

	if (root != NULL) {
		if (key == root->key) {
			printf("\nBinary Search Tree search function\n");
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
		printf("\nBinary Search Tree search function\n");
		return NULL;
	}
}

template < typename T >
typename BTree<T>::Node* BSTree<T>::search(const T& key) {
	return search(key, root);
}

template < typename T >
void BSTree<T>::inorder_print(typename BTree<T>::Node* root) {
	if (root != NULL) {
		inorder_print(root->left);
		std::cout << root->key << ",";
		inorder_print(root->right);
	}
}

template < typename T >
void BSTree<T>::inorder_print() {
	printf("\nBinary Search Tree inorder_print function\n");
	inorder_print(root);
	std::cout << "\n";
}

#endif // BINARY_SEARCH_TREE_HPP