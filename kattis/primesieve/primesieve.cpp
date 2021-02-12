#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, aux, t = 0;
    cin >> n >> q;

    vector<bool> sieve(n);

    for (int i = 2; i <= n; i++) {
        if (sieve[i]) continue;

        t++;
        for (int j = i * 2; j <= n; j += i) sieve[j] = true;
    }

    cout << t << endl;

    for (int i = 0; i < q; i++) {
        cin >> aux;

        if (sieve[aux] || aux <= 1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}
