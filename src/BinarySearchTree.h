#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value);
    TreeNode* remove(TreeNode* node, int value);
    TreeNode* findMin(TreeNode* node);
    void inOrder(TreeNode* node);
    void preOrder(TreeNode* node);
    void postOrder(TreeNode* node);

public:
    BinarySearchTree();
    void insert(int value);
    void remove(int value);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

#endif // BINARYSEARCHTREE_H
