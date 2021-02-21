#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
    string curr;
    vector<string> res;

   public:
    vector<string> generateParenthesis(int n) {
        generate(n, 0);
        return res;
    }

    void generate(int n, int open) {
        if (n == 0 && open == 0) {
            res.push_back(curr);
            return;
        } else {
            if (n > 0) {
                curr += '(';
                generate(n - 1, open + 1);
                curr.pop_back();
            }

            if (open > 0) {
                curr += ')';
                generate(n, open - 1);
                curr.pop_back();
            }
        }
    }

    Solution() {
        curr = "";
        res = vector<string>();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v = Solution().generateParenthesis(3);
    for (auto s : v) cout << s << endl;

    return 0;
}
