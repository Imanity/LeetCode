#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int m_x, int m_y) : x(m_x), y(m_y) {}
};

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') {
                    bool isSurrounded = true;
                    vector<Pos> v;
                    queue<Pos> q;
                    v.push_back(Pos(i, j));
                    q.push(Pos(i, j));
                    board[i][j] = 'C';
                    while (!q.empty()) {
                        Pos curr = q.front();
                        q.pop();
                        int cx = curr.x, cy = curr.y;
                        if (cx == 0 || cy == 0 || cx == board.size() - 1 || cy == board[0].size() - 1) {
                            isSurrounded = false;
                        }
                        if (cx > 0 && board[cx - 1][cy] == 'O') {
                            board[cx - 1][cy] = 'C';
                            v.push_back(Pos(cx - 1, cy));
                            q.push(Pos(cx - 1, cy));
                        }
                        if (cx < board.size() - 1 && board[cx + 1][cy] == 'O') {
                            board[cx + 1][cy] = 'C';
                            v.push_back(Pos(cx + 1, cy));
                            q.push(Pos(cx + 1, cy));
                        }
                        if (cy > 0 && board[cx][cy - 1] == 'O') {
                            board[cx][cy - 1] = 'C';
                            v.push_back(Pos(cx, cy - 1));
                            q.push(Pos(cx, cy - 1));
                        }
                        if (cy < board[0].size() - 1 && board[cx][cy + 1] == 'O') {
                            board[cx][cy + 1] = 'C';
                            v.push_back(Pos(cx, cy + 1));
                            q.push(Pos(cx, cy + 1));
                        }
                    }
                    if (isSurrounded) {
                        for (int k = 0; k < v.size(); ++k) {
                            board[v[k].x][v[k].y] = 'X';
                        }
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    char b[4][4] = { { 'X', 'X', 'X', 'X' }, 
                        { 'X', 'O', 'O', 'X' }, 
                        { 'X', 'X', 'O', 'X' }, 
                        { 'X', 'O', 'X', 'X' } };
    vector<vector<char> > board;
    for (int i = 0; i < 4; ++i) {
        vector<char> line(&b[i][0], &b[i][4]);
        board.push_back(line);
    }
    Solution s;
    s.solve(board);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
