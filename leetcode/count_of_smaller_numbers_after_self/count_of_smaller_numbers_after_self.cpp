#include <bits/stdc++.h>

using namespace std;

class Solution {
    int offset, size;
    vector<int> tree;

   public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res = vector<int>(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = sum(0, offset + nums[i] - 1);
            inc(nums[i] + offset);
        }

        return res;
    }

    void inc(int k) {
        k += size;
        tree[k]++;
        for (k /= 2; k >= 1; k /= 2) {
            tree[k] = tree[2 * k] + tree[2 * k + 1];
        }
    }

    int sum(int a, int b) {
        a += size;  // shift the index to the leaf
        b += size;
        int s = 0;
        while (a <= b) {
            // if left is a right node
            // bring the value and move to parent's right node
            if (a % 2 == 1) s += tree[a++];
            if (b % 2 == 0) s += tree[b--];
            // if right is a right node
            // bring the value of the left node and move to parent
            a /= 2;
            b /= 2;
        }

        return s;
    }

    Solution() {
        offset = 10000;  // offset negative to non-negative
        size = offset * 2 +
               1;  // total possible values in nums (negative to non-negative)
        tree = vector<int>(2 * size);  // + the extra size for the tree
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {5, 2, 6, 1};
    // vector<int> nums = {-1, -1};

    for (auto x : Solution().countSmaller(nums)) {
        cout << x << endl;
    }

    return 0;
}
