#include <iostream>

using namespace std;

class Solution {
    int m[26];

   public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i] - 97] == -2) continue;
            if (m[s[i] - 97] >= 0) m[s[i] - 97] = -2;
            if (m[s[i] - 97] == -1) m[s[i] - 97] = i;
        }

        int res = s.size();
        for (int i = 0; i < 26; i++) {
            if (m[i] >= 0) res = min(res, m[i]);
        }

        return res < s.size() ? res : -1;
    }

    Solution() { memset(m, -1, 26 * sizeof(int)); }
};

int main() {
    cout << Solution().firstUniqChar(
                "itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiih"
                "ervpncztuoljftlxybpgwnjb")
         << endl;

    return 0;
}
