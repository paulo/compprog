#include <bits/stdc++.h>

using namespace std;

/*
Write an algorithm that returns the first non-repeated character in a string.
For example:

Input: ABCA
Output: B
Input: BCABAC
Output: null
Input: BAC
Output: B
Input: GlovoAtGlovo
Output: A
Input: What is the first non-repeated character?
Output: W
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    unordered_map<char, int> m;

    for (int i = 0; i < s.length(); i++) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 1;
        } else {
            m[s[i]]++;
        }
    }

    int res = -1;
    for (int i = 0; i < s.length(); i++) {
        if (m[s[i]] == 1) {
            res = i;
            break;
        }
    }

    if (res >= 0) {
        cout << s[res] << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}
