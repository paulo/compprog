#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int next;
        for (int i = 0; i < nums.size(); i++) {
            next = i == nums.size() - 1 ? INT_MIN : nums[i + 1];

            if (nums[i] > next) return i;
        }
        return 0;
    }
};

int main() {
    vector<int> v{1, 2, 1, 3, 5, 6, 4};

    cout << Solution().findPeakElement(v) << endl;

    return 0;
}
