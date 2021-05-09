#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string s = countAndSay(n - 1), res = "";
        char last = -1;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != last && last != -1) {
                res += to_string(count) + last;
                count = 0;
            }

            last = s[i];
            count++;
        }

        res += to_string(count) + last;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().countAndSay(4) << endl;

    return 0;
}
