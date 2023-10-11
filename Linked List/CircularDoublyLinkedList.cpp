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

void printCDLL(Node *head)
{
    Node *curr = head;

    do
    {
        cout << curr->data << " ";
        curr = curr->next;

    } while (curr != head);
}

Node *insertAtHead(Node *head, int n)
{
    Node *temp = new Node(n);

    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    temp->prev = head->prev;
    temp->next = head;

    head->prev->next = temp;
    head->prev = temp;

    return temp;
}

int main()
{
    Node *head = new Node(5);
    Node *temp1 = new Node(10);
    Node *temp2 = new Node(15);

    head->next = temp1;
    head->prev = temp2;

    temp1->prev = head;
    temp1->next = temp2;

    temp2->prev = temp1;
    temp2->next = head;

    head = insertAtHead(head, 3);

    printCDLL(head);
}