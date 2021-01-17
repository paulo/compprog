#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for (string s : strs) {
            m[hsh(s)].push_back(s);
        }

        vector<vector<string>> r;
        for (auto x : m) r.push_back(x.second);

        return r;
    }

    // Solution 1: hsh hashes a string by counting the number of times a
    // character appears and transforming it into a string
    // Solution 1: hsh counts the value of the characters in the string and
    // returns it with the size of the string. It saves up on hashing relative
    // to the first solution, but requires a map instead of an unordered_map.
    // Even here, there's still risk of collision
    string hsh(string s) {
        int count[26];
        memset(count, 0, sizeof(int) * 26);

        for (auto c : s) count[c - 'a']++;
        string r = "";

        for (int i = 0; i < 26; i++) r += "#" + to_string(count[i]);

        return r;
    }
};

int main() {
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution().groupAnagrams(v);

    return 0;
}
