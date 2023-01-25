#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

int cnt = 0;


void Merge(int arr[], int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int b[end+1];
    int k = 0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            b[k++] = arr[i++];
        }
        else{
            b[k++] = arr[j++];
        }
    }
    
    
    while(i<=mid){
        b[k++] = arr[i++];
    }
    
    while(j<=end){
        b[k++] = arr[j++];
    }
    
    
    k--;
    while(k >= 0){
        arr[k+start] = b[k];
        k--;
    }
}

void mergeSort(int arr[], int start, int end){
    int mid = (start+end) / 2;
    if(start<end){
        cnt++;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
    }
}

int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i =0; i<t; i++){
        cin>>arr[i];
    }
    
    // int arr[] = {10, 12, 45, 78, 65, 20, 32, 54, 76, 80};
    auto start = high_resolution_clock::now();
    mergeSort (arr, 0, t-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;
    
    cout <<"After Sorting"<<endl;
    cout<<"iteration: "<<cnt<<endl;
    for(int i=0;i<t;i++)
        cout <<arr[i] <<" ";
}