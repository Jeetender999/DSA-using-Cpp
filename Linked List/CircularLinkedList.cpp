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

void printCLL(Node *head)
{
    Node *curr = head;
    if (head == NULL)
        return;

    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);

    // if(head->next == head )
    // {
    //     cout << head->data << " ";
    // }

    // Node* curr = head;

    // while(curr->next != head)
    // {
    //     cout << curr->data << " ";
    //     curr = curr->next;
    // }

    // cout << curr->data << " ";

    // return head;
}

Node *insertAtBegNaive(Node *head, int n)
{
    Node *temp = new Node(n);
    Node *curr = head;

    if (head == NULL)
    {
        temp->next = temp;
    }
    else
    {
        while (curr->next != head)
        {
            curr = curr->next;
        }

        curr->next = temp;
        temp->next = head;
    }

    return temp;
}

Node *insertAtBeg(Node *head, int n)
{
    Node *temp = new Node(n);

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    temp->next = head->next;
    head->next = temp;

    int t = head->data;
    head->data = temp->data;
    temp->data = t;

    return head;
}

Node *insertAtEndNaive(Node *head, int n)
{
    Node *temp = new Node(n);
    Node *curr = head;

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

   
    while (curr->next != head)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->next = head;

    return head;
}

Node* insertAtEnd(Node* head,int n)
{
    Node* temp  = new Node(n);
    Node* curr = head;

    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;

        int t = temp->data;
        temp->data = head->data;
        head->data = t;

        return temp;
    }
}

Node* deleteHeadNaive(Node* head)
{

    if(head == NULL) return NULL;

    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    
    Node* curr = head;

    while(curr->next != head)
     curr = curr->next;

    curr->next = head->next;
    delete head;
    return (curr->next);
}

Node* deleteHead(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        int t = head->data;
        head->data = head->next->data;
        head->next->data = t;

        Node* temp = head->next;
        head->next = head->next->next;

        delete temp;

        return head;

        
    }

}

Node* deleteKthNode(Node* head, int k)
{
    if(head == NULL)
     return NULL;

    if(k==1)
     return deleteHead(head); 

   
    Node* curr = head;

    for(int i=0; i<k-2 ; i++)
      curr = curr->next;

   Node* temp = curr->next;
   curr->next = curr->next->next;
   delete temp;

   return head;

}

int main()
{
    Node *head = new Node(5);
    Node *temp1 = new Node(10);
    Node *temp2 = new Node(15);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = head;

    head = insertAtBeg(head, 20);
    head = insertAtEnd(head,40);

     head = deleteKthNode(head,22);

    printCLL(head);
}