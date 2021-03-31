#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    double t = 0, lower = 0, upper = 0, special = 0, space = 0;
    char c;
    while (cin >> c) {
        t++;
        if (c > 96 && c < 123)
            lower++;
        else if (c > 64 && c < 91)
            upper++;
        else if (c == 95)
            space++;
        else
            special++;
    }

    cout << fixed;
    cout << setprecision(10);
    cout << space / t << endl
         << lower / t << endl
         << upper / t << endl
         << special / t << endl;

    return 0;
}
