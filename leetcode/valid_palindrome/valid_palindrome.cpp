#include <iostream>

using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            char a = tolower(s[i]);
            char b = tolower(s[j]);
            // Could've checked for their ascii value, but boring
            if (!isalnum(a)) {
                j++;
            } else if (!isalnum(b)) {
                i--;
            } else if (a != b)
                return false;
        }

        return true;
    }
};

int main() {
    string pal = "0P";

    Solution s = Solution();

    cout << s.isPalindrome(pal) << endl;

    return 0;
}
