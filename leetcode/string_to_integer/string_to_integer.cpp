#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
   public:
    int myAtoi(string s) {
        long long int res = 0;

        int i = 0;
        for (i = 0; i < s.length(); i++)
            if (s[i] != ' ') break;

        char sign = '\0';
        if (s[i] == '+' || s[i] == '-') {
            sign = s[i];
            i++;
        }

        while (i < s.length() && s[i] == '0') i++;

        int from = i;
        while (i < s.length()) {
            if (s[i] < '0' || s[i] > '9') break;
            i++;
        }

        int to = i;

        if (from == to) return 0;

        int p = to - from - 1;
        if (p > 15) {
            if (sign == '-') return INT_MIN;
            return INT_MAX;
        }

        for (i = from; i < to; i++) {
            if (sign == '-')
                res -= ll(s[i] - 48) * powl(10, p);
            else
                res += ll(s[i] - 48) * powl(10, p);

            if (res < INT_MIN) return INT_MIN;
            if (res > INT_MAX) return INT_MAX;
            p--;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().myAtoi("   000000000012345678") << endl;

    return 0;
}
