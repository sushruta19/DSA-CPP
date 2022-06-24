/* This file is the implementation of singly linked list and some of its basic 
 * operations --> insertion, deletion, search, print
 * You must include this header file in other singly linked list files.
*/

#include<iostream>
using namespace std;

//defining the doubly linked list node(DLLNode)
class DLLNode
{
  public:
  int data;
  DLLNode* prev, *next;
};
/*Didn't use constructor as I did in SLL(simply-linked-list) to avoid confusion of where the two pointers are pointing to*/
/*In case of DLL, set the pointers manually to get better understanding*/


//Insert DLLNode at front/head
void push(DLLNode**head_ref, int data)
{
  DLLNode* new_node = new DLLNode;
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = *head_ref;
  if(*head_ref != NULL)
    (*head_ref)->prev = new_node;
  *head_ref = new_node;
}

//Insert DLLNode at rear
void append(DLLNode** head_ref, int data)
{
  DLLNode* new_node = new DLLNode;
  new_node->data = data;
  new_node->next = NULL;
  if(*head_ref == NULL)
  {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }
  DLLNode* current = *head_ref;
  while(current->next!=NULL)
    current = current->next;
  current->next = new_node;
  new_node->prev = current; 
}

//Insert DLLNode after a given DLLNode
void insertAfter(DLLNode* prev_node, int data)
{
  DLLNode* new_node = new DLLNode;
  new_node->data = data;
  new_node->prev = prev_node;
  new_node->next = prev_node->next;
  
  prev_node->next = new_node;
  if(new_node->next!=NULL)
    (new_node->next)->prev = new_node;
}

//Insert DLLNode before a given DLLNode(not the head)
void insertBefore(DLLNode* next_node, int data)
{
  DLLNode* new_node = new DLLNode;
  new_node->data = data;
  new_node->next = next_node;
  new_node->prev = next_node->prev;
  next_node->prev = new_node;
  if(new_node->prev!=NULL)
    (new_node->prev)->next = new_node;
}

//Print DLL(forward and backward)
void printDLL(DLLNode* head)
{
  DLLNode* current = head, *temp = head;
  cout<<"Forward Traversal: ";
  while(current!=NULL)                    //Printing forward
  {
    cout<<current->data<<" ";
    temp = current;
    current=current->next;
  }
  cout<<endl;

  cout<<"Backward Traversal: ";
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->prev;
  }
  cout<<endl;
}

//Print DLL
void printDLL2(DLLNode* head)
{
  cout<<"HEAD->";
  DLLNode* current = head;
  if(head!=NULL)
  {
    while(current->next!=NULL)
    {
      cout<<current->data<<"<->";
      current = current->next;
    }
    cout<<current->data<<"->";
  }
  cout<<"NULL\n";
}

//Deleting the first DLLNode having the given data
void deleteNodeByData(DLLNode** head_ref, int key)
{
  if(*head_ref == NULL)
    throw underflow_error("DLL is Empty!");
  if((*head_ref)->data == key)
  {
    *head_ref = (*head_ref)->next;
    delete (*head_ref)->prev;
    (*head_ref)->prev = NULL;
    return;
  }
  DLLNode* current = *head_ref;
  while(current!=NULL)
  {
    if(current->data == key)
    {
      (current->prev)->next = current->next;
      if(current->next!=NULL) (current->next)->prev = current->prev;
      delete current;
      break;
    }
    current = current->next;
  }
}

//Delete entire DLL
void deleteDLL(DLLNode* head)
{
  if(head == NULL)
    throw underflow_error("DLL is empty");
  DLLNode* current = head;
  while(current!=NULL)
  {
    DLLNode* temp = current;
    current = current->next;
    delete temp;
  }
}

//Go to file ("00-driver.cpp") for the driver program of the above functions

