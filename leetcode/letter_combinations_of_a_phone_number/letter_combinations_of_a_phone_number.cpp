#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<char, vector<char>> m = {
        {'2', vector<char>{'a', 'b', 'c'}},
        {'3', vector<char>{'d', 'e', 'f'}},
        {'4', vector<char>{'g', 'h', 'i'}},
        {'5', vector<char>{'j', 'k', 'l'}},
        {'6', vector<char>{'m', 'n', 'o'}},
        {'7', vector<char>{'p', 'q', 'r', 's'}},
        {'8', vector<char>{'t', 'u', 'v'}},
        {'9', vector<char>{'w', 'x', 'y', 'z'}},
    };

    vector<string> res;

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return res;
        comb(digits, 0, "");

        return res;
    }

    void comb(string digits, int at, string curr) {
        if (at == digits.length()) {
            res.push_back(curr);
            return;
        }

        for (char c : m[digits[at]]) {
            comb(digits, at + 1, curr + c);
        }
    }
};

int main() {
    vector<string> res = Solution().letterCombinations("23");

    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}
