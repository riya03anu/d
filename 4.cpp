#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int column, int N) {
    int i, j;

    // Same Row
    for (i = 0; i < column; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Upper Diagonal
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Lower Diagonal
    for (i = row, j = column; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void printSolution(const vector<vector<int>>& board) {
    static int solutionCount = 0;
    cout << "Solution " << ++solutionCount << ":" << endl;
    for (const vector<int>& row : board) {
        for (int cell : row) {
            if (cell) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

bool nQueenAlgo(vector<vector<int>>& board, int column, int N) {
    if (column >= N) {
        printSolution(board);
        return true;
    }

    bool foundSolution = false;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, column, N)) {
            board[i][column] = 1;
            foundSolution = nQueenAlgo(board, column + 1, N) || foundSolution;
            board[i][column] = 0;
        }
    }

    return foundSolution;
}

int main() {
    int size;
    cout << "Enter Size of Board: ";
    cin >> size;

    int N = size;

    // Create a 2D vector to represent the chessboard
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!nQueenAlgo(board, 0, N)) {
        cout << "No solutions exist." << endl;
    }

    return 0;
}
