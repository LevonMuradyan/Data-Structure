#ifndef HEIGHT_TREE_HPP
#define HEIGHT_TREE_HPP
#include <iostream>
#include "binary_tree.hpp"

template < typename T >
class HTree : public BTree<T> {
public:
	HTree();
	~HTree() override;

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
HTree<T>::HTree() {
	printf("Height Tree Constructor\n\n");
	root = NULL;
}

template < typename T >
HTree<T>::~HTree() {
	printf("Height Tree Destructor\n");
	destroy_tree(root);
}

template <typename T >
void HTree<T>::destroy_tree(typename BTree<T>::Node* root) {
	if (root != NULL) {
		destroy_tree(root->left);
		destroy_tree(root->right);
		delete root;
	}
}


///function to insert element in height tree
template < typename T >
void HTree<T>::insert(const T& key, typename BTree<T>::Node* root)
{
	if (key < root->key) {
		if (root->left != NULL) {
			insert(key, root->left);
		}
		else {
			printf("Height Tree insert function\n");
			root->left = new typename BTree<T>::Node(key);
		}
	}
	else if (key >= root->key) {
		if (root->right != NULL) {
			insert(key, root->right);
		}
		else {
			printf("Height Tree insert function\n");
			root->right = new typename BTree<T>::Node(key);
		}
	}
}

template < typename T >
void HTree<T>::insert(const T& key) {

	if (root != NULL) {
		insert(key, root);
	}
	else {
		printf("Height Tree insert function\n");
		root = new typename BTree<T>::Node(key);
	}
}

template < typename T >
typename BTree<T>::Node* HTree<T>::search(const T& key, typename BTree<T>::Node* root) {

	if (root != NULL) {
		if (key == root->key) {
			printf("\nHeight Tree search function\n");
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
		printf("\nHeight Tree search function\n");
		return NULL;
	}
}

template < typename T >
typename BTree<T>::Node* HTree<T>::search(const T& key) {
	return search(key, root);
}

template < typename T >
void HTree<T>::inorder_print(typename BTree<T>::Node* root) {
	if (root != NULL) {
		inorder_print(root->left);
		std::cout << root->key << ",";
		inorder_print(root->right);
	}
}

template < typename T >
void HTree<T>::inorder_print() {
	printf("\nHeight Tree inorder_print function\n");
	inorder_print(root);
	std::cout << "\n\n";
}

#endif // HEIGHT_TREE_HPP
