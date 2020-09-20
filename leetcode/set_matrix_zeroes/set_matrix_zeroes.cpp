#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// For an in place approach, modifying the matrix and putting flags at the start
// of each row/column can be done, with the help of an extra boolean flag
// variable to tell appart the matrix[0][0] case
class Solution {
  public:
   void setZeroes(vector<vector<int>>& matrix) {
      unordered_map<int, bool> rows, cols;

      for (int i = 0; i < matrix.size(); i++) {
         for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
               rows[i] = true;
               cols[j] = true;
            }
         }
      }

      for (int i = 0; i < matrix.size(); i++) {
         for (int j = 0; j < matrix[i].size(); j++) {
            if (rows[i] || cols[j]) {
               matrix[i][j] = 0;
            }
         }
      }
   }
};

int main() {
   vector<vector<int>> m;

   // [[1,1,1],[1,0,1],[1,1,1]]
   m.push_back(vector<int>{1, 1, 1});
   m.push_back(vector<int>{1, 0, 1});
   m.push_back(vector<int>{1, 1, 1});

   Solution s = Solution();
   s.setZeroes(m);

   for (auto row : m) {
      for (auto elem : row) {
         cout << elem << ' ';
      }
      cout << endl;
   }

   return 0;
}
