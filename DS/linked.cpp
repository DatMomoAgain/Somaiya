#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* next;
};

void traverse(Node* n)
{
    while (n != NULL)
    {
       cout<< n->data << ' '; 
       n = n->next;
    }
}

Node* insert(int x, Node* head)
{
    cout<<"1-begining 2-end: ";
    int q;
    cin>>q;
    Node* n=NULL;
    n = new Node();
    n->data = x;
    Node* temp = NULL;
    temp = head;
    switch(q)
    {
     case 1:
        n->next = head;
        head = n;
        break;
     case 2:
        n->next = NULL;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        break;
     default:
        break;
    }
    return head;
}


int main()
{
    Node* head = NULL;
    Node* first = NULL;
    first = new Node();
    first->data = 1;
    first->next = NULL;
    head = first;
    Node* sec = NULL;
    sec = new Node();
    sec->data=2;
    sec->next = NULL;
    first->next = sec;
    head = insert(3,head);
    traverse(head);

    return 0;
}
