#include "BST.h"
#include "stdio.h"

BST::BST(int *dataArr, int arrLen): root(0), size(0) {
  for(int i = 0; i < arrLen; i++) {
    if(insert(dataArr[i])) size++;
  }
}

bool BST::insert(int data) {
  if(!root) {
    root = new BSTNode(data);
    return true;
  }
  return root->insert(data);
}

bool BST::find(int data) {
  if(!root) return false;
  return root->find(data);
}

bool BST::remove(int data) {
  if(!root) return false;

  if(root->data == data) {
    if(!root->left) {
      root = root->right;
    } else if(!root->right) {
      root = root->left;
    } else {
      BSTNode *temp = root->removeSuccessor();
      temp->left = root->left;
      temp->right = root->right;
      root = temp;
    }
    size--;
    return true;
  }
  
  BSTNode *dummy = 0;
  bool success = root->remove(data, dummy);
  if(success) size--;
  return success;
}

void BST::traverse_inOrder(int * &dataArr) {
  if(root) {
    int count = 0;
    root->traverse_inOrder(dataArr, count);
  }
}

BST::~BST() {
  // printf("called BST destructor\n");
  if(root) delete root;
  root = 0;
}
