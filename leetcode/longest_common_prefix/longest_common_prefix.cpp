#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for (int i = 0; strs.size() > 0 && i < strs[0].size(); i++) {
            char curr = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i < strs[j].size()) {
                    if (strs[j][i] != curr) return res;
                } else {
                    return res;
                }
            }
            res += curr;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> strs = {"flower", "flow", "flight"};

    cout << Solution().longestCommonPrefix(strs) << endl;

    return 0;
}
