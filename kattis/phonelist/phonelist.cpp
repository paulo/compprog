#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// This can be improved to linear execution using a tree where each node
// represents a digit and has 10 pointers to other nodes. On insertion we can
// check if we fullfil the requirement.
int main() {
    int n;
    cin >> n;

    int m;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<string> vs(m);
        for (int j = 0; j < m; j++) {
            cin >> vs[j];
        }

        sort(vs.begin(), vs.end());

        bool b = false;
        for (int j = 0; j < m - 1; j++) {
            if (vs[j] == vs[j + 1].substr(0, vs[j].size())) {
                cout << "NO" << endl;
                b = true;
                break;
            }
        }

        if (b) continue;

        cout << "YES" << endl;
    }

    return 0;
}
