#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && check(board, word.substr(1), i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char> >& board, string word, int i, int j) {
        if (!word.size()) {
            return true;
        }
        char c = word[0], tmp = board[i][j];
        int m = board.size(), n = board[0].size();
        board[i][j] = ' ';
        if (j > 0 && board[i][j - 1] == c && check(board, word.substr(1), i, j - 1)) {
            board[i][j] = tmp;
            return true;
        }
        if (j < n - 1 && board[i][j + 1] == c && check(board, word.substr(1), i, j + 1)) {
            board[i][j] = tmp;
            return true;
        }
        if (i > 0 && board[i - 1][j] == c && check(board, word.substr(1), i - 1, j)) {
            board[i][j] = tmp;
            return true;
        }
        if (i < m - 1 && board[i + 1][j] == c && check(board, word.substr(1), i + 1, j)) {
            board[i][j] = tmp;
            return true;
        }
        board[i][j] = tmp;
        return false;
    }
};

int main() {
    char boardArr[3][4] = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
    vector<vector<char> > board;
    for (int i = 0; i < 3; ++i) {
        vector<char> line(&boardArr[i][0], &boardArr[i][4]);
        board.push_back(line);
    }
    Solution s;
    cout << s.exist(board, "ABCCED") << endl;
    cin.get();
    return 0;
}
