#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c;
    int i, zeros = 0;
    vii v(9);
    for (int i = 1; i < 10; i++) v[i - 1] = make_pair(0, i);
    while (cin >> c) {
        i = c - '0';
        if (i == 0) {
            zeros++;
        } else {
            v[i - 1] = make_pair(v[i - 1].first + 1, v[i - 1].second);
        }
    }

    sort(v.begin(), v.end());

    if (v[0].first == 0) {
        cout << v[0].second << endl;
        return 0;
    }

    string s = "";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < v[i].first; j++) {
            s += '0' + v[i].second;
        }

        if (v[i].first > zeros) {
            s += '0';
            break;
        }
    }

    cout << s << endl;

    return 0;
}
