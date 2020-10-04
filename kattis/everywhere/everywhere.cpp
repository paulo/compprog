#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> m;
        set<string> mem;
        for (int j = 0; j < m; j++) {
            cin >> s;
            mem.insert(s);
        }

        cout << mem.size() << endl;
    }

    return 0;
}
