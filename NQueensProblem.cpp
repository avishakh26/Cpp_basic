#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen
bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Function to print the board
void printBoard(vector<vector<int>> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

// Backtracking function
void solveNQueens(vector<vector<int>> &board, int row, int n, int &solutionCount) {
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":" << endl;
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // place queen

            solveNQueens(board, row + 1, n, solutionCount);

            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    int solutionCount = 0;

    solveNQueens(board, 0, n, solutionCount);

    if (solutionCount == 0)
        cout << "No solutions found." << endl;
    else
        cout << "Total solutions: " << solutionCount << endl;

    return 0;
}

