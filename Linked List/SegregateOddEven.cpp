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

Node *segregateOddEven(Node *head) // My Approach
{
    Node *Es = NULL;
    Node *Ee = NULL;
    Node *Os = NULL;
    Node *Oe = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {

            Es = insertAtEnd(Es, curr->data);
        }
        else
        {

            Os = insertAtEnd(Os, curr->data);
        }

        curr = curr->next;
    }

    Node *currEs = Es;
    Node *currOs = Os;
    while (currEs != NULL)
    {
        cout << currEs->data << " ";
        Ee = currEs;
        currEs = currEs->next;
    }

    cout << endl;

    while (currOs != NULL)
    {
        cout << currOs->data << " ";
        currOs = currOs->next;
    }

    Ee->next = Os;

    return Es;
}

Node *segregate(Node *head)
{
    Node *Es = NULL;
    Node *Ee = NULL;
    Node *Os = NULL;
    Node *Oe = NULL;

    Node *curr = head;

    while (curr != NULL)
    {

        int x = curr->data;
        if (x % 2 == 0)
        {
            if (Es == NULL)
            {
                Es = curr;
                Ee = Es;
            }

            else
            {
                Ee->next = curr;
                Ee = Ee->next;
            }

            cout << "Even" << curr->data << endl;
        }
        else
        {

            if (Os == NULL)
            {
                Os = curr;
                Oe = Os;
            }
            else
            {
                Oe->next = curr;
                Oe = Oe->next;
            }

            cout << "Odd " << curr->data << endl;
        }

        curr = curr->next;
    }

    if (Os == NULL || Es == NULL)
        return head;

    Ee->next = Os;
    Oe->next = NULL;

    return Es;
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

    head = segregate(head);

    cout << endl;
    printList(head);
}