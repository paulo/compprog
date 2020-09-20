#include <iostream>

using namespace std;

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        for (int i = 0; i < 32; i++)
            if (n & (1 << i)) total++;

        return total;
    }
};

int main() {
    uint32_t i = 3;
    Solution s = Solution();
    cout << s.hammingWeight(i) << endl;

    return 0;
}
