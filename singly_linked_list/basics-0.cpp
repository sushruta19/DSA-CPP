#include<iostream>
#include<stdexcept>
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

void push(Node** head_ref, int data)
{
  Node* new_node = new Node(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

//Append(Inserting Node at Rear)

void append(Node** head_ref, int data)
{
  Node* new_node = new Node(data);
  if(*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }
  Node* current = *head_ref;
  while(current!=NULL)
    current=current->next;
  current->next = new_node;
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

//Recursive method
void deleteLinkedList(Node* head)
{
  if(head==NULL)
    return;
  deleteLinkedList(head->next);
  delete head;
}
//The above function will make the original head pointer of linked list a
//dangling pointer. So make sure to set head to NULL in the main() function.



