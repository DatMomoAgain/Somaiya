#include <iostream>
#include <vector>

using namespace std;

int binary(vector<int> &vec, int key)
{
    int l=0;
    int r=vec.size();
    
    while(l<r)
    {
        int m=(l+r)/2;
        if(vec[m]<key)
        {
            l = m+1;
        }
        else if(vec[m]>key)
        {
            r = m-1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}

int main()
{
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;
    cout<<"Enter elements: ";
    vector<int> vec;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        vec.push_back(t);
    }
    
    cout<<"Enter no. to be found: ";
    int k;
    cin>>k;
    
    if(binary(vec,k) >=0)
    {
        cout<<"No. exists at index "<<binary(vec,k);
    }
    else
    {
        cout<<"no. doesnt exist";
    }
    
    
}
