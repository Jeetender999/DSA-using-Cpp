#include <iostream>

using namespace std;

struct Node
{
    char data;
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

bool isPalindrome(Node* head)
{
    Node* curr = head;
    Node* newCurr = NULL;

    while(curr!= NULL)
    {
      newCurr = insertAtBeg(newCurr, curr->data);
      curr = curr->next;
    }

    curr = head;

    while(curr != NULL)
    {
        if(curr->data != newCurr->data)
        {
            cout << "Not a palindrome" << endl;
            return false;
        }

        curr = curr->next;
        newCurr = newCurr->next;
    }

    cout << "Palindrome" << endl;
    return true;


}

bool isPalindromeEfficient(Node* head)
{
    if(head == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* rev = reverseListEfficient(slow->next);

    Node* curr = head;

    while(rev != NULL)
    {
        if(curr->data != rev->data)
         {
            cout << "Not a palindrome" << endl;
            return false;
         }

         rev = rev->next;
         curr = curr->next;
    }

     

    cout << "Palindrome" << endl;
    return true;
}

int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 'm');
    head = insertAtEnd(head, 'a');

    head = insertAtEnd(head, 'd');
    head = insertAtEnd(head, 'a');
    head = insertAtEnd(head, 'm');
     

    
    printList(head);
    cout << endl;
    isPalindromeEfficient(head);

  
    
}