#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        string str;
        vector<int> used;
        for (int i = 0; i < n; ++i) {
            used.push_back(0);
        }
        int pos = 1;
        while (pos <= n) {
            int tmp = 1;
            for (int i = 0; i < n - pos; ++i) {
                tmp *= (i + 1);
            }
            int rank = k / tmp;
            k -= rank * tmp;
            pos++;
            for (int i = 0; i < n; ++i) {
                if (used[i]) {
                    continue;
                }
                if (rank == 0) {
                    used[i] = 1;
                    str.push_back('1' + i);
                    break;
                }
                --rank;
            }
        }
        return str;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 3) << endl;
    cin.get();
    return 0;
}
