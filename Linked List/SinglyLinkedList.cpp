#include <iostream>
using namespace std;

class Node
{
public:
    int n;
    Node *next;

    Node(int value)
    {
        n = value;
        next = NULL;
    }
};

void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->n << " ";
        head = head->next;
    }
}

void recursivePrint(Node *head)
{
    if (head == NULL)
        return;

    cout << head->n << " ";
    recursivePrint(head->next);
}

Node *insertAtBeg(Node *head, int n)
{

    Node *newNode = new Node(n);

    newNode->next = head;

    head = newNode;
    return head;
}

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

Node *insertAtPos(Node *head, int n, int pos)
{
   

    Node *temp = new Node(n);
    if(pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;

   
     for(int i=1;i<= pos-2 && curr!=NULL;i++)
       curr = curr->next;

     if(curr == NULL)
      return head;  

   
     temp->next = curr->next;
    curr->next = temp;
   

    return head;
}

Node *deleteFromBeg(Node *head)
{

    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *deleteFromEnd(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;

    delete curr->next;
    curr->next = NULL;
    return head;
}


int search(Node* head, int n)
{
    Node* curr = head;

    for(int i=1; curr!=NULL;i++)
    {
        if(curr->n == n)
          return i;
        
        curr = curr->next;
    }

    return -1;
}

int searchRecursive(Node* head, int n)
{
    if(head == NULL)
      return -1;

    if(head->n == n)
     return 1;
    else
    {
        int res = searchRecursive(head->next,n);  
        if(res == -1) return -1;
        else return (res+1);
    }

    
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    head->next->next = temp2;
    temp2->next = nullptr;

    head = insertAtBeg(head, 40);
    head = insertAtBeg(head, 50);

    head = insertAtEnd(head, 99);
    head = insertAtEnd(head, 999);
    head = insertAtPos(head, 69, 4);
    printNode(head);
    cout << endl;

    cout << search(head,69) << endl;
     cout << searchRecursive(head,99) << endl;

    // head = deleteFromBeg(head);
    // head = deleteFromEnd(head);
    // printNode(head);
}