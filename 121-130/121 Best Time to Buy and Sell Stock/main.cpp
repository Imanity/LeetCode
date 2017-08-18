#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                if (prices[i] - min > profit) {
                    profit = prices[i] - min;
                }
            }
        }
        return profit;
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
