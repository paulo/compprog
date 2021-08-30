#include <bits/stdc++.h>

using namespace std;

// After you sell your stock, you cannot buy stock on the next day (i.e.,
// cooldown one day)
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // three states: hold: 0, bought: 1, sold: 2 referring to i-1
        vector<vector<int>> dp(prices.size() + 1, vector<int>(3, INT_MIN));

        dp[0][0] = 0;

        for (int i = 0; i < prices.size(); i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][2]);

            dp[i + 1][1] = max(dp[i][0], dp[i][2] - prices[i]);

            // previous state of sold can only be hold
            dp[i + 1][2] = dp[i][0] + prices[i];
        }

        return dp[prices.size()][0];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vector<int> prices = {1, 2, 3, 0, 2};
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    cout << Solution().maxProfit(prices) << endl;

    return 0;
}
