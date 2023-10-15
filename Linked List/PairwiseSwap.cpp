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

Node* pairWiseSwap(Node* head)
{
    Node* curr = head;

    while(curr != NULL && curr->next != NULL )
    {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;

          
       curr = curr->next->next;
    }

    return head;
}

Node* pairwiseSwap2(Node* head)
{
    if(head == NULL || head->next == NULL) return NULL;

    Node* curr = head->next->next;
    Node* prev = head;
    head = head->next;
    head->next  = prev;

    while(curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node* next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }

    prev->next = curr;
    return head;
}
int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 17);
    head = insertAtEnd(head, 15);

    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 12);
    head = insertAtEnd(head, 10);

    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 4);

   
    printList(head);
    cout << endl;

    head = pairwiseSwap2(head);
    printList(head);

    
}