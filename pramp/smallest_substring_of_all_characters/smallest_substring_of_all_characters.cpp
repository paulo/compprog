#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//    |
// xyyzyzyx
//        |
// xyz
// 000 -> 0
// 100 -> 4
//
// 242    3

string getShortestUniqueSubstring(const vector<char>& arr, const string& str) {
    unordered_map<char, int> m;
    for (auto c : arr) m[c] = 0;

    int missing = arr.size();
    int windowStart = 0;
    string shortest = "";

    char c;
    for (int i = 0; i < str.length(); i++) {
        c = str[i];

        if (m.find(c) == m.end()) continue;

        if (m[c] == 0) {
            if (missing == arr.size()) windowStart = i;

            missing--;
        }

        m[c]++;

        while (missing == 0) {
            if (shortest == "" || i - windowStart < shortest.length()) {
                shortest = str.substr(windowStart, i - windowStart + 1);
            }

            m[str[windowStart]]--;
            if (m[str[windowStart]] == 0) missing++;
            windowStart++;

            while (m.find(str[windowStart]) == m.end()) windowStart++;
        }
    }

    return shortest;
}

int main() {
    vector<char> arr = {'x', 'y', 'z'};
    cout << getShortestUniqueSubstring(arr, "xyyzyzyx") << endl;
    return 0;
}
