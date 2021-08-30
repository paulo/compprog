#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

// 3
// 2 8
// 3 1
// 1 4
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int a, b, min;
    vi va, vb, vac(110, 0), vbc(110, 0), vas(100000, 0), vbs(100000, 0);
    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        va.push_back(a);
        vb.push_back(b);

        for (int j = a; j < 110; j++) vac[j]++;
        for (int j = b; j < 110; j++) vbc[j]++;

        vi vacc(vac);
        vi vbcc(vbc);

        for (int j = 0; j < i + 1; j++) {
            vas[vacc[va[j]] - 1] = va[j];
            vacc[va[j]]--;

            vbs[vbcc[vb[j]] - 1] = vb[j];
            vbcc[vb[j]]--;
        }

        min = 0;

        for (int j = 0; j < i + 1 && j < 10; j++) {
            min = max(min, vas[j] + vbs[i - j]);
        }

        cout << min << endl;
    }

    return 0;
}
