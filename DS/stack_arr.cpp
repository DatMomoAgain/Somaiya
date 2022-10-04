#include <iostream>

using namespace std;

int * push(int * arr, int* t)
{
    int n;
    cout<<"Enter no. you want to add: ";
    cin>>n;
    if(*(arr+4) != 0)
    {
        cout<<"Stack is full";
    }
    else if(*arr == 0)
    {
        t = arr;
        *t = n;
    }
    else
    {
        t = t+1;
        *t = n;
    }
    return t;
}

int * pop(int *arr, int* t)
{
    if(*arr == 0)
    {
        cout<<"Stack is empty";
    }
    else
    {
        *t = 0;
        t -= 1;
    }
    return t;
}

void traverse(int * arr, int* t)
{
    int* temp = arr;
    if(*arr == 0)
    {
        cout<<"Stack is empty";
    }
    else
    {
        while(temp!= t+1)
        {
            cout<<*temp;
            temp = temp + 1;
        }
        cout<<"\n";
    }
}

int main()
{
    int* stack= new int[5];
    for(int i=0; i<5; i++)
    {
        stack[i] = 0;
    }
    int* t=NULL;
    int q=-1;
    while (q!=0)
    {
        cout<<"1-insert  2-delete  3-traverse  0-exit: ";
        cin>>q;
        switch(q)
        {
         case 0:
            break;
         case 1:
            t = push(stack,t);
            break;
         case 2:
            t = pop(stack,t);
            break;
         case 3:
            traverse(stack,t);
            break;
            
            
        }
    }
}
