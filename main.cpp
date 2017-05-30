#include "BST.h"
#include "stdio.h"

void test_insert_one_ele();
void test_insert_n_ele();
void test_find();
void test_remove();

int main() {
  test_remove();
  return 0;
}

void test_insert_one_ele() {
  BST bst = BST();
  if(bst.insert(0)) {
    printf("Successfully inserted 0, the root data is %d\n", bst.root->data);
  } else {
    printf("Fail\n");
  }
}

void test_insert_n_ele() {
  int data[10] = {1, 5, 3, 9, 8, 2, 6, 4, 7, 0};
  BST bst = BST(data, 10);
  if(bst.size != 10) {
    printf("Fail\n");
  }
  int *bst_data = new int[bst.size];
  bst.traverse_inOrder(bst_data);
  for(int i = 0; i < bst.size; i++) {
    printf("%d ", bst_data[i]);
  }
  printf("\n");
  delete[] bst_data;
}

void test_find() {
  int data[5] = {3, 5, 1, 9, 0};
  BST bst = BST(data, 5);
  if(bst.find(7)) {
    printf("Fail, 7 is not in the bst\n");
  } else if (!bst.find(5)) {
    printf("Fail, 5 is in the bst\n");
  } else if (!bst.find(3)) {
    printf("Fail, 3 is in the bst\n");
  } else {
    printf("Success\n");
  }
}

void test_remove() {
  int data[10] = {1, 5, 3, 9, 8, 2, 6, 4, 7, 0};
  BST bst = BST(data, 10);
  if(bst.remove(11)) {
    printf("Fail, 11 is not in the bst\n");
  } else if (!bst.remove(1)) {
    printf("Fail, 1 is in the bst\n");
  }
  if(bst.size != 9) {
    printf("Fail\n");
  }
  int *bst_data = new int[bst.size];
  bst.traverse_inOrder(bst_data);
  for(int i = 0; i < bst.size; i++) {
    printf("%d ", bst_data[i]);
  }
  printf("\n");
  delete[] bst_data;
}
