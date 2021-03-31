#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

bool div(float a, float b, float c) {
    if (a > b)
        return a / b == c;
    else
        return b / a == c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int a, b, c;
    while (t-- > 0) {
        cin >> a >> b >> c;

        if (a + b == c || a * b == c || a - b == c || b - a == c ||
            div(a, b, c))
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}
