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

Node *reverseInGroup(Node *head, int k)
{
    Node *curr = head;
    

    Node *prevFirst = NULL;
    bool isFirstPass = true;

    while (curr != NULL)
    {
        Node *first = curr;
        Node *prev = NULL;
        for (int i = 0; i < k && curr != NULL; i++)
        { 
            
           Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }

        prevFirst = first;
    }
    return head;
}

Node *reverseKRecursive(Node *head, int k)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

        count++;
    }

    if (next != NULL)
    {
        Node *rest_head = reverseKRecursive(next, k);
        head->next = rest_head;
    }

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

   

    head = reverseInGroup(head,3);
    printList(head);
}