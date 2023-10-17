#include <iostream>
#include <vector>
#include <unordered_set>

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

bool isLoop(Node* head)
{
    Node* temp = new Node(0);
    Node* curr = head;

    while(curr != NULL)
    {

        if(curr->next == NULL) 
        {
          cout << "No Looop" << endl;
          return false;
        }
        if(curr->next == temp)
         {
            cout << "LLoop exist" << endl;
            return true;
         }
      
       Node* curr_next = curr->next;
       curr->next = temp;
       curr = curr_next;
         
    }

  return false;
  
}

bool isLoopHash(Node* head)
{
   
    unordered_set<Node*> s;

    for(Node* curr=head; curr != NULL; curr = curr->next)
    {
        if(s.find(curr) != s.end())
        {
            cout << "Loop exist";
            return true;
        }

        s.insert(curr);
    }

    cout << "No loop" << endl;
    return 0;
    
}

int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 5);
    Node* firstHead = head;
    head = insertAtEnd(head, 10);

    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 32);
    head = insertAtEnd(head, 40);

    head = insertAtEnd(head, 15);



    printList(head);
    cout << endl;

   
    isLoop(head);
    isLoopHash(head);

   

    
}