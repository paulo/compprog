#include <iostream>

using namespace std;

class Solution {
   public:
    int reverse(int x) {
        bool neg = x < 0;
        long long n = x;
        if (neg) n *= -1;

        long long acc = 0;
        long long i = pow(10, to_string(n).length() - 1);

        while (n > 0) {
            acc += (n % 10) * i;
            n -= n % 10;
            n /= 10;
            i /= 10;
        }

        acc = neg ? -acc : acc;

        if (acc > INT_MAX || acc <= INT_MIN) return 0;

        return acc;
    }
};

int main() {
    int i = -2147483648;

    Solution s = Solution();

    cout << s.reverse(i) << endl;

    return 0;
}
