#include "01-implementation.cpp"
//The above source file "bst-01.cpp" contains the necessary header files and
//implementation of binary search tree and 
//its basic operations(insert, delete entire tree, print, search, get Height, get min, max)

//function to get minimum valued Node in BST
BstNode* getMinNode(BstNode* root)
{
  if(root == NULL)
    return NULL;
  else if(root->left == NULL)
    return root;
  else
    return getMinNode(root->left);
}

//function to get the desired node
BstNode* getNode(BstNode* root, int data)
{
  if(root == NULL)
    return NULL;
  else if(data < root->data)
    return getNode(root->left, data);
  else if(data > root->data)
    return getNode(root->right, data);
  else  //if found
    return root;
}

//function to find inorder successor in O(logn) = O(h) time
BstNode* getSuccessor(BstNode* root, int data)
{
  //search the node
  BstNode* current = getNode(root, data);
  if(current == NULL)     //if node not found
    return NULL;
  if(current->right != NULL)  //if right subtree exists
      return getMinNode(current->right);         //return minimum node in right subtree to find successor
  else
  {
    BstNode* successor = NULL;
    BstNode* ancestor = root;
    while(ancestor != current)
    {
      if(current->data < ancestor->data)
      {
        successor = ancestor;             //successor would be the ancestor whose left subtree would have current Node
        ancestor = ancestor->left;
      }
      else ancestor = ancestor->right;
    }
    return successor;
  }
}