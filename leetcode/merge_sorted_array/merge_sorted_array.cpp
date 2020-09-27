#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }

        for (int i = m; i < m + n; i++) {
            int j = i;
            while (j > 0 && nums1[j] < nums1[j - 1]) {
                swap(nums1[j], nums1[j - 1]);
                j--;
            }
        }
    }
};

int main() {
    vector<int> v1{1, 2, 3, 0, 0, 0};
    vector<int> v2{2, 5, 6};

    Solution s = Solution();
    s.merge(v1, 3, v2, 3);

    for (auto x : v1) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
