#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<char> curr;
    vector<string> res;
    stack<char> q;
    unordered_map<string, bool> m;

   public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;  // number of misplaced parentheses

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        backtrack(s, 0, left + right);

        return res;
    }

    void backtrack(string s, int i, int left) {
        if (left == 0 && i == s.size() && q.empty()) {
            string s(curr.begin(), curr.end());
            if (m[s]) return;
            m[s] = true;
            res.push_back(s);
            return;
        }

        if (s.size() == i) return;

        if (left > 0 && (s[i] == '(' || s[i] == ')')) {
            backtrack(s, i + 1, left - 1);
        }

        char removed = '\0';
        bool inserted = false;
        if (s[i] == '(') {
            q.push(s[i]);
            inserted = true;
        } else if (s[i] == ')' && !q.empty()) {
            removed = q.top();
            q.pop();
        } else if (s[i] == ')' || s[i] == '(')
            return;

        curr.push_back(s[i]);
        backtrack(s, i + 1, left);
        curr.pop_back();
        if (removed != '\0')
            q.push(removed);
        else if (inserted)
            q.pop();
    }

    Solution() {
        curr = vector<char>();
        res = vector<string>();
        q = stack<char>();
        m = unordered_map<string, bool>();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto r : Solution().removeInvalidParentheses("(a)())()"))
    // cout << r << " ";
    // cout << endl;

    for (auto r : Solution().removeInvalidParentheses(")(()c))("))
        cout << r << " ";
    cout << endl;

    return 0;
}
