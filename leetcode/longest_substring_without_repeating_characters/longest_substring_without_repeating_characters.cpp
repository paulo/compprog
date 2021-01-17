#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;  // m tracks past characters
        int best = 0;

        // i is the index of the beginning of the string, j of the ending
        for (int i = 0, j = 0; j < s.length(); j++) {
            // character already exists, move sliding window to the right
            if (m.find(s[j]) != m.end() && m[s[j]] >= i) i = m[s[j]] + 1;
            m[s[j]] = j;
            best = max(j - i + 1, best);
        }

        return best;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring("abba") << endl;

    return 0;
}
