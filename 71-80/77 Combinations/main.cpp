#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    vector<vector<int> > v;
    Solution s;
    v = s.combine(5, 3);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
