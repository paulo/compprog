#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << "still running" << endl;
        return 0;
    }

    int aux, last, total = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;

        if (i % 2 != 0) {
            total += aux - last;
        }
        last = aux;
    }

    cout << total << endl;

    return 0;
}
