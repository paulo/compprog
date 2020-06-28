#include <iostream>
#include <map>

using namespace std;

int main() {
    int minx=1000, miny=1000, maxx=-1000, maxy=-1000;
    int auxx, auxy;

    map<pair<int, int>, bool> m;

    while(cin >> auxx >> auxy) {
        minx = min(minx, auxx);
        miny = min(miny, auxy);
        maxx = max(maxx, auxx);
        maxy = max(maxy, auxy);
        m[make_pair(auxx, auxy)] = true;
    }

    // try all combinations, no need to get smart
    if(!m[make_pair(minx, miny)]) { auxx = minx; auxy = miny; }
    if(!m[make_pair(maxx, miny)]) { auxx = maxx; auxy = miny; }
    if(!m[make_pair(minx, maxy)]) { auxx = minx; auxy = maxy; }
    if(!m[make_pair(maxx, maxy)]) { auxx = maxx; auxy = maxy; }

    cout << auxx << ' ' << auxy << endl;

    return 0;
}
