#include <iostream>
#include <map>

using namespace std;

#define MAXN 100000

int p[MAXN];
int s[MAXN];

int find(int x) {
    if(p[x] == x) {
        return x;
    }

    return p[x] = find(p[x]);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(p[fx] != fy) {
        s[fy] += s[fx];
        s[fx] = s[fy];
    }
    p[fx] = fy;
}

int main() {
    int tcases, f;
    string fs;
    cin >> tcases;

    map<string, int> msi;
    string f1, f2;
    for(int i=0; i<tcases;i++){
        for (int i = 0; i < MAXN; i++) p[i] = i;
        for (int i = 0; i < MAXN; i++) s[i] = 1;
        msi.clear();

        cin >> f;
        int lastn = 0;

        for(int j=0; j < f; j++){
            cin >> f1 >> f2;

            if(msi[f1] == 0) msi[f1] = ++lastn;
            if(msi[f2] == 0) msi[f2] = ++lastn;

            unite(msi[f1], msi[f2]);

            cout << s[find(msi[f2])] << endl;
        }
    }

    return 0;
}
