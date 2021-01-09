#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        for (char c : s) m[c]++;
        for (char c : t) m[c]--;
        for (auto x : m)
            if (x.second != 0) return false;

        return true;
    }
};

int main() {
    string s = "anagram", t = "nagaram";

    cout << Solution().isAnagram(s, t) << endl;

    return 0;
}
