#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

Node *insertAtEnd(Node *head, int n)
{
    Node *temp = new Node(n);
    Node *curr = head;

    if (head == NULL)
        return temp;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void nthNodeFromEnd(Node* head, int n)
{
    Node* curr;
    int count = 0;

    for(curr=head; curr!=NULL; curr=curr->next)
     count++;

    if(count < n) return; 

    int k = count-n+1;

    curr = head;
    for(int i=1; i<k;i++)
      curr = curr->next; 

    cout << "From End " << curr->data << endl; 


}

void nthNodeFromEndEfficient(Node* head, int n)
{


    if(head == NULL) return;
    Node* first = head;
    Node* second = head;
   
   


    for(int i=1; i<=n;i++)
      {
        if(first == NULL) return;
        first = first->next;
      }

   
   

   while(first != NULL)
     {
        second = second->next;
        first = first->next;
     }

   cout << "From last " << second->data << endl;   
}

int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 8);
     head = insertAtEnd(head, 32);
     

    printList(head);
    nthNodeFromEndEfficient(head,5);
    cout << endl;

  
    
}