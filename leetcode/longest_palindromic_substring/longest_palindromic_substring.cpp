#include <bits/stdc++.h>

using namespace std;

#define pb push_back

// From
// https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm
class Solution {
   public:
    string longestPalindrome(string s) {
        string saux = "|";
        for (auto c : s) {
            saux += c;
            saux += "|";
        }

        vector<int> radii(saux.length(), 0);
        int center = 0, radius, maxRadius = -1, maxCenter = -1;
        int oldCenter, oldRadius;

        while (center < saux.length()) {
            radius = 0;

            while (center - radius - 1 >= 0 &&
                   center + radius + 1 < saux.length() &&
                   saux[center - radius - 1] == saux[center + radius + 1]) {
                radius++;
            }

            radii[center] = radius;
            if (radius > maxRadius) {
                maxRadius = radius;
                maxCenter = center;
            }

            // try to reuse already computed results
            oldCenter = center;
            oldRadius = radius;
            center++;
            // while inside the previous palindrome
            while (center <= oldCenter + radius) {
                // mirroredCenter tracks the center backwards on the palindrome
                // as center increases, mirroredCenter decreases on the same
                // scale
                int mirroredCenter = oldCenter - (center - oldCenter);
                // maxMirroredRadius tracks the current max radius that can be
                // achieved while inside the old palindrome. As center increses,
                // radius maxMirroredRadius decreases
                int maxMirroredRadius = oldCenter + oldRadius - center;
                // when the palindrome at mirroredCenter lies completely within
                // the old palindrome...
                if (radii[mirroredCenter] < maxMirroredRadius) {
                    radii[center] = radii[mirroredCenter];
                    center++;
                }
            }
        }

        string res;
        for (int i = maxCenter - maxRadius; i < maxCenter + maxRadius; i++) {
            if (saux[i] != '|') res += saux[i];
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().longestPalindrome("babad") << endl;

    return 0;
}
