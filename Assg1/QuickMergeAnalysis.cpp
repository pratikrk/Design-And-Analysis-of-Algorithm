#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;
/*
Name : Pratik K. Rathod
Roll No : 321056
PRN No: 22010885
*/

int cnt1=0, cnt2=0;

void PrintArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
/* -------- Quick Sort Program Starts Here -------- */
int Partition(int arr[], int start, int end)
{
  int pivot = arr[end];
  int i = (start-1);
  for(int j = start; j<= end-1; j++){
    if(arr[j] <= pivot){
        i++;
        swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[end]);
  return (i+1);
}

void QuickSort(int arr[], int start, int end)
{
  if (start < end)
  {
    cnt1++;
    int index = Partition(arr, start, end);
    QuickSort(arr, start, index - 1);
    QuickSort(arr, index + 1, end);
  }
  else{
    cnt1++;
  }
}

/* -------- Merge Sort Program Starts Here -------- */
void Merge(int arr[], int start, int mid, int end){
    int temp[end + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    k--;
    while (k >= 0)
    {
        arr[k + start] = temp[k];
        k--;
    }
}

void mergeSort(int arr[], int start, int end){
    
    if(start<end){
        
        int mid = (start+end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
        cnt2++;
    }
}

/* ----- Main Function ----- */
int main(){
    int n;

    cout<<"Quick Sort and merge sort Efficiency and time comparision."<<endl;
    cout<<"Enter Number of integer elements: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
    cout<< "Unsorted generated elements: \n ";

    for(int i =0; i<n;i++){
        cout<< arr[i]<<" ";
    }

    cout<<"\n\n===== Quick Sort ====";
    
    auto start1 = high_resolution_clock::now();
    QuickSort(arr, 0, n - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

    cout << "\nAfter Sorting" << endl;
    PrintArr(arr, n);
    cout << "\nTime taken by function: " << duration1.count() << " nanoseconds" << endl;

    cout << "Quick Sort iteration: " << cnt1 << endl;
    

    cout<<"\n\n===== Merge Sort ====";
    auto start2 = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "\nAfter Sorting" << endl;
    PrintArr(arr, n);
    cout << "\nTime taken by function: " << duration2.count() << " nanoseconds" << endl;
    cout << "Merge Sort iteration: " << cnt2 << endl;

    if(cnt1<cnt2) cout<<"\n\nQuick Sort Is better than Merge Sort Here.";
    else cout<<"\n\nMerge Sort is better than Quick Sort Here.\n";
    
}
