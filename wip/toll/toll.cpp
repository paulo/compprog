#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int INF = 10000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, o;
    float k;
    cin >> k >> n >> m >> o;

    vector<vector<int>> dist(n);

    for (int i = 0; i < n; i++) {
        dist[i].resize(n - i);  // = vector<int>(n - i, 0);
    }

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (i != j) dist[i][j - i] = INF;

    // a can reach edges that are between b1= ((a/k) * k) + k  b2= ((a / k) * k)
    // + (k*2)-1
    int a, b, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        dist[a][b - a] = t;
    }

    for (int z = 0; z < n; z++)
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                // if (i > z || z > j) continue;
                if (z - i < 0 || j - z < 0) continue;
                dist[i][j - i] =
                    min(dist[i][j - i], dist[i][z - i] + dist[z][j - z]);
            }


    for (int i = 0; i < o; i++) {
        cin >> a >> b;
        // cout << a << " " << b << ": ";
        if (dist[a][b - a] == INF)
            cout << -1 << endl;
        else
            cout << dist[a][b - a] << endl;
    }

    return 0;
}
