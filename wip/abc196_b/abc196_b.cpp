#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c;
    bool allskip = false;
    while (cin >> c) {
        if (c == '.') allskip = true;

        if (!allskip) cout << c;
    }

    cout << endl;

    return 0;
}
