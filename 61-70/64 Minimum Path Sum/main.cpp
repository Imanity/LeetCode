#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > cost;
        for (int i = 0; i < m; ++i) {
            vector<int> lineCost;
            for (int j = 0; j < n; ++j) {
                lineCost.push_back(0);
            }
            cost.push_back(lineCost);
        }
        cost[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1)
                    continue;
                int a = -1;
                int b = -1;
                if (i < m - 1) {
                    a = cost[i + 1][j];
                }
                if (j < n - 1) {
                    b = cost[i][j + 1];
                }
                if (a == -1) {
                    cost[i][j] = b + grid[i][j];
                } else if (b == -1) {
                    cost[i][j] = a + grid[i][j];
                } else {
                    cost[i][j] = a > b ? b : a;
                    cost[i][j] += grid[i][j];
                }
            }
        }
        return cost[0][0];
    }
};

int main () {
    vector<vector<int> > grid;
    for (int i = 0; i < 3; ++i) {
        vector<int> line;
        for (int j = 0; j < 3; ++j) {
            line.push_back(i * 3 + j + 1);
        }
        grid.push_back(line);
    }
    Solution s;
    cout << s.minPathSum(grid) << endl;
    cin.get();
    return 0;
}