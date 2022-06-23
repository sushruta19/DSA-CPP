/* This file is the implementation of singly linked list and some of its basic 
 * operations --> insertion, deletion, search, print
 * You must include this header file in other singly linked list files.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

//Singly linked list Node
class Node {
  public:
  int data;
  Node* next;
  Node(int x=0):data{x},next{NULL}{}
};

/*******************************Insertion********************************/

//Push(Inserting Node at Head)
//T:O(1) S:O(1)
void push(Node** head_ref, int data)
{
  Node* new_node = new Node(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

//Append(Inserting Node at Rear)
//Iterative
//T:O(n) S:O(1)
void append(Node** head_ref, int data)
{
  Node* new_node = new Node(data);
  if(*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }
  Node* current = *head_ref;
  while(current->next!=NULL)
    current=current->next;
  current->next = new_node;
}

//Append(Inserting Node at Rear)
//Recursive
Node* append2(Node* head, int data)
{
  if(head == NULL)
    return new Node(data);
  else
  {
    head = append2(head->next, data);
    return head;
  }
}

//InsertAtIndex(Inserting Node at a valid Index(starts from 0))
void insertAtIndex(Node** head_ref, int index, int data)
{
  if(index<0)
    throw out_of_range("Index out of bound");
  Node* new_node = new Node(data);
  if(index == 0)
  {
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
  }
  Node* current = *head_ref;
  int count=0;
  while(current!=NULL)
  {
    if(count == index-1)            //we need to be one step earlier so that we don't lose the address
    {
      new_node->next=current->next;
      current->next=new_node;
      break;
    }
    current=current->next;
    count++;
  }
  if(count!=index-1)
    throw out_of_range("Index out of bound");
}

/********************************Deletion********************************/

//deleteNodeByData (Deleting the first Node having the given data)
void deleteNodeByData(Node** head_ref, int key)
{
  if(*head_ref == NULL)
    throw underflow_error("Singly linked list is empty!");

  if((*head_ref)->data == key)
  {
    Node* temp=*head_ref;
    (*head_ref) = (*head_ref)->next;
    delete temp;
  }
  Node* current = *head_ref;
  while(current->next!=NULL)
  {
    if(current->next->data == key)
    {
      Node* temp=current->next;
      current->next = current->next->next;
      delete temp;
      break;
    }
    current=current->next;
  }
  if(current->next == NULL)
    cout<<"Key not present!\n";
}

//delete entire singly linked list
//Iterative method
void deleteLinkedList(Node** head_ref)
{
  if(*head_ref == NULL)
  {
    cout<<"Singly linked list is empty!";
    return;
  }
  Node* current=*head_ref;
  while(current!=NULL)
  {
    Node* temp=current;
    current=current->next;
    delete temp;
  }
  *head_ref = NULL; //pointing the head to NULL after deletion of entire list
}

//delete entire singly linked list
//Recursive method
void deleteLinkedList2(Node* head)
{
  if(head==NULL)
    return;
  else
  {
    deleteLinkedList2(head->next);
    delete head;
  }
}
//The above function will make the original head pointer of linked list a
//dangling pointer. So make sure to set head to NULL in the main() function.


/***************************Searching**************************/

//Search given key
//Iterative
bool searchIterative(Node* head, int key)
{
  Node* current = head;
  while(current!=NULL)
  {
    if(current->data == key)
      return true;
  }
  return false;
}

//Search given key
//Recursive
bool search(Node* head, int key)
{
  if(head==NULL)
    return false;
  else if(head->data == key)
    return true;
  else
    return search(head->next,key);
}

/***************************Printing***************************/

//Printing singly linked list
//Iterative
void printLinkedList(Node* head)
{
  cout<<"HEAD->";
  Node* current=head;
  while(current!=NULL)
  {
    cout<<current->data<<"->";
    current=current->next;
  }
  cout<<"NULL\n";
}

//Printing singly linked list
//Recursive
void printLinkedList2(Node* head)
{
  if(head==NULL)
    return;
  cout<<head->data<<" ";
  printLinkedList2(head->next);
}