#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t[100][100];

int KnapsackRecursion(int wt[], int val[], int W, int n)
{
    if(n == 0 || W == 0) return 0;

    if(wt[n-1] <= W) return max(val[n-1] + KnapsackRecursion(wt, val, W-wt[n-1], n-1), KnapsackRecursion(wt, val, W, n-1));

    else if(wt[n-1] > W) return KnapsackRecursion(wt, val, W, n-1);

    else return -1;
    
    // return (wt, val, W, n-1);
}

int KnapsackDP(int wt[], int val[], int w, int n)
{
    // int t[n+1][w+1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    
    cout << "Matrix After Modification\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            cout << t[i][j] << "\t";
        }
        cout << "\n";
    }
    return t[n][w];
}

int main()
{
    int n, w;
    cout << "Enter number of items available to pick: ";
    cin >> n;
    cout << "Enter capacity of Knapsack: ";
    cin >> w;
    int wt[n];
    int val[n];
    cout << "Enter WEIGHTS of " << n << " items separated by space: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter PROFITS of " << n << " items separated by space: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];
    clock_t start, end;
    cout << "\n------ Using DP ------" << endl;
    cout << "0/1 Knapsack Solution for given input(Optimized using DP): " << endl;

    start = clock();
    cout<<"\nOptimal Profit: "<< KnapsackDP(wt, val, w, n)<<endl;
    end = clock();
    cout << "Time taken by function: " << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(11) << "ms" << endl;

    cout<<"\n\n------ Using Recursion ------"<<endl;

    cout << "0/1 Knapsack Solution for given input(Optimized using Recursion):"<< endl;
    start = clock();
    cout<<"Optimal Profit: "<< KnapsackRecursion(wt, val, w, n)<<endl;
    end = clock();
    cout << "Time taken by function: " << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(11) << "ms" << endl;

}