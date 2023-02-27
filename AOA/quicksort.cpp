#include <iostream>
#include <vector>
using namespace std;

int it =0;

//returns pivot element
int partition(vector<int> &v, int l, int r){
    it++;
    int pivot = l;
    int end = r;

    while(r>l){
        while(v[l]<=v[pivot] && l<end){
            l++;
        }
        while(v[r]>=v[pivot] && r>pivot){
            r--;
        }
        if(l<r){
            int t = v[l];
            v[l]= v[r];
            v[r]= t;
        }
    }
    int t = v[pivot];
    v[pivot]= v[r];
    v[r]= t;
    pivot = r;

    return pivot;
}

void quicksort(vector<int> &v, int l, int r){
    if(l<r){
        int q = partition(v, l, r);
        quicksort(v, l, q-1);
        quicksort(v, q+1, r);
    }
}

int main(){
    vector<int> v;
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    srand(time(0));

    cout<<"Initial array is: ";
    for(int i=0; i<n; i++){
        v.push_back(rand()%1000);
        cout<<v[i]<<' ';
    }
    cout<<endl;

    quicksort(v, 0, n-1);

    cout<<"Sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<' ';
    }

    cout<<endl<<"No. of iterations are: "<<it<<endl;
}
