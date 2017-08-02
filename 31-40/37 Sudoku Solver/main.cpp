#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        solvePos(board, 0, 0);
    }
    bool solvePos(vector<vector<char> >& board, int x, int y) {
        if(x == 0 && y == 9) {
            return true;
        }
        if(board[x][y] != '.') {
            ++x;
            if(x == 9) {
                x = 0, ++y;
            }
            return solvePos(board, x, y);
        } else {
            bool validNum[9];
            for(int i = 0; i < 9; ++i) {
                validNum[i] = true;
            }
            for(int i = 0; i < 9; ++i) {
                if(board[x][i] != '.') {
                    validNum[board[x][i] - '1'] = false;
                }
            }
            for(int i = 0; i < 9; ++i) {
                if(board[i][y] != '.') {
                    validNum[board[i][y] - '1'] = false;
                }
            }
            int midX = x / 3 * 3 + 1;
            int midY = y / 3 * 3 + 1;
            for(int i = midX - 1; i <= midX + 1; ++i) {
                for(int j = midY - 1; j <= midY + 1; ++j) {
                    if(board[i][j] != '.') {
                        validNum[board[i][j] - '1'] = false;
                    }
                }
            }
            for(int i = 0; i < 9; ++i) {
                if(validNum[i]) {
                    board[x][y] = '1' + i;
                    int newX = x + 1;
                    int newY = y;
                    if(newX == 9) {
                        newX = 0, ++newY;
                    }
                    if(solvePos(board, newX, newY)) {
                        return true;
                    } else {
                        board[x][y] = '.';
                    }
                }
            }
            return false;
        }
    }
};

int main() {
    int list[9][9] = 
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    vector<vector<char> > board;
    for(int i = 0; i < 9; ++i) {
        vector<char> line;
        for(int j = 0; j < 9; ++j) {
            line.push_back(list[i][j]);
        }
        board.push_back(line);
    }
    Solution s;
    s.solveSudoku(board);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
