#pragma once

class BSTNode {
public:
  int data;
  BSTNode *left;
  BSTNode *right;

  BSTNode(): data(0), left(0), right(0) {};
  BSTNode(int data): data(data), left(0), right(0) {this->data = data;};
  ~BSTNode();

  BSTNode * getSuccessor();
  // BSTNode * getPredessor();

  bool insert(int data);
  bool find(int data);
  bool remove(int data, BSTNode * &parent);

  void traverse_inOrder(int * &dataArr, int &currCount);
};
