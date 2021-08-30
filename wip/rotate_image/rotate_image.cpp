#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int ms = matrix.size();

        for (int i = 0; i < ms; i++) {
            for (int j = i; j < ms; j++) {
                swap(matrix[i][j], matrix[j][ms - i - 1]);
                // swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

// 0 - 0 | 0 - 2
// 0 - 1 | 1 - 2
// 0 - 2 | 2 - 2
// 1 - 0 | 0 - 1
// 1 - 1 | 1 - 1
// 1 - 2 | 2 - 1
// 2 - 0 | 0 - 0
// 2 - 1 | 1 - 0
// 2 - 2 | 2 - 0

int main() {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s = Solution();

    s.rotate(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
