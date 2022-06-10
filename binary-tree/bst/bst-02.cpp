#include<climits>
#include "bst-01.cpp"
//The above source file "bst-01.cpp" contains the necessary header files and
//implementation of binary search tree and 
//its basic operations(insert, delete entire tree, print, search, get Height, get min, max)

//binary tree node
class BtNode {
  public:
  int data;
  BtNode* left;
  BtNode* right;
  BtNode(int x=0):data{x},left{NULL},right{NULL}{}
};

bool isSubtreeLesser(BtNode* root, int value)
{
  if(root == NULL)
  {
    return true;
  }
  else if(root->data <= value && isSubtreeLesser(root->left,value) && isSubtreeLesser(root->right,value))
  {
    return true;
  }
  else return false;
}

bool isSubtreeGreater(BtNode* root, int value)
{
  if(root == NULL)
  {
    return true;
  }
  else if(root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value))
  {
    return true;
  }
  else return false;
}

//function to check whether given binary tree is a BST
bool isBinarySearchTree(BtNode* root)
{
  if(root == NULL)
  {
    return true;
  }
  else if(isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data)
          && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
  {
    return true;
  }
  else return false;
}

//its a utility function so that we don't have to enter minValue and maxValue in isBST() function
bool isBstUtil(BtNode* root, int minValue, int maxValue)
{
  if(root == NULL)
    return true;
  else if(root->data >= minValue && root->data < maxValue && isBstUtil(root->left, minValue, root->data)
          && isBstUtil(root->right, root->data, maxValue))
  {
    return true;
  }
  else return false;
}

//function to check whether given binary tree is a BST(more efficient)
bool isBST(BtNode* root)
{
  return isBstUtil(root, INT_MIN, INT_MAX);
}

//Another way to check whether Binary Tree is BST or not by doing a inorder traversal and see whether 
//the elements are sorted

