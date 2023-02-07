#include <iostream>
#include <vector>

using namespace std;

int binary(vector<int> &vec, int l, int r, int key)
{
    if(l>r)
    {
        return -1;
    }
    
    int m = (l+r)/2;
    
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
    
    binary(vec, l, r, key);
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
    
    if(binary(vec,0,n-1,k) >=0)
    {
        cout<<"No. exists at index "<<binary(vec,0,n-1,k);
    }
    else
    {
        cout<<"no. doesnt exist";
    }
    
    
}
