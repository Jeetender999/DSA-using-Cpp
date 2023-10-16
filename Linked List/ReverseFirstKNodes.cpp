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

Node* reverseFirstKNode(Node* head, int k)
{
    Node* curr = head;
    Node* next;
    Node* prev = NULL;

    for(int i=0; i<k && curr->next != NULL;i++)
      {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
      }
   
   head->next = curr;
   return prev;
     
}



int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 10);
   
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 32);
    head = insertAtEnd(head, 40);
   
    head = insertAtEnd(head, 15);

    printList(head);
    cout << endl;

    head = reverseFirstKNode(head,11);
    printList(head);
    
}