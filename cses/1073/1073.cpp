#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, t = 0;
    cin >> n;

    multiset<int> ms;
    multiset<int>::iterator next;
    for (int i = 0; i < n; i++) {
        cin >> aux;

        next = ms.upper_bound(aux);
        if (next == ms.end()) {
            t++;
        } else {
            ms.erase(next);
        }
        ms.insert(aux);
    }

    cout << t << endl;

    return 0;
}
