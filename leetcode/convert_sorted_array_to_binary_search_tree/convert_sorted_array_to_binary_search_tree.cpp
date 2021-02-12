#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return divide(nums, 0, nums.size() - 1);
    }

    TreeNode *divide(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;

        int mid = left + ((right - left) / 2);
        return new TreeNode(nums[mid], divide(nums, left, mid - 1),
                            divide(nums, mid + 1, right));
    }
};

int main() {
    vector<int> v{-10, -3, 0, 5, 9};

    Solution().sortedArrayToBST(v);

    return 0;
}

