#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = n - 1, j = -1;
        int s = 0;
        int currLeft = 0, currRight = 0;
        while (i > j) {
            if (gas[i] - cost[i] >= 0) {
                currRight += gas[i] - cost[i];
                while (gas[j + 1] - cost[j + 1] <= 0 && currRight + gas[j + 1] - cost[j + 1] >= 0) {
                    currRight += gas[j + 1] - cost[j + 1];
                    ++j;
                }
                --i;
            } else {
                int tmpI = i;
                currLeft = gas[i] - cost[i];
                while (currLeft < 0 && i - 1 > j) {
                    --i;
                    currLeft += gas[i] - cost[i];
                }
                if (currLeft >= 0) {
                    currRight += currLeft;
                    while (gas[j + 1] - cost[j + 1] <= 0 && currRight + gas[j + 1] - cost[j + 1] >= 0) {
                        currRight += gas[j + 1] - cost[j + 1];
                        ++j;
                    }
                } else {
                    if (currLeft + currRight >= 0) {
                        return tmpI == n - 1 ? 0 : tmpI + 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
        if (currRight >= 0) {
            return i == (n - 1) ? 0 : (i + 1);
        } else {
            return -1;
        }
    }
};

int main() {
    int gasArr[] = { 1, 2, 3, 3 };
    int costArr[] = { 2, 1, 5, 1 };
    vector<int> gas(&gasArr[0], &gasArr[4]);
    vector<int> cost(&costArr[0], &costArr[4]);
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    cin.get();
    return 0;
}
