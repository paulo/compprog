#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> facts;

    int total = 1;
    for (int i = 1; i < 10; i++) {
        total *= i;
        facts[i + 48] = total;
    }

    string s;
    int sum, res = 0;
    cout << total << endl;
    for (int i = 3; i <= total * 2; i++) {
        sum = 0;
        s = to_string(i);

        for (int j = 0; j < s.length(); j++) sum += facts[s[j]];

        if (sum == i) res += i;
    }

    for (auto x : facts) {
        cout << "i: " << x.first << " v: " << x.second << endl;
    }

    cout << res << endl;
}
