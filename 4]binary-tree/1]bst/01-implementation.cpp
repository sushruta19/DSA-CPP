/* This file is the implementation of BST and some of its basic 
 * operations --> insertion, deletion, search, print, etc.
 * You must include this header file in other BST files.
*/

#include<iostream>
#include<stdexcept>
#include<queue>
using namespace std;

class BstNode {
  public:
  int data;
  BstNode* left;
  BstNode* right;
  BstNode(int x = 0):data{x},left{NULL},right{NULL}{}
};

BstNode* insert(BstNode* root, int data)
{
  if(root == NULL)                      //empty tree
  {
    root = new BstNode(data);
  }
  else if(data <= root->data)          
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}

bool search(BstNode* root, int key)
{
  if(root == NULL)
    return false;
  else if (root->data == key)
    return true;
  else if (key < root->data)
    return search(root->left, key);
  else
    return search(root->right, key);
}

int findMin(BstNode* root)
{
  if(root == NULL)
    throw underflow_error("Tree is Empty!\n");
  if (root->left == NULL) 
    return root->data;
  //search in left subtree
  return findMin(root->left);
}

int findMinIterative(BstNode* root)
{
  if(root == NULL)
    throw underflow_error("Tree is Empty!\n");

  while(root->left!=NULL)
    root = root->left;
  return root->data;
}

int findMax(BstNode* root)
{
  if(root == NULL)
    throw underflow_error("Tree is Empty!\n");
  if (root->right == NULL) 
    return root->data;
  return findMin(root->right);
}

int findMaxIterative(BstNode* root)
{
  if(root == NULL)
    throw underflow_error("Tree is Empty!\n");
  while(root->right!=NULL)
    root = root->right;
  return root->data;
}

int getHeight(BstNode* root)
{
  if(root == NULL)
    return -1;
  return max(getHeight(root->left),getHeight(root->right))+1;
}

void printPreorder(BstNode* root)
{
  if(root == NULL)
    return;
  cout << root-> data << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printInorder(BstNode* root)
{
  if(root == NULL)
    return;
  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

void printPostorder(BstNode* root)
{
  if(root == NULL)
    return;
  printPostorder(root->left);
  printPostorder(root->right);
  cout << root->data << " ";
}

void printLevelorder(BstNode* root)
{
  queue<BstNode*> q;
  q.push(root);
  while(!q.empty())
  {
    cout<<q.front()->data<<" ";
    if(q.front()->left!=NULL)
      q.push(q.front()->left);
    if(q.front()->right!=NULL)
      q.push(q.front()->right);
    q.pop();
  }
}

void deleteBst(BstNode* root)
{
  if(root == NULL)
    return;
  deleteBst(root->left);
  deleteBst(root->right);
  delete root;
}

