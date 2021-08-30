#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) { return backtrack(s, 0, p, 0); }

    bool backtrack(string s, int si, string p, int pi) {
        if (si >= s.length() && pi >= p.length()) return true;
        if (si >= s.length() || pi >= p.length()) return false;

        if (s[si] == p[pi] || p[pi] == '.') {
            cout << "here 1: " << si << endl;
            return backtrack(s, si + 1, p, pi + 1);
        }

        if (p[pi] == '*') {
            if (p[pi - 1] == s[si] || p[pi - 1] == '.') {
                cout << "here 2: " << si << endl;
                return backtrack(s, si + 1, p, pi + 1) ||
                       backtrack(s, si + 1, p, pi) ||
                       backtrack(s, si, p, pi + 1);
            }
        }

        if (pi + 1 < p.length() && p[pi + 1] == '*') {
            cout << "here 3: " << si << endl;
            return backtrack(s, si, p, pi + 2);
        }

        cout << "here 4: " << si << endl;
        return false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().isMatch("aa", "a") << endl;
    cout << Solution().isMatch("aab", "c*a*b") << endl;
    cout << Solution().isMatch("ab", ".*") << endl;
    cout << Solution().isMatch("mississippi", "mis*is*p*.") << endl;
    cout << Solution().isMatch("ab", ".*c") << endl;
    cout << Solution().isMatch("aaa", "ab*a*c*a") << endl;
    cout << Solution().isMatch("aaca", "ab*a*c*a") << endl;

    return 0;
}
