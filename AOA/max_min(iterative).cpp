#include <iostream>
#include <vector>

using namespace std;

vector<int> minmax(vector<int> vec, int *it)
{
    int max = vec[0];
    int min = vec[0];
    vector<int> ans;
    for(int i=1; i<vec.size(); i++)
    {
        *it +=1;
        if(max<vec[i])
            max = vec[i];
        if(min>vec[i])
            min = vec[i];
    }
    
    ans.push_back(min);
    ans.push_back(max);
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
    
    int* it = new int();
    *it=0;
    vector<int> ans = minmax(vec, it);
    
    cout<<endl<<"min element: "<<ans[0]<<endl;
    cout<<"max element: "<<ans[1]<<endl;
    cout<<"No. of iterations: "<<*it;
}
