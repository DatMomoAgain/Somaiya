#include <iostream>
#include <vector>
using namespace std;

int it =0;

void disp(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

void merge(vector<int> &v, int l, int m, int r){
    cout<<"l:"<<l<<" m:"<<m<<" r:"<<r<<endl;
    disp(v);
    it++;

    //creating 2 arrays for left side and right side
    vector<int> left_arr;
    vector<int> right_arr;
    for(int i=l; i<=m; i++){
        left_arr.push_back(v[i]);
    }
    for(int i=m+1; i<=r; i++){
        right_arr.push_back(v[i]);
    }

    //merging
    int i = left_arr.size()-1;
    int j = right_arr.size()-1;
    while(i>=0 && j>=0 && r>=l){
        if(left_arr[i]>right_arr[j]){
            v[r] = left_arr[i];
            i--;
            r--;
        }
        else{
            v[r] = right_arr[j];
            r--;
            j--;
        }
    }

    //if one or both left/right arrays put all their elements in vector
    if(r<l){
        return;
    }
    else if(i<0){
        while(j>=0){
            v[r] = right_arr[j];
            r--;
            j--;
        }
    }
    else if(j<0){
        while(i>=0){
            v[r] = left_arr[i];
            i--;
            r--;
        }
    }
}

void mergesort(vector<int> &v, int l, int r){
    int m = (l+r)/2;
    if(l<r){
        mergesort(v, l, m);
        mergesort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){
    vector<int> v;
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    //srand(time(0));

    cout<<"Initial array is: ";
    for(int i=0; i<n; i++){
        v.push_back(rand()%1000);
        cout<<v[i]<<' ';
    }
    cout<<endl;

    mergesort(v, 0, n-1);

    cout<<"Sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<' ';
    }

    cout<<endl<<"No. of iterations are: "<<it<<endl;
}
