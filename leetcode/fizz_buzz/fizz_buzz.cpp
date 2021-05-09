#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res[i - 1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                res[i - 1] = "Fizz";
            } else if (i % 5 == 0) {
                res[i - 1] = "Buzz";
            } else {
                res[i - 1] = to_string(i);
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (auto x : Solution().fizzBuzz(15)) {
        cout << x << endl;
    }

    return 0;
}
