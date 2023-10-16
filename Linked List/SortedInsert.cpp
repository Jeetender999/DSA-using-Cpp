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

Node *sortedInsert(Node *head, int n)
{
    Node *temp = new Node(n);
    Node *curr = head;

    if (head == NULL)
    {
        return temp;
    }

    if (n < head->data)
    {
        temp->next = head;
        return temp;
    }

    while (curr->next != NULL && curr->next->data <= n)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;

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

int main()
{
    Node *head = NULL;
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 15);
    head = sortedInsert(head, 8);

    printList(head);
}