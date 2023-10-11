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

void middleElement(Node* head)
{
    if(head == NULL) return;
    int count = 0;
    Node* curr;
    for(curr=head;curr!=NULL;curr = curr->next)
      count++;

     cout << "count " << count << endl; 
    
    curr = head;
    for(int i=0;i<count/2;i++)
    {
        curr = curr->next;
    }
 
 cout << "Middle " << curr->data << endl;
   
}

void middleElementEfficient(Node* head)
{
    if(head == NULL) return;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Element " << slow->data << endl;
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

   middleElementEfficient(head);
    
}