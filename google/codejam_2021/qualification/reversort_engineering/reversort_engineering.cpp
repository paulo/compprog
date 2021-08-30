#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int n, c;
vi perm, v, ind, vind;
vector<bool> chosen;

int check(int k) {
    int cost = 0;
    v = perm;
    vind = ind;
    for (int i = 0; i < k - 1; i++) {
        int minind = vind[i];
        int from = i, to = minind;
        while (from < to) {
            vind[v[from]] = to;
            vind[v[to]] = from;
            swap(v[from], v[to]);
            from++;
            to--;
        }

        cost += minind - i + 1;
    }

    return cost;
}

bool search(int k) {
    int cost = check(k);
    if (cost > c) return false;

    if (k == n && cost == c) {
        for (int i = 0; i < n; i++) cout << perm[i] + 1 << ' ';
        cout << endl;
        return true;
    } else if (k < n) {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;

            int aux = perm[k];
            perm[k] = i;
            ind[i] = k;

            if (search(k + 1)) return true;
            chosen[i] = false;
            perm[k] = aux;
            ind[i] = -1;
        }
    }

    return false;
}

// NOTE: Fails the second test set
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    perm = vi(110);
    ind = vi(110);
    chosen = vector<bool>(110, false);

    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> c;

        for (int i = 0; i < n; i++) {
            perm[i] = i;
            ind[i] = i;
            chosen[i] = false;
        }

        cout << "Case #" << tt << ": ";
        if (n - 1 > c) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        if (!search(0)) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
    }

    return 0;
}


// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, c;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> n >> c;
    cout << "Case #" << T << ": ";
    if (c < n - 1 || c >= n * (n + 1) / 2) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    c -= (n - 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    int i = 0, j = n - 1, r = 0;
    for (int k = 0; k < n; k++) {
      if (c >= n - k - 1)
        reverse(a.begin() + i, a.begin() + j + 1), r = !r, c -= n - k - 1;
      if (r) j--;
      else
        i++;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
  }
}

