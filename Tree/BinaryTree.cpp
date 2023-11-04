#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int n)
    {
        data = n;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(Node* root)
{
    Node* temp = root;

    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->rightChild;
    }
}

int main()
{

       //      3
       //    6     9
       // 12
     
    Node *root = NULL;

    Node *temp1 = new Node(3);
    Node *temp2 = new Node(6);
    Node *temp3 = new Node(9);
    Node *temp4 = new Node(12); 

    root = temp1;
    temp1->leftChild = temp2;
    temp1->rightChild = temp3;

    temp2->leftChild = temp4;

    printTree(root);


}