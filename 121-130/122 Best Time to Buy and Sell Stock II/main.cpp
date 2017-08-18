#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0};
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
            swap(next, cur);
        }
        return max(states[cur][1], states[cur][3]);
    }
};

int main() {
    int price[] = { 7, 1, 5, 3, 6, 4 };
    vector<int> prices(&price[0], &price[6]);
    Solution s;
    cout << s.maxProfit(prices) << endl;
    cin.get();
    return 0;
}
