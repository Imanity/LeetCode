#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }
        vector<int> arr(n + 1, -1);
        vector<int> pal(1, 0);
        arr[0] = arr[1] = 0;
        for (int i = 1; i < n; ++i) {
            for (vector<int>::iterator j = pal.begin(); j != pal.end();) {
                if (*j > 0 && s[*j - 1] == s[i]) {
                    if (arr[i + 1] == -1 || arr[i + 1] > (*j == 1 ? 0 : arr[*j - 1] + 1)) {
                        arr[i + 1] = (*j == 1 ? 0 : arr[*j - 1] + 1);
                    }
                    (*j)--;
                    ++j;
                } else {
                    j = pal.erase(j);
                }
            }
            pal.push_back(i);
            if (arr[i + 1] == -1 || arr[i + 1] > (i == 0 ? 0 : arr[i] + 1)) {
                arr[i + 1] = (i == 0 ? 0 : arr[i] + 1);
            }
            if (s[i] == s[i - 1]) {
                pal.push_back(i - 1);
                if (arr[i + 1] == -1 || arr[i + 1] > (i == 1 ? 0 : arr[i - 1] + 1)) {
                    arr[i + 1] = (i == 1 ? 0 : arr[i - 1] + 1);
                }
            }
        }
        return arr[n];
    }
};

int main() {
    Solution s;
    cout << s.minCut("cabababcbc") << endl;
    cin.get();
    return 0;
}
