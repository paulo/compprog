#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        s.insert(aux);
    }

    cout << s.size() << endl;
    return 0;
}
