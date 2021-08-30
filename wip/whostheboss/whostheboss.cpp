#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

const int MAXN = 100010;

vector<int> adj[MAXN];
int counts[MAXN];

struct emp {
    int id, salary, height;
    emp(int _id, int _salary, int _height) {
        id = _id;
        salary = _salary;
        height = _height;
    }
    emp() {}
};

bool ve_compare(emp& e1, emp& e2) {
    if (e1.salary > e2.salary && e1.height >= e2.height) return true;
    if (e1.salary > e2.salary) return true;

    return false;
}

bool operator<(const emp& e1, const emp& e2) { return e1.height < e2.height; }

void dfs(int s) {
    counts[s] = 1;

    for (auto a : adj[s]) {
        dfs(a);
        counts[s] += counts[a];
    }
}

//  your boss is always at least as tall as you are.
//  your boss earns a bit more than you do.
//  your immediate boss is the person who earns the least among all the
//  employees that earn more than you and are at least as tall as you are
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, q;
    cin >> m >> q;

    unordered_map<string, int> e2i;
    unordered_map<int, string> i2e;
    vector<emp> vemp;

    string id;
    int salary, height;
    for (int i = 0; i < m; i++) {
        cin >> id >> salary >> height;
        e2i[id] = i;
        i2e[i] = id;
        vemp.push_back(emp(i, salary, height));
    }

    sort(vemp.begin(), vemp.end(), ve_compare);

    vector<int> boss(m);
    boss[vemp[0].id] = -1;

    for (int i = 1; i < m; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (vemp[i].salary < vemp[j].salary &&
                vemp[i].height <= vemp[j].height) {
                adj[vemp[j].id].pb(vemp[i].id);
                boss[vemp[i].id] = vemp[j].id;
                break;
            }
        }
    }

    dfs(vemp[0].id);

    string qe;
    for (int i = 0; i < q; i++) {
        cin >> qe;

        if (boss[e2i[qe]] == -1) {
            cout << 0 << " " << counts[e2i[qe]] - 1 << endl;
        } else {
            cout << i2e[boss[e2i[qe]]] << " " << counts[e2i[qe]] - 1 << endl;
        }
    }

    return 0;
}
