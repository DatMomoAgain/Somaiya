#include <iostream>

using namespace std;

void enqueue(int* arr, int* rear, int* front, int n)
{
    if(*front ==-1)
    {
        (*front)++;
    }
    (*rear)++;
    *(arr+*rear) = n;
}

void dequeue(int* arr, int* rear, int* front)
{
    if(*front>*rear || *front==-1)
    {
        cout<<"Queue is empty\n";
        return;
    }
    (*front)++;
}

void traverse(int* arr, int* rear, int* front)
{
    if(*front>*rear || *front==-1)
    {
        cout<<"Queue is empty\n";
        return;
    }
    for(int i= *front; i<*rear+1; i++)
    {
        cout<<*(arr+i)<<endl;
    }
}

int main()
{
    int* arr = new int[200];
    int rear1 = -1;
    int* rear= &rear1;
    int front1 = -1;
    int* front = &front1;
    int n;
    int q = -1;
    while(q!=0)
    {
        cout<<"Enter 1-enqueue 2-dequeue 3-traverse 0-quit: ";
        cin>>q;
        switch(q)
        {
         case 0:
            break;
         case 1:
            cout<<"Enter no.: ";
            cin>>n;
            enqueue(arr, rear, front, n);
            break;
         case 2:
            dequeue(arr, rear, front);
            break;
         case 3:
            traverse(arr, rear, front);
            break;
         default:
            cout<<"Try again\n";
            break;
        }
    }
    
    return 0;
}
