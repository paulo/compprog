#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size() - 1]++;

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry) digits[i]++;

            if (digits[i] > 9) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carry) digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    vector<int> v{9, 9};

    vector<int> res = Solution().plusOne(v);

    for (auto x : res) {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
