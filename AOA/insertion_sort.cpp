#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertion(int* arr, int n)
{
    int k;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            k = arr[i+1];
            for(int j=i; j>=0; j--)
            {
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
    
    time_t start, end;
    
    int* arr = new int[n];
    for(int i =0; i<n; i++)
    {
        arr[i]=rand()%1000;
    }
    
    time(&start);
    
    insertion(arr, n);
    
    time(&end);
    double time_taken = double(end - start);
    
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
    cout<<endl<<"Time taken: "<< time_taken<<'s';
}
