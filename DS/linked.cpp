#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void traverse(Node* head)
{
    if(head == NULL)
    {
        cout<<"List is empty";
    }
    Node *n = head;
    while (n != NULL)
    {
        
        cout<< n->data << ' '; 
        n = n->next;
    }
    cout<<'\n';
}

Node* insert(int x, Node* head)
{

    cout<<"Enter index: ";
    int q1;
    cin>>q1;
    Node* n=NULL;
    n = new Node();
    n->data = x;
    Node* temp = head;
    if(q1 == 0)
    {
        n->next = head;
        head = n;
    }
    else
    {
        for(int i=0; i<q1; i++)
        {
            //temp points to prev node
            if(i!=0){
            temp = temp->next;}
            if(temp == NULL)
            {
                cout<<"Invalid index\n";
                return head;
            }            
        }
        n->next = temp->next;
        temp->next = n;
    }
    return head;
}

Node* eradicate(Node* head)
{
    if(head ==NULL)
    {
        cout<<"List is empty\n";
        return head;
    }
    cout<<"Enter index: ";
    int q;
    cin>>q;
    Node* temp = head;
    Node* temp2 = head;
    if(q==0)
    {
        head = head->next;
        delete(temp);
        return head;
    }
    for(int i=0; i<q;i++)
    {
        if(i!=0)
        {
            temp = temp->next;
        }
        if(temp->next==NULL)
        {
            cout<<"Invalid index\n";
        }
        temp2 = temp2->next;
    }
    temp->next= temp->next->next;
    delete(temp2);
    return head;
}



int main()
{
    Node* head = NULL;
    int q3 = -1;
    while(q3!=0)
    {
        cout<<"Enter 1-insert; 2-delete; 3-traverse; 0-exit: ";
        cin>>q3;
        switch(q3){
         case 0:
            break;
         case 1:
            cout<<"Enter no: ";
            int n1;
            cin>>n1;
            head = insert(n1, head);
            break;
         case 2:
            head = eradicate(head);
            break;
         case 3:
            traverse(head);            
        }
    }

    return 0;
}
