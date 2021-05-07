#include <bits/stdc++.h>

using namespace std;

#define pb push_back

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second == p2.second) return p1.first > p2.first;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<pair<int, int>, decltype(compare)*> movies(compare);

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies.insert({a, b});
    }

    int end = -1, count = 0;
    for (auto m : movies) {
        if (m.first >= end) {
            count++;
            end = m.second;
        }
    }

    cout << count << endl;

    return 0;
}
