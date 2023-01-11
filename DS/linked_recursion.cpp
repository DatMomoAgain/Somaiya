#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
 public:
    int val;
    Node* next;
};

void traverse(Node* head)
{
    if(head==NULL)
    {
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    traverse(head->next);
}

Node* insert(Node* head, int val, int index)
{
    if((head==NULL && index!=0)||index<0)
    {
        cout<<"Index doesn't exist"<<endl;
        return head;
    }
    else if(head==NULL)
    {
        head = new Node();
        head->val = val;
        return head;
    }
    if(index==0)
    {
        Node* n = new Node();
        n->val = val;
        n->next = head;
        head = n;
        return head;
    }
    if(index==1)
    {
        Node* n = new Node();
        n->val = val;
        n->next = head->next;
        head->next = n;
        return head;
    }
    index--;
    insert(head->next, val, index);
}

Node* del(Node* head, int index)
{
    if(head==NULL)
    {
        cout<<"Index doesn't exist";
        return head;
    }
    if(index==0)
    {
        head = head->next;
        return head;
    }
    else if(index==1)
    {
        head->next = head->next->next;
        return head;
    }
    index--;
    del(head->next, index);    
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
            int ind;
            cout<<"Enter index: ";
            cin>>ind;
            head = insert(head,n1,ind);
            break;
         case 2:
            int inde;
            cout<<"Enter index: ";
            cin>>inde;
            head = del(head,inde);
            break;
         case 3:
            traverse(head);
            break;
         default:
            cout<<"Invalid input!"<<endl;
            break;         
        }
    }
}
