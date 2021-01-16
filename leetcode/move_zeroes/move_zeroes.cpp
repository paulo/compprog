#include <iostream>
#include <vector>

using namespace std;

// j index represents non-zero housing, i represents current index
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    vector<int> v{0, 1, 0, 3, 12};

    Solution().moveZeroes(v);

    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

    cout << endl;

    return 0;
}
