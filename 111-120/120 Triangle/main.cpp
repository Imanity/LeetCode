#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i; ++j) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        int minNum = INT_MAX;
        for (int i = 0; i < triangle.size(); ++i) {
            if (triangle[triangle.size() - 1][i] < minNum) {
                minNum = triangle[triangle.size() - 1][i];
            }
        }
        return minNum;
    }
};

int main() {
    Solution s;
    vector<vector<int> > t;
    int line0[] = { 2 };
    vector<int> l0(&line0[0], &line0[1]);
    t.push_back(l0);
    int line1[] = { 3, 4 };
    vector<int> l1(&line1[0], &line1[2]);
    t.push_back(l1);
    int line2[] = { 6, 5, 7 };
    vector<int> l2(&line2[0], &line2[3]);
    t.push_back(l2);
    int line3[] = { 4, 1, 8, 3 };
    vector<int> l3(&line3[0], &line3[4]);
    t.push_back(l3);
    cout << s.minimumTotal(t) << endl;
    cin.get();
    return 0;
}
