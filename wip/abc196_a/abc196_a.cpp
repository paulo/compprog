#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m = INT_MIN;
    m = max(m, a - c);
    m = max(m, a - d);
    m = max(m, b - c);
    m = max(m, b - d);

    cout << m << endl;

    return 0;
}
