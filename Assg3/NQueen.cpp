
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool canPlaceQueen(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == abs(row - i)) {
            return false;
        }
    }
    return true;
}

void printBoard(int n, vector<int>& queens) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queens[i] == j) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueens(int n, int row, vector<int>& queens) {
    if (row == n) {
        printBoard(n, queens);
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (canPlaceQueen(row, col, queens)) {
            queens[row] = col;
            if (solveNQueens(n, row + 1, queens)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cout<<"Enter the number of queen: ";    
    cin>>n;
    vector<int> queens(n);
    auto start = high_resolution_clock::now();
    bool foundSolution = solveNQueens(n, 0, queens);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
}