#include <iostream>
#include <vector>

using namespace std;

vector<int> minmax(vector<int> vec, int l, int r)
{
    vector<int> ans;
    vector<int> ans2;
    if(l==r)
    {
        ans.push_back(vec[l]);
        ans.push_back(vec[r]);
        return ans;
    }
    
    int m= (l+r)/2;
    ans = minmax(vec,l,m);
    ans2 = minmax(vec,m+1,r);
    
    if(ans[0]>ans2[0])
    {
        ans[0] = ans2[0];
    }
    
    if(ans[1]<ans2[1])
    {
        ans[1] = ans2[1];
    }
    
    return ans;

}

int main()
{
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0; i<n; i++)
    {
        int t = rand()%1000;
        vec.push_back(t);
    }
    
    cout<<"Array is: ";
    for(int i=0; i<n; i++)
    {
        cout<<vec[i]<<' ';
    }
    
    vector<int> ans = minmax(vec, 0, n-1);
    
    cout<<endl<<"min element: "<<ans[0]<<endl;
    cout<<"max element: "<<ans[1];
}
