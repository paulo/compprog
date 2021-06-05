#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int maxA = -1, auxArea;
        while (i < j) {
            auxArea = (j - i) * min(height[i], height[j]);
            if (auxArea > maxA) {
                maxA = auxArea;
            }

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxA;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << Solution().maxArea(v) << endl;

    return 0;
}
