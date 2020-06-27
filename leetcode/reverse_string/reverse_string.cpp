#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char aux;
        for(int i = 0; i < s.size()/2; i++) {
            aux = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = aux;
        }
    }
};

int main() {
    string s = "hello world";
    vector<char> v(s.begin(), s.end());

    Solution sol;
    sol.reverseString(v);

    for(auto x:v) cout << x;
}
