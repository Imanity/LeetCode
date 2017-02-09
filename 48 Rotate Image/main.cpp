#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        for(int i = 0; i < matrix.size() / 2; ++i) {
            for(int j = 0; j < matrix.size() / 2; ++j) {
                exchange(matrix[i][j], matrix[j][matrix.size() - i - 1], 
                matrix[matrix.size() - i - 1][matrix.size() - j - 1], matrix[matrix.size() - j - 1][i]);
            }
        }
        if(matrix.size() % 2 == 1) {
            for(int i = 0; i < matrix.size() / 2; ++i) {
                exchange(matrix[i][matrix.size() / 2], matrix[matrix.size() / 2][matrix.size() - i - 1], 
                matrix[matrix.size() - i - 1][matrix.size() - matrix.size() / 2 - 1], 
                matrix[matrix.size() - matrix.size() / 2 - 1][i]);
            }
        }
    }
    void exchange(int &a, int &b, int &c, int &d) {
        if(a != b) {
            a ^= b; b ^= a; a ^= b;
        }
        if(c != d) {
            c ^= d; d ^= c; c ^= d;
        }
        if(a != c) {
            a ^= c; c ^= a; a ^= c;
        }
    }
};

int main() {
    int list[5][5] = 
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };
    vector<vector<int> > board;
    for(int i = 0; i < 5; ++i) {
        vector<int> line;
        for(int j = 0; j < 5; ++j) {
            line.push_back(list[i][j]);
        }
        board.push_back(line);
    }
    Solution s;
    s.rotate(board);
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl << endl << endl << endl;
    }
    cin.get();
    return 0;
}
