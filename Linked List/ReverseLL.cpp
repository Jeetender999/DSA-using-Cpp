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

Node* reverseListNaive(Node* head)
{
    Node* headtemp = NULL;
    Node* curr = head;

    while(curr != NULL)
     {
        headtemp = insertAtBeg(headtemp, curr->data);
        curr = curr->next;
     }
     

     return headtemp;
}

Node* reverseList(Node* head)
{
  vector<int> temp;

   for(Node* curr = head; curr!= NULL; curr = curr->next)
   {
     temp.push_back(curr->data);
   }

   for(Node* curr = head; curr != NULL; curr= curr->next)
   {
     curr->data = temp.back();
     temp.pop_back();
   }
   return head;
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
   head = reverseListEfficient(head);
   printList(head);
    
    cout << endl;

  
    
}