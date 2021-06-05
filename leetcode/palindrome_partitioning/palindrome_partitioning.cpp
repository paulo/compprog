#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> curr;
    vector<vector<string>> res;

   public:
    bool isPalin(string s, int from, int to) {
        while (from <= to) {
            if (s[from] != s[to]) return false;
            from++;
            to--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        partitionRec(s, 0);

        return res;
    }

    void partitionRec(string s, int start) {
        if (start >= s.length()) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalin(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));

                partitionRec(s, i + 1);

                curr.pop_back();
            }
        }
    }

    Solution() {
        curr = vector<string>();
        res = vector<vector<string>>();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (auto x : Solution().partition("aab")) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }

    return 0;
}
