#include <iostream>
using namespace std;

void bubble(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int k=0;
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                k++;
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
        if(k==0)
        {
            break;
        }
    }
}

void insertion(int* arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i+1];
            for(int j=i; j>=0; j--)
            {
                if(arr[j]>temp)
                {
                    arr[j+1] = arr[j];
                }
                else
                {
                    arr[j+1] = temp;
                    break;
                }

                if(j==0)
                {
                    arr[j] = temp;
                    break;
                }
            }

        }
    }
}

void count(int* arr, int n)
{
    //min element
    int mini = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<mini)
        {
            mini = arr[i];
        }
    }

    //max element
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>maxi)
        {
            maxi = arr[i];
        }
    }

    int ca_size = maxi-mini+1;
    int count_array[ca_size];
    for(int i=0; i<ca_size; i++)
    {
        count_array[i] = 0;
    }

    //store unique count of each key
    for(int i=0; i<n; i++)
    {
        count_array[arr[i]-mini]++;
    }

    //cumulative addition
    for(int i=0; i<ca_size-1; i++)
    {
        count_array[i+1] += count_array[i];
    }

    //right shift
    for(int i=ca_size-2; i>=0; i--)
    {
        count_array[i+1] = count_array[i];
    }
    count_array[0] = 0;

    int sort_array[n];
    for(int i=0; i<n; i++)
    {
        sort_array[count_array[arr[i]-mini]] = arr[i];
        count_array[arr[i]-mini]++;
    }

    //copying sorted array into original array
    for(int i=0; i<n; i++)
    {
        arr[i] = sort_array[i];
    }
}


int main()
{
    //taking input
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    //copying contents of arr into 3 other arrays
    int* bubble_arr = new int[n];
    int* insertion_arr = new int[n];
    int* count_arr = new int[n];
    for(int i=0; i<n; i++)
    {
        bubble_arr[i] = arr[i];
        insertion_arr[i] = arr[i];
        count_arr[i] = arr[i];
    }

    //display
    cout<<"Bubble sort: ";
    bubble(bubble_arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<bubble_arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Insertion sort: ";
    insertion(insertion_arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<insertion_arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Count sort: ";
    count(count_arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<count_arr[i]<<" ";
    }
    cout<<endl;
}
