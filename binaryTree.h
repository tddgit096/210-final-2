#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "main.cpp";
/*
This class was copy pasted from IntBinaryTree.h  from Module 14 Lesson: BST Class.
It is in the process of being modified to fit with the assignment
*/


class BinaryTree {
    private:

struct TreeNode {
private:
    customer myCustomer;
    TreeNode *left; // Pointer to left child node
    TreeNode *right; // Pointer to right child node
    // root points to the topmost node of the tree
    TreeNode *root;
    // methods
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void insert(TreeNode *&, TreeNode *&);
public:
    BinaryTree() { root = nullptr; }
    // Destructor deallocates all nodes in the tree.
    ~IntBinaryTree() { destroySubTree(root); }
    
    // Public interface for inserting, searching, and removing nodes.    
    void displayInOrder() const { displayInOrder(root); }
};



}

#endif // BINARYTREE_H