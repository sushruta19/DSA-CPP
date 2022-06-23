#include <unordered_set>
#include "sll-0.cpp"
//The above source file "sll-0.cpp" contains the necessary header files and
//implementation of singly linked list and 
//its basic operations(push, append, delete, print, search)

/*********************Loops in Singly Linked List*********************/

//Detect Loops
//Hashing Approach
bool detectLoop(Node* head)
{
  unordered_set<Node*> s; //store the node addresses
  while(head!=NULL)
  {
    //if node address is present in the set then there is a loop
    if(s.find(head) != s.end())  
    {
      return true;
    }

    //if seeing the node for first time, insert it in hash
    s.insert(head);
    head = head->next;
  }
  return false;
}

//Detect Loops
//Using Floyd's Cycle Finding Algorithm
bool detectLoopFloyd(Node* head)
{
  Node* slow = head, *fast=head;
  while(slow!=NULL && fast!=NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
      return true;
  }
  return false;
}

//Detect and remove loops(Easy Method)
void detectAndRemoveLoopByHashing(Node* head)
{
  unordered_set<Node*> s;
  if(head == NULL)
    throw invalid_argument("Loop is empty!");

  while(head->next!=NULL)
  {
    if(s.find(head->next)!=s.end()) //loop found
    {
      head->next = NULL;
      break;
    }

    s.insert(head);
    head=head->next;
  }
}

//Detect and remove loops
//Floyd Cycle Finding Algorithm
void detectAndRemoveLoop(Node* head)
{
  Node* slow = head, *fast = head;
  while(slow!=NULL && fast!=NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    //loop found
    if(slow == fast)
      break;
  }
  if(slow == fast)
  {
    slow = head;

    //if looping point is at head
    if(slow == fast)
    {
      while(fast->next!=slow)
      {
        fast = fast->next;
      }
    }
    else
    {
      while(slow->next != fast->next)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
    fast->next = NULL;    //remove looping point
  }
  else
  {
    cout<<"No loop detected!\n";
  }
}

//Driver Program
int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printLinkedList(head);

    deleteLinkedList2(head);
    return 0;
}