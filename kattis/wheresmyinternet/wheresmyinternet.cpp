#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 400000

int p[MAXN];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx > fy) p[fx] = fy;
    else p[fy] = fx;
}

int main() {
    int m, h1, h2;
    long n;
    cin >> n >> m;

    for (int i = 0; i < MAXN; i++) p[i] = i;

    for(int i=0; i<m;i++){
        cin >> h1 >> h2;

        unite(h1, h2);
    }

    bool conn = true;

    for(int j=1; j<=n; j++){
        if(p[find(j)] > 1) {
            cout << j << endl;
            conn = false;
        }
    }

    if(conn) cout << "Connected";

    return 0;
}
