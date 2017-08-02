#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int x, y;
    Pair(int a, int b): x(a), y(b) {}
};

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> board;
        string line;
        for(int i = 0; i < n; ++i) {
            line.push_back('.');
        }
        for(int i = 0; i < n; ++i) {
            board.push_back(line);
        }
        res.push_back(board);
        return solver(n, 0, res);
    }
    vector<vector<string> > solver(int n, int pos, vector<vector<string> > &boards) {
        if(pos == n) {
            return boards;
        }
        vector<vector<string> > res;
        for(int i = 0; i < boards.size(); ++i) {
            for(int j = 0; j < n; ++j) {
                vector<string> board;
                for(int k = 0; k < pos; ++k) {
                    board.push_back(boards[i][k]);
                }
                string line;
                for(int k = 0; k < j; ++k) {
                    line.push_back('.');
                }
                line.push_back('Q');
                for(int k = j + 1; k < n; ++k) {
                    line.push_back('.');
                }
                board.push_back(line);
                for(int k = pos + 1; k < n; ++k) {
                    board.push_back(boards[i][k]);
                }
                if(checkBoard(n, pos, board)) {
                    res.push_back(board);
                }
            }
        }
        return solver(n, pos + 1, res);
    }
    bool checkBoard(int n, int pos, vector<string> board) {
        vector<Pair> pairs;
        for(int i = 0; i <= pos; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'Q') {
                    Pair pos(i, j);
                    pairs.push_back(pos);
                }
            }
        }
        for(int i = 0; i < pairs.size(); ++i) {
            for(int j = i + 1; j < pairs.size(); ++j) {
                if(!checkPair(pairs[i], pairs[j])) {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkPair(Pair a, Pair b) {
        if(a.x == b.x) {
            return false;
        }
        if(a.y == b.y) {
            return false;
        }
        if((a.x - b.x) == (a.y - b.y)) {
            return false;
        }
        if((b.x - a.x) == (a.y - b.y)) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<string> > res = s.solveNQueens(8);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << endl;
        }
        cout << endl << endl;
    }
    cin.get();
    return 0;
}
