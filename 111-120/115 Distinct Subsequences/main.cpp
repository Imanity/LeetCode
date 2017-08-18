#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (!s.size() || !t.size()) {
            return 0;
        }
        vector<vector<int> > arr;
        for (int i = 0; i < s.size(); ++i) {
            vector<int> line;
            for (int j = 0; j < t.size(); ++j) {
                line.push_back(-1);
            }
            arr.push_back(line);
        }
        arr[0][0] = (s[0] == t[0]);
        for (int j = 1; j < t.size(); ++j) {
            arr[0][j] = 0;
        }
        for (int i = 1; i < s.size(); ++i) {
            arr[i][0] = arr[i - 1][0];
            if (s[i] == t[0]) {
                arr[i][0]++;
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 1; j < t.size(); ++j) {
                if (s[i] == t[j]) {
                    arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
                } else {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
        return arr[s.size() - 1][t.size() - 1];
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("ccc", "c") << endl;
    cin.get();
    return 0;
}
