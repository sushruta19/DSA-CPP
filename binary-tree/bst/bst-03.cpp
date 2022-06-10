#include "bst-01.cpp"
//The above source file "bst-01.cpp" contains the necessary header files and
//implementation of binary search tree and 
//its basic operations(insert, delete entire tree, print, search, get Height, get min, max)

/*************************Deleting a single node from BST*********************/

BstNode* deleteNode(BstNode* root, int data)
{
  if(root == NULL)
    return NULL;
  else if(data < root->data)
    root->left = deleteNode(root->left, data);
  else if(data > root->data)
    root->right = deleteNode(root->right, data);
  else  //refers to root->data == data, i.e., when we have found the data to be deleted
  {
    //case 1 : no child
    if(root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
    }
    //case 2 : only one child
    else if(root->left == NULL)
    {
      BstNode* temp = root->right;
      root = root->right;
      delete temp;
    }
    else if(root->right == NULL)
    {
      BstNode* temp = root;
      root = root->left;
      delete temp;
    }
    else //case 3: 2 children
    {
      root->data = findMin(root->right);
      root->right = deleteNode(root->right, root->data);  //handle zero or one child case
    }
  }
  return root;
}

//Driver Code
int main()
{
  BstNode* root = NULL;
  root = insert(root,12);
  root = insert(root,5);
  root = insert(root,15);
  root = insert(root,4);
  root = insert(root,6);
  root = insert(root,13);
  root = insert(root,19);
  root = insert(root,11);
  root = insert(root,14);
  root = insert(root,17);
  root = insert(root,20);
  root = insert(root,16);
  root = insert(root,18);
  root = insert(root,25);

  cout<<"The BST is(Inorder Traversal) :\n";
  printInorder(root);
  cout<<endl;

  cout<<"Deleting 15 from BST\n";
  root = deleteNode(root, 15);

  cout<<"The BST is(Inorder Traversal) after deleting:\n";
  printInorder(root);
  cout<<endl;

  //freeing up all the heap memory
  deleteBst(root);

}