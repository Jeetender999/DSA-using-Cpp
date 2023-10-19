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

Node *mergeSortedList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *newHead = NULL, *newTail = NULL;
    if (head1->data <= head2->data)
    {
        newHead = head1;
        newTail = newHead;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        newTail = newHead;
        head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            newTail->next = head1;
            newTail = head1;
            head1 = head1->next;
        }
        else
        {
            newTail->next = head2;
            newTail = head2;
            head2 = head2->next;
        }
    }

   if(head1 == NULL)
    newTail->next = head2;
   else
    newTail->next = head1;
    

    return newHead;
}

int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 10);

    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 22);
    head = insertAtEnd(head, 30);

    Node *head2 = NULL;

 
    head2 = insertAtEnd(head2, 50);

    printList(head);
    cout << endl;
    printList(head2);
    cout << endl;

    Node *newHead = mergeSortedList(head, head2);
    printList(newHead);
}