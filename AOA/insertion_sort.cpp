#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertion(int* arr, int n, int* it)
{
    int k;
    for(int i=0; i<n-1; i++)
    {
        *it +=1;
        if(arr[i]>arr[i+1])
        {
            k = arr[i+1];
            for(int j=i; j>=0; j--)
            {
                *it +=1;
                if(arr[j]<k)
                {
                    arr[j+1] = k;
                    break;
                }
                else if(j==0 && arr[j]>k)
                {
                    arr[j+1] = arr[j];
                    arr[j] = k;
                    break;
                }
                else
                {
                    arr[j+1] = arr[j];
                }
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
    
    insertion(arr, n, it);
    
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
    
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
}
