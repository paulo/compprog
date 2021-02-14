#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;

    while (cin >> n >> m && n != 0 && m != 0) {
        unordered_map<int, bool> mem;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            mem[aux] = true;
        }

        ll c = 0;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (mem[aux]) c++;
        }

        cout << c << endl;
    }

    return 0;
}
