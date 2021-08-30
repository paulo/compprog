#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double vectorMedian(vector<int> nums) {
        if (nums.size() % 2 == 0) {
            return (nums[nums.size() / 2] + nums[nums.size() / 2 + 1]) / 2;
        }
        return nums[nums.size() / 2];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() > 0) return vectorMedian(nums2);
        if (nums2.size() == 0 && nums1.size() > 0) return vectorMedian(nums1);
        if (nums1.size() == 0 && nums2.size() == 0) return 0;

        // int medianIndex =
        // nums1.size() % 2 == 0 ? nums1.size() / 2 + 1 : nums1.size() / 2;

        int median = vectorMedian(nums1);
        int left = 0, right = nums2.size() - 1, mid;
        while (left < right) {
            mid = (right - left) / 2;

            if (nums2[mid] > median) {
                right = left - 1;
            } else if (nums2[mid] < median) {
                left = right - 1;
            } else {
                return median;
            }
        }

        if (mid == 0) {
            int index = (nums1.size() + nums2.size()) / 2 - 1;
            if ((nums1.size() + nums2.size()) % 2 == 0) {
                cout << "here" << endl;
                return (nums1[index] + nums1[index + 1]) / 2;
            } else {
                return nums1[index];
            }
        } else if (mid == nums2.size() - 1) {
        } else {
        }

        cout << median << endl;
        return 0;
    }
};

// 1 3 5 7 // med: 3+5 / 2
// 2 4 6  // med: 4
// med : 4

// 1 3 5 7 // med: 3+5 / 2
// 10 11 12  // med: 11
// med : 7

// 1 3 5 7 8 9 // med: 6
// 10 11 12  // med: 11
// med : 8

// 1 5 8 9 // med: 5+8 / 2 : 6,5
// 2 3 4 6  // med: 3,5
// med : 4,5

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
