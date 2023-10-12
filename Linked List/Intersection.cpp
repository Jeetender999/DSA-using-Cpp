#include <iostream>
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


Node* getIntersection(Node* head1, Node* head2)
{
    Node* intersection = NULL;

    Node* curr2 = head2;
    
    while(curr2 != NULL)
    {
        
        for(Node* curr = head1; curr!=NULL; curr = curr->next)
        {
            if(curr2 == curr)
             {
                cout << "Intersection found " << curr2->data << endl;
                intersection = curr2;
                return curr2;
             }
        }

        curr2 = curr2->next;
    }

    cout << "No intersection" << endl;
    return head1;
}

Node* findIntersection(Node* head1, Node* head2)
{
    unordered_set<Node*> s;

    Node* curr1 = head1;

    while(curr1 != NULL)
      {
        s.insert(curr1);
        curr1 = curr1->next;
      }

    Node* curr2 = head2;

    while(curr2 != NULL)
    {
        if(s.find(curr2) != s.end())
        {
            cout << "Intersection Pt " << curr2->data << endl;
            return curr2;
        }

        curr2 = curr2->next;
    }

    cout << "No inter Point" << endl;
    return NULL;
}

Node* findIntersection2(Node* head1, Node* head2)
{
    Node* curr1 = head1;
    Node* curr2 = head2;

    int count1 =0;
    int count2 = 0;


    while(curr1 != NULL)
    {
        count1++;
        curr1 = curr1->next;
    }

      while(curr2 != NULL)
    {
        count2++;
        curr2 = curr2->next;
    }


    curr1 = head1;
    curr2 = head2;

   if(count1 > count2)
   {
    int diff = count1-count2;
   
     for(int i=1; i<= diff;i++)
       curr1 = curr1->next;
   }
   else
   {
     int diff = count2-count1;
     for(int i=1; i<= diff;i++)
       curr2 = curr2->next;
   }

   

   while(curr1 != NULL && curr2 != NULL)
   {
     if(curr1 == curr2) 
      {
        cout << "Intersection found " << curr1->data << endl;
        return curr1;
      }

      curr1 = curr1->next;
      curr2 = curr2->next;
   }

   cout << "No intersection" << endl;
   return NULL;
}

int main()
{
    Node *head = NULL;
   
    head = new Node(5);
    Node* temp1 = new Node(10);
    Node* temp2 = new Node(15);
    Node* temp3 = new Node(20);
    Node* temp4 = new Node(25);
    Node* temp5 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;

    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = NULL;


    Node* head2 = new Node(3);
    Node* dummy1  = new Node(6);

    head2->next = dummy1;
    dummy1->next = temp3;

    printList(head);
    cout << endl;

    printList(head2);
    cout << endl;
  
   Node* pt = findIntersection2(head,head2);
   printList(pt);
   
}