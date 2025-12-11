// Specification file for the IntBinaryTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include "main.cpp";

class BinaryTree {
private:
   // TreeNode is a private structure for IntBinaryTree nodes.
   struct TreeNode {
      customer my_customer;         // The value in the node
      int completion_time;          // Time left to complete balloon animal, ordered lowest to highest. each balloon animal has an associated timeweight which
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   // root points to the topmost node of the tree.
   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(int, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   BinaryTree()     { root = nullptr; }

   // Destructor deallocates all nodes in the tree.
   ~BinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, and removing nodes.
   void insertNode(int);
   void remove(int);

   // Public wrappers for tree traversal functions.
   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }
};

// Implementation file for the IntBinaryTree class
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->completion_time < nodePtr->completion_time)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

// insertNode creates a new node to hold num as its value,
// and passes it to the insert function.                  
void BinaryTree::insertNode(int num) {
   TreeNode *newNode;      // Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->completion_time = num;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void BinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   

// remove calls deleteNode to delete the      
// node whose value member is the same as num.
void BinaryTree::remove(int num) {
   deleteNode(num, root);
}

// deleteNode deletes the node whose value 
// member is the same as num.              
void BinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}

// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void BinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

// The displayPreOrder member function displays the values      
// in the subtree pointed to by nodePtr, via preorder traversal.
void BinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

// The displayPostOrder member function displays the values     
// in the subtree pointed to by nodePtr, via postorder traversal.
void BinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

#endif // INTBINARYTREE_H
