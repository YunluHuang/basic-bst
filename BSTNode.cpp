#include "BSTNode.h"
#include "stdio.h"

BSTNode * BSTNode::getSuccessor() {
  BSTNode *curr = right;
  if(curr) {
    while(curr->left) {
      curr = curr->left;
    }
  }
  return curr;
}

bool BSTNode::insert(int data) {
  if(data == this->data) return false;
  if(data > this->data) {
    if(!right) {
      right = new BSTNode(data);
    } else {
      return right->insert(data);
    }
  } else {
    if(!left) {
      left = new BSTNode(data);
    } else {
      return left->insert(data);
    }
  }
  return true;
}

bool BSTNode::find(int data) {
  if(data == this->data) return true;
  if(data > this->data) {
    if(right) return right->find(data);
  } else {
    if(left) return left->find(data);
  }
  return false;
}

bool BSTNode::remove(int data, BSTNode * &parent) {
  BSTNode *replaceNode = 0;
  if(data == this->data) {
    if(!left) {
      replaceNode = right;
    } else if(!right) {
      replaceNode = left;
    } else if (left && right) {
      replaceNode = getSuccessor();
      replaceNode->left = left;
      replaceNode->right = right;
    }
    if(data < parent->data) {
      parent->left = replaceNode;
    } else {
      parent->right = replaceNode;
    }
    return true;
  }

  BSTNode *curParent = this;
  if(data < this->data) {
    if(left) return left->remove(data, curParent);
  } else {
    if(right) return right->remove(data, curParent);
  }
  return false;
}

void BSTNode::traverse_inOrder(int * &dataArr, int &currCount) {
  if(left) {
    left->traverse_inOrder(dataArr, currCount);
  }
  dataArr[currCount] = data;
  currCount++;
  if(right) {
    right->traverse_inOrder(dataArr, currCount);
  }
}

BSTNode::~BSTNode() {
  // printf("called BSTNode destructor, data = %d\n", data);
  if(left) delete left;
  if(right) delete right;
  left = 0;
  right = 0;
}
