#include <iostream>

using namespace std;

//start will be 0 in main
void selection(int* arr, int start, int n, int* it)
{
    *it+=1;
    if(start==n-1)
    {
        return;
    }
    //find min element
    int min = arr[start];
    int min_ind = start;
    for(int i=start; i<n; i++)
    {
        *it+=1;
        if(arr[i]<min)
        {
            min = arr[i];
            min_ind = i;
        }
    }
    //swap
    int temp = arr[start];
    arr[start] = arr[min_ind];
    arr[min_ind] = temp;

    selection(arr,start+1,n,it);
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
    
    selection(arr,0,n,it);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
    cout<<endl<<"Iterations for random elements: "<< *it;
    *it = 0;
    
    int n1 = n;
    for(int i =0; i<n; i++)
    {
        arr[i]=n1;
        n1--;
    }
    
    selection(arr,0, n, it);
    cout<<endl<<"Iterations for worst case: "<< *it;
    *it = 0;
    
    selection(arr,0, n, it);
    cout<<endl<<"Iterations for best case: "<< *it<<endl;
    
}
