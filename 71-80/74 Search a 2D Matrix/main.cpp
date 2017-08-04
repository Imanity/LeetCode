#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (!matrix.size()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (r >= l) {
            int mid = (l + r) / 2;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    int table[4][4] = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
    vector<vector<int> > matrix;
    for (int i = 0; i < 3; ++i) {
        vector<int> line(&table[i][0], &table[i][4]);
        matrix.push_back(line);
    }
    Solution s;
    cout << s.searchMatrix(matrix, 2) << endl;
    cin.get();
    return 0;
}
