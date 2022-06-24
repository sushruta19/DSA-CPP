#include "00-implementation.cpp"
//The above source file "00-implementation.cpp" contains the necessary header files and
//implementation of doubly linked list and 
//its basic operations(push, append, delete, print)


//Driver Program for Doubly Linked List basic functions
int main()
{
  DLLNode* head = NULL;
  append(&head,5);  //head-> 5->NULL
  append(&head,7);  //head-> 5<->7->NULL
  push(&head, 8);   //head-> 8<->5<->7->NULL
  push(&head,10);   //head-> 10<->8<->5<->7->NULL
  append(&head,6);  //head-> 10<->8<->5<->7<->6->NULL
  insertAfter(head->next,50); //head-> 10<->8<->50<->5<->7<->6->NULL
  insertBefore(head->next,50); //head-> 10<->50<->8<->50<->5<->7<->6->NULL

  cout<<"The DLL is\n";
  printDLL2(head);

  cout<<"\nThe DLL in Forward and Reverse:\n";
  printDLL(head);

  cout<<"Delete 50\n";
  deleteNodeByData(&head, 50);
  printDLL(head);
  cout<<"Delete 10\n";
  deleteNodeByData(&head,10);
  printDLL(head);

  /*Dellocate heap memory*/
  deleteDLL(head);
  return 0;
}