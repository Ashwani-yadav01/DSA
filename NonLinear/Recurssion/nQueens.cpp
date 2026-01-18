#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solutions;

bool isSafe(int row, int col, vector<string>& board, int n) {
    // check upper column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(int row, vector<string>& board, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';     // place queen
            solve(row + 1, board, n);  // recursive call
            board[row][col] = '.';     // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    solutions.clear();
    vector<string> board(n, string(n, '.'));
    solve(0, board, n);
    return solutions;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    if (result.empty()) {
        cout << "No solution exists for N = " << n << endl;
    } else {
        cout << "Solutions for N = " << n << ":\n";
        for (auto board : result) {
            for (auto row : board) {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
