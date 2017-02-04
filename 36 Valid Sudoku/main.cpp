#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int isDup[9];
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                isDup[j] = 0;
            }
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    continue;
                }
                ++isDup[board[i][j] - '1'];
                if(isDup[board[i][j] - '1'] > 1) {
                    return false;
                }
            }
        }
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                isDup[j] = 0;
            }
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] == '.') {
                    continue;
                }
                ++isDup[board[j][i] - '1'];
                if(isDup[board[j][i] - '1'] > 1) {
                    return false;
                }
            }
        }
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                isDup[j] = 0;
            }
            for(int j = 0; j < 9; ++j) {
                int l = (i / 3) * 3 + (j / 3);
                int r = (i % 3) * 3 + (j % 3);
                if(board[l][r] == '.') {
                    continue;
                }
                ++isDup[board[l][r] - '1'];
                if(isDup[board[l][r] - '1'] > 1) {
                    return false;
                }
            }
        }
        return true;
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
    cout << s.isValidSudoku(board);
    cin.get();
    return 0;
}
