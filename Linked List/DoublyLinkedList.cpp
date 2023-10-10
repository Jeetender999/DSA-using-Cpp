#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int n)
    {
        data = n;
        prev = NULL;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *insertAtBeg(Node *head, int n)
{
    Node *temp = new Node(n);

    temp->next = head;

    if (head != NULL)
        head->prev = temp;

    return temp;
}

Node *insertAtEnd(Node *head, int n)
{
    Node *temp = new Node(n);
    Node *curr = head;

    if (head == NULL)
        return temp;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;

    return head;
}

Node* deleteFromBeg(Node* head)
{
    if(head == NULL ) 
    return NULL;

    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node* curr = head;
    head = head->next;
    head->prev = NULL;

    delete curr;

    return head;
    }

    

}

Node* deleteFromEnd(Node* head)
{
    Node* curr = head;

     if(head == NULL)
     return NULL;

     if(head->next == NULL)
     {
        delete head;
        return NULL;
     }

    while(curr->next != NULL)
    {
        curr  = curr->next;
    }

    Node* temp = curr;
    curr->prev->next = NULL;
    delete temp;

    return head;
}

Node* reverseDDL(Node* head)
{

    if(head == NULL || head->next == NULL )
    return head;

    Node* curr = head;
    Node* temp = NULL;

    while(curr!= NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next =temp;;

        curr = curr->prev;
       

    }

   return temp->prev;
}

int main()
{
    Node *head = NULL;
    head = insertAtBeg(head,5);
    head = insertAtBeg(head,10);
    head = insertAtEnd(head, 69);
     head = insertAtEnd(head, 20);
     printList(head);
     cout << endl;
     head = deleteFromBeg(head);
     head = deleteFromEnd(head);
      printList(head);
      cout << endl;


     head = reverseDDL(head);

    printList(head);
}
