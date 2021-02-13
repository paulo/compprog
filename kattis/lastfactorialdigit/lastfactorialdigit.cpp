#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        aux = n;

        while (aux > 1) n *= --aux;
        cout << n % 10 << endl;
    }

    return 0;
}
