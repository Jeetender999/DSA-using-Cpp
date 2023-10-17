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

bool detechAndRemoveLoop(Node* head)
{
 Node* slow = head;
 Node* fast = head;

 while(fast != NULL && fast->next != NULL)
 {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast)
    {
      
        break;
    }
 }

 if(slow != fast)
   {
    cout << "No loop found";
    return false;
   }

 slow = head;
 
 while(fast->next!=slow->next)
 {
    slow = slow->next;
    fast = fast->next;
 }
 fast->next = NULL;

 cout << "Loop removed" << endl;
 return true;
}

int main()
{
    Node *head = NULL;
   
    head = new Node(5);
    Node* temp1 = new Node(10);
    Node* temp2 = new Node(15);
    Node* temp3 = new Node(20);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    temp3->next = temp1;

    detechAndRemoveLoop(head);
    printList(head);
    
    
   
    
}