#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l, r, mid;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            // binary search line
            l = j, r = n;
            while (l < r) {
                mid = (l + r) / 2;
                if (matrix[i][mid] == target) return true;
                if (matrix[i][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            // binary search column
            l = i, r = m;
            while (l < r) {
                mid = (l + r) / 2;
                if (matrix[mid][j] == target) return true;
                if (matrix[mid][j] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> v{
        vector<int>{1, 4, 7, 11, 15}, vector<int>{2, 5, 8, 12, 19},
        vector<int>{3, 6, 9, 16, 22}, vector<int>{10, 13, 14, 17, 24},
        vector<int>{18, 21, 23, 26, 30}};

    cout << Solution().searchMatrix(v, 5);

    return 0;
}
