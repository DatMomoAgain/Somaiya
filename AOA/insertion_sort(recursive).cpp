#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertion(int* arr, int n, int* it)
{
    *it+=1;
    if(n==1)
    {
        return;
    }
    insertion(arr,n-1,it);
    if(arr[n-1]<arr[n-2])
    {
        for(int i=n-1; i>=1; i--)
        {
            *it++;
            if(arr[i]<arr[i-1])
            {
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }
        }
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
        arr[i]=rand()%10000;
    }
    
    cout<<"Initial array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    
    insertion(arr, n, it);
    
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
    
    insertion(arr, n, it);
    cout<<endl<<"Iterations for worst case: "<< *it;
    *it = 0;
    
    insertion(arr, n, it);
    cout<<endl<<"Iterations for best case: "<< *it<<endl;
    
    
}
