#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;

        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] == needle[j]) {
                    if (j == needle.length() - 1) return i;
                } else
                    break;
            }
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string hay = "abb", needle = "abaaa";

    cout << Solution().strStr(hay, needle) << endl;

    return 0;
}
