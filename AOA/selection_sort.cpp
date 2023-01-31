#include <iostream>

using namespace std;

void selection(int* arr, int n, int* it)
{
    int smol = 50000;
    int ind =0;
    for(int i=0; i<n; i++)
    {
        *it+=1;
        for(int j=i; j<n; j++)
        {
            *it +=1;
            if(arr[j]<smol)
            {
                smol = arr[j];
                ind =j;
            }
        }
        smol = 50000;
        int temp = arr[ind];
        arr[ind] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;
    
    int* it = new int();
    *it = 0;
    
    int* arr = new int[n];
    for(int i =0; i<n; i++)
    {
        arr[i]=rand()%1000;
    }
    
    cout<<"initial array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    
    selection(arr,n,it);
    
    cout<<endl<<"Iterations for random elements: "<< *it;
    *it = 0;
    
    int n1 = n;
    for(int i =0; i<n; i++)
    {
        arr[i]=n1;
        n1--;
    }
    
    selection(arr, n, it);
    cout<<endl<<"Iterations for worst case: "<< *it;
    *it = 0;
    
    selection(arr, n, it);
    cout<<endl<<"Iterations for best case: "<< *it<<endl;
    
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
}
