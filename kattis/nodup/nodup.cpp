#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    unordered_map<string, bool> m;

    while (cin >> s) {
        if (m.find(s) != m.end()) {
            cout << "no" << endl;
            return 0;
        }

        m[s] = true;
    }

    cout << "yes" << endl;

    return 0;
}
