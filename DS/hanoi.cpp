#include <iostream>
#include <math.h>

using namespace std;

int * push(int * arr, int* t, int n)
{
    if(*arr == 0)
    {
        *arr = n;
        *t =0;
    }
    else
    {
        *t += 1;
        *(arr+*t) = n;
    }
    return t;
}

int * pop(int *arr, int* t)
{
    if(*arr == 0)
    {
        //cout<<"Stack is empty"<<endl;
    }
    else
    {
        *(arr+*t) = 0;
        *t -= 1;
    }
    return t;
}

void traverse(int * arr, int* t)
{
    int* temp = arr;
    if(*arr == 0)
    {
        //cout<<"Stack is empty"<<endl;
    }
    else
    {
        for(int i=0; i<=*t; i++)
        {
            cout<<*temp<<' ';
            temp = temp + 1;
        }
        cout<<"\n";
    }
}

int top(int * arr, int* t)
{
    int ans=0;
    if(*arr == 0)
    {
        //cout<<"Stack is empty";
    }
    else
    {
        ans = *(arr+*t);
    }
    return ans;
}


void move(int* tow1, int* tow2, int* t1, int* t2)
{
    int tow1_top = top(tow1, t1);
    int tow2_top = top(tow2, t2);
    t2 = pop(tow2 ,t2);
    t1 = pop(tow1, t1);
    if(tow1_top==0)
    {
        push(tow1, t1, tow2_top);
    }
    else if(tow2_top==0)
    {
        push(tow2, t2, tow1_top);
    }
    else if(tow2_top<tow1_top)
    {
        push(tow1, t1, tow1_top);
        push(tow1, t1, tow2_top);
    }
    else if(tow2_top>tow1_top)
    {
        push(tow2, t2, tow2_top);
        push(tow2, t2, tow1_top);
    }
}

void solve(int n, int* tow1, int* tow2, int* tow3, int* t1, int* t2, int* t3)
{
    int totmov;
    totmov = pow(2, n) - 1;
    for(int i=1; i<= totmov; i++)
    {
        if(i%3==1)
        {
            //cout<<"enter 1";
            move(tow1, tow3, t1, t3);
            cout<<"tow1: ";
            traverse(tow1, t1);
            cout<<"tow2: ";
            traverse(tow2, t2);
            cout<<"tow3: ";
            traverse(tow3, t3);
            cout<<endl;
        }
        else if(i%3==2)
        {
            //cout<<"enter 2";
            move(tow1, tow2, t1, t2);
            cout<<"tow1: ";
            traverse(tow1, t1);
            cout<<"tow2: ";
            traverse(tow2, t2);
            cout<<"tow3: ";
            traverse(tow3, t3);
            cout<<endl;
        }
        else if(i%3==0)
        {
            //cout<<"enter 3";
            move(tow2, tow3, t2, t3);
            cout<<"tow1: ";
            traverse(tow1, t1);
            cout<<"tow2: ";
            traverse(tow2, t2);
            cout<<"tow3: ";
            traverse(tow3, t3);
            cout<<endl;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter no. of disks: ";
    cin>>n;
    int* tow1= new int[n];
    int* tow2= new int[n];
    int* tow3= new int[n];
    for(int i=0; i<n; i++)
    {
        tow1[i] = 0;
        tow2[i] = 0;
        tow3[i] = 0;
    }
    int* t1=new int();
    int* t2=new int();
    int* t3=new int();

    //pushing input in tow1
    for(int i=n; i>0; i--)
    {
        t1 = push(tow1,t1,i);
    }

    if(n%2==0)
        solve(n, tow1, tow3, tow2, t1, t3, t2);
    else
        solve(n, tow1, tow2, tow3, t1, t2, t3);
}
