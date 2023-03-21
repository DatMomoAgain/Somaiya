#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;

    vector<vector<float>> v;//price,weight,p/w

    float max_weight;

    for(int i=0; i<n; i++)
    {
        vector<float> temp;
        float t;
        cout<<"Enter profit of element "<<i<<": ";
        cin>>t;
        temp.push_back(t);

        float t2;
        cout<<"Enter weight of element "<<i<<": ";
        cin>>t2;
        temp.push_back(t2);

        float pw = t/t2;
        temp.push_back(pw);

        v.push_back(temp);
    }

    //sort according to pw
    float max = v[0][2];
    int ind=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(max<v[j][2])
            {
                max = v[j][2];
                ind = j;
            }
        }

        max = -1;
        vector<float> &v1 = v[i];
        vector<float> &v2 = v[ind];
        v1.swap(v2);
    }

    cout<<"Array: ";
    for(int i=0; i<n; i++)
    {
        cout<<v[i][2]<<' ';
    }
    cout<<endl;

    cout<<"Enter max capacity: ";
    cin>>max_weight;

    float curr_weight=0;
    float curr_profit=0;
    int i1=0;
    while(curr_weight<max_weight && i1<v.size())
    {
        if(v[i1][1]+curr_weight<=max_weight)
        {
            curr_weight += v[i1][1];
            curr_profit += v[i1][0];
        }
        else{
            float x = (max_weight - curr_weight)/v[i1][1];
            curr_weight += v[i1][1]*x;
            curr_profit += v[i1][0]*x;
            break;
        }
        i1++;
    }

    cout<<"max profit:"<<curr_profit<<" max weight:"<<curr_weight<<endl;
}
