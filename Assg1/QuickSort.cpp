#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

int cnt = 0;
int Partition(int arr[], int start, int end)
{
  int pivot = arr[start];
  int i = start + 1;
  int j = end;
  while (i < j)
  {
    while (arr[i] < pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[start], arr[j]);
  return j;
}

void QuickSort(int arr[], int start, int end)
{
  if (start < end)
  {
    cnt++;
    int index = Partition(arr, start, end);
    QuickSort(arr, start, index - 1);
    QuickSort(arr, index + 1, end);
  }
}

int main()
{
  int t;
  cin >> t;
  int arr[t];
  for (int i = 0; i < t; i++)
  {
    cin >> arr[i];
  }
  // int arr[] = {10, 12, 45, 78, 65, 20, 32, 54, 76, 80};

  auto start = high_resolution_clock::now();
  QuickSort(arr, 0, t - 1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  cout << "After Sorting" << endl;
  cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

  cout << "iteration: " << cnt << endl;
  for (int i = 0; i < t; i++)
    cout << arr[i] << " ";
}