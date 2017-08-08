#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (!matrix.size()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0);
        int maxS = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    h[j]++;
                } else {
                    h[j] = 0;
                }
            }
            int s = largestRectangleArea(h);
            if (s > maxS) {
                maxS = s;
            }
        }
        return maxS;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int tp;
        int area_with_top;
        int i = 0;
        while (i < heights.size()) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            } else {
                tp = s.top();
                s.pop();
                
                area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }
        while (s.empty() == false) {
            tp = s.top();
            s.pop();
            area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
        return max_area;
    }
};

int main() {
    char table[4][5] = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, 
        { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
    vector<vector<char> > matrix;
    for (int i = 0; i < 4; ++i) {
        vector<char> line;
        for (int j = 0; j < 5; ++j) {
            line.push_back(table[i][j]);
        }
        matrix.push_back(line);
    }
    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    cin.get();
    return 0;
}
