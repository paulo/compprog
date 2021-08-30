#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    double p[4];
    for (int i = 0; i < 4; i++) cin >> p[i];
    char let[4] = {'A', 'B', 'C', 'D'};

    cout << fixed;
    cout << setprecision(10);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << let[i] << ' ' << let[j] << ' ' << p[i] * p[j] << endl;
        }
    }

    return 0;
}
