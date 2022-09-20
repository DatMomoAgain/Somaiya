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
    cout<<"1-begining 2-end 3-middle: ";
    int q;
    cin>>q;
    Node* n=NULL;
    n = new Node();
    n->data = x;
    Node* temp = NULL;
    Node* temp2 = NULL;
    temp = head;
    temp2 = head;
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
        temp->next = n;              
        break;
    
     case 3:
        cout << "Enter 1st node: ";
        int n1;
        cin >> n1;
        cout << "Enter 2nd node: ";
        int n2;
        cin >> n2;

        for(int i=0; i<n1-1; i++)
        {
            temp = temp->next;
        }
        for(int i=0; i<n2-1; i++)
        {
            temp2 = temp2->next;
        }
        n->next = temp2;
        temp->next = n;
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
    head =insert(4,head);
    head =insert(5,head);
    traverse(head);

    return 0;
}
