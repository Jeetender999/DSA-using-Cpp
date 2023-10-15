#include <iostream>
#include <vector>

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


Node *insertAtBeg(Node *head, int n)
{

    Node *newNode = new Node(n);

    newNode->next = head;

    head = newNode;
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


Node* reverseListEfficient(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
   

    while(curr != NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
       
    }

    return prev;
}
Node* recursiveReverse(Node* curr, Node* prev = NULL)
{
   
 
   if(curr == NULL)
   return prev;

   
   Node* next = curr->next;
   curr->next = prev;

   prev = curr;
   curr = next;
   recursiveReverse(curr,prev);
}

Node* recursiveReverse1(Node* head)
{
    
    
    if(head == NULL || head->next == NULL)
     return head;

    Node* rest_head = recursiveReverse1(head->next);
    Node* rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;

    return rest_head;
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
    cout << endl;

     head = recursiveReverse(head);
     
   printList(head);
   
    
    cout << endl;

  
    
}