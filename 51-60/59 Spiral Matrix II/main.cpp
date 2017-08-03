#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > m;
        for (int i = 0; i < n; ++i) {
            vector<int> line;
            for (int j = 0; j < n; ++j) {
                line.push_back(0);
            }
            m.push_back(line);
        }
        int direction = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n * n; ++i) {
            m[y][x] = i + 1;
            if (direction == 0) {
                ++x;
                if (x >= n || m[y][x] != 0) {
                    --x;
                    ++y;
                    direction = 1;
                    if (y >= n || m[y][x]) {
                        break;
                    }
                }
            } else if (direction == 1) {
                ++y;
                if (y >= n || m[y][x] != 0) {
                    --y;
                    --x;
                    direction = 2;
                    if (x < 0 || m[y][x]) {
                        break;
                    }
                }
            } else if (direction == 2) {
                --x;
                if (x < 0 || m[y][x] != 0) {
                    ++x;
                    --y;
                    direction = 3;
                    if (y < 0 || m[y][x]) {
                        break;
                    }
                }
            } else if (direction == 3) {
                --y;
                if (y < 0 || m[y][x] != 0) {
                    ++y;
                    ++x;
                    direction = 0;
                    if (x >= n || m[y][x]) {
                        break;
                    }
                }
            }
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<vector<int> > res = s.generateMatrix(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
