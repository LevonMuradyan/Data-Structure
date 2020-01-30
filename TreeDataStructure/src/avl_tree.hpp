#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include <iostream>
#include "binary_search_tree.hpp"
#include "height_tree.hpp"


template < typename T >
class AVLTree : public BSTree<T>, public HTree<T> {
public:
	AVLTree();
	~AVLTree() override;

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
AVLTree<T>::AVLTree() {
	printf("AVL Tree Constructor\n\n");
	root = NULL;
}

template < typename T >
AVLTree<T>::~AVLTree() {
	printf("AVL Tree Destructor\n");
	destroy_tree(root);
}

template <typename T >
void AVLTree<T>::destroy_tree(typename BTree<T>::Node* root) {
	if (root != NULL) {
		destroy_tree(root->left);
		destroy_tree(root->right);
		delete root;
	}
}


///function to insert element in height tree
template < typename T >
void AVLTree<T>::insert(const T& key, typename BTree<T>::Node* root)
{
	if (key < root->key) {
		if (root->left != NULL) {
			insert(key, root->left);
		}
		else {
			printf("AVL Tree insert function\n");
			root->left = new typename BTree<T>::Node(key);
		}
	}
	else if (key >= root->key) {
		if (root->right != NULL) {
			insert(key, root->right);
		}
		else {
			printf("AVL Tree insert function\n");
			root->right = new typename BTree<T>::Node(key);
		}
	}
}

template < typename T >
void AVLTree<T>::insert(const T& key) {

	if (root != NULL) {
		insert(key, root);
	}
	else {
		printf("AVL Tree insert function\n");
		root = new typename BTree<T>::Node(key);
	}
}

template < typename T >
typename BTree<T>::Node* AVLTree<T>::search(const T& key, typename BTree<T>::Node* root) {

	if (root != NULL) {
		if (key == root->key) {
			printf("\nAVL Tree search function\n");
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
		printf("AVL Tree search function\n");
		return NULL;
	}
}

template < typename T >
typename BTree<T>::Node* AVLTree<T>::search(const T& key) {
	return search(key, root);
}

template < typename T >
void AVLTree<T>::inorder_print(typename BTree<T>::Node* root) {
	if (root != NULL) {
		inorder_print(root->left);
		std::cout << root->key << ",";
		inorder_print(root->right);
	}
}

template < typename T >
void AVLTree<T>::inorder_print() {
	printf("AVL Tree inorder_print function\n");
	inorder_print(root);
	std::cout << "\n\n";
}

#endif // AVL_TREE_HPP
