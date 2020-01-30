#include <iostream>
#include "binary_tree.hpp"
#include "binary_search_tree.hpp"
#include "avl_tree.hpp"

int main() {

	//btree tree;
	BTree<int>** bt = new BTree<int>*[2];
	bt[0] = new BSTree<int>();
	bt[1] = new HTree<int>();

	BSTree<int>* bst = new AVLTree<int>();

	//BTree<int>* avlt = new AVLTree<int>(); //error: can't point to AVLTree
	bt[0]->insert(10);
	bt[0]->insert(6);
	bt[0]->insert(14);
	bt[0]->insert(5);
	bt[0]->insert(8);
	bt[0]->insert(11);
	bt[0]->insert(18);

	bt[1]->insert(20);
	bt[1]->insert(106);
	bt[1]->insert(85);
	bt[1]->insert(5);
	bt[1]->insert(10);
	bt[1]->insert(113);
	bt[1]->insert(19);

	bst->insert(100);
	bst->insert(66);
	bst->insert(124);
	bst->insert(95);
	bst->insert(78);
	bst->insert(161);
	bst->insert(198);

	printf("\n%d\n", bt[0]->search(11)->key);
	printf("\n%d\n", bt[1]->search(113)->key);
	printf("\n%d\n", bst->search(100)->key);
	

	bt[0]->inorder_print();
	bt[1]->inorder_print();
	bst->inorder_print();

	delete bt[0];
	delete bt[1];
	delete bst;
	
	

}
