#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        obstacleGrid[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (obstacleGrid[i][j] != 0) {
                    continue;
                }
                int a = 0;
                int b = 0;
                if (i < m - 1 && obstacleGrid[i + 1][j] != -1) {
                    a = obstacleGrid[i + 1][j];
                }
                if (j < n - 1 && obstacleGrid[i][j + 1] != -1) {
                    b = obstacleGrid[i][j + 1];
                }
                obstacleGrid[i][j] = a + b;
            }
        }
        return obstacleGrid[0][0];
    }
};

int main () {
    vector<vector<int> > grid;
    vector<int> line1;
    vector<int> line2;
    for (int i = 0; i < 3; ++i) {
        line1.push_back(0);
    }
    line2.push_back(0);
    line2.push_back(1);
    line2.push_back(0);
    grid.push_back(line1);
    grid.push_back(line2);
    grid.push_back(line1);
    Solution s;
    cout << s.uniquePathsWithObstacles(grid) << endl;
    cin.get();
    return 0;
}
