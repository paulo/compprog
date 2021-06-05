#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> mem;

   public:
    int numDecodings(string s) { return decs(s, 0); }

    int decs(string s, int i) {
        if (i == s.size()) return 1;
        if (mem[i] > -1) return mem[i];

        int t = 0;

        if (s[i] >= '1' && s[i] <= '9') {
            t += decs(s, i + 1);
        }

        if (s[i] > '0' && s[i] < '3' && i + 1 < s.size() &&
            (s[i] == '1' || s[i + 1] < '7')) {
            t += decs(s, i + 2);
        }

        mem[i] = t;

        return t;
    }

    Solution() { mem = vector<int>(101, -1); }
};

// Iterative solution
class Solution {
   public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1);
        dp[0] = 1;  // can be always one because we check that two_digit is >=10

        // '0' doesn't have a single digit decode.
        dp[1] = s[0] == '0' ? 0 : 1;

        for (size_t i = 2; i < dp.size(); i++) {
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int two_digit = stoi(s.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.length()];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().numDecodings("1201234") << endl;

    return 0;
}
