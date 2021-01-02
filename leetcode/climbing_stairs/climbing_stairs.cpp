#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> m;

   public:
    int climbStairs(int n) { return climb(n, 0); }

    int climb(int n, int curr) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        if (m.find(n) != m.end()) {
            return m[n];
        }

        m[n] = climb(n - 1, curr + 1) + climb(n - 2, curr + 2);

        return m[n];
    }

    Solution() { m = unordered_map<int, int>(); }
};

int main() {
    cout << Solution().climbStairs(44) << endl;

    return 0;
}
