#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        if (s.size() % 2 != 0) return false;

        stack<char> c;
        int i = 0;
        char aux;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                c.push(s[i]);
            } else {
                if (c.empty()) return false;
                aux = c.top();
                c.pop();
                if (aux == '(' && s[i] != ')') return false;
                if (aux == '[' && s[i] != ']') return false;
                if (aux == '{' && s[i] != '}') return false;
            }
            i++;
        }

        return c.empty();
    }
};

// Can be solved using a queue/stack or backtracking
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().isValid("(){}}{") << endl;

    return 0;
}
