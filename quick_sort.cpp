#include<iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr,int low,int high);
void qs(vector<int>& arr,int low,int high);

void quick_sort(vector<int>& arr){
    qs(arr,0,arr.size()-1);
}
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            int temp= arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>& arr,int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        qs(arr,low,p-1);
        qs(arr,p+1,high);
    }
    
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"enter elements:";
        cin>>arr[i];
    }
    cout<<"unsorted array:"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
       
    }

    quick_sort(arr);
    cout<<endl;
    cout<<"sorted array:"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
       
    }


}