#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;

        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "/" || t == "*") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();

                if (t == "+") q.push(a + b);
                if (t == "-") q.push(a - b);
                if (t == "/") q.push(floor(a / b));
                if (t == "*") q.push(a * b);
            } else {
                q.push(stoi(t));
            }
        }

        return q.top();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> toks = {"10", "6", "9",  "3", "+", "-11", "*",
                           "/",  "*", "17", "+", "5", "+"};

    cout << Solution().evalRPN(toks) << endl;

    return 0;
}
