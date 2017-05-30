#pragma once

#include "BSTNode.h"

class BST {
public:
  BSTNode *root;
  int size;

  BST(): root(0), size(0) {};
  BST(int *dataArr, int arrLen);
  ~BST();

  bool insert(int data);
  bool find(int data);
  bool remove(int data);

  /**
    inorder traverse the tree, write the pointer to inorder data array with
    size of bst.size to the given dataArr pointer
  */
  void traverse_inOrder(int * &dataArr);
};
