#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        vector<int> empty;
        res.push_back(empty);
        for (int i = 1; i <= n; ++i) {
            vector<vector<int> > tmp = combine(n, i);
            for (int j = 0; j < tmp.size(); ++j) {
                vector<int> single;
                for (int k = 0; k < tmp[j].size(); ++k) {
                    single.push_back(nums[tmp[j][k] - 1]);
                }
                res.push_back(single);
            }
        }
        return res;
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> line;
        vector<vector<int> > res;
        if (k == 1) {
            for (int i = 0; i < n; ++i) {
                line.resize(0);
                line.push_back(i + 1);
                res.push_back(line);
            }
            return res;
        }
        while (true) {
            if (line.size()) {
                while (line.back() == n) {
                    line.pop_back();
                }
                line[line.size() - 1]++;
            }
            while (line.size() < k) {
                if (line.size()) {
                    if (line.back() >= n) {
                        break;
                    }
                    line.push_back(line.back() + 1);
                } else {
                    line.push_back(1);
                }
            }
            if (line.size() == 1) {
                break;
            }
            if (line.size() == k) {
                res.push_back(line);
            }
        }
        return res;
    }
};

int main() {
    int nums[3] = { 1, 2, 3 };
    vector<int> numSet(&nums[0], &nums[3]);
    vector<vector<int> > v;
    Solution s;
    v = s.subsets(numSet);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
