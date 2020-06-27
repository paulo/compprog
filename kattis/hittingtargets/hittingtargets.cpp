#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct rectangle {
    // bottom-left, top-right
    int x1, y1, x2, y2;

    rectangle(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    }

    bool contains(int xx, int yy) {
        if(xx >= x1 && yy >= y1 && xx <= x2 && yy <= y2) return true;

        return false;
    }
};

struct circle {
    int x, y, r;

    circle(int _x, int _y, int _r) {
        x = _x;
        y = _y;
        r = _r;
    }

    bool contains(int xx, int yy) {
        return pow(double(x - xx), double(2)) + pow(double(y - yy), double(2)) <= pow(double(r), double(2));
    }
};


int main() {
    int m;
    cin >> m;

    vector<circle> cs;
    vector<rectangle> rs;

    string s;
    int x1, x2, y1, y2, r;
    for(int i = 0; i < m; i++){
        cin >> s;
        if(s == "circle") {
            cin >> x1 >> y1 >> r;
            cs.push_back(circle(x1, y1, r));
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            rs.push_back(rectangle(x1, y1, x2, y2));
        }
    }

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int total = 0;
        cin >> x1 >> y1;

        for(auto c:cs) if(c.contains(x1, y1)) total++;
        for(auto r:rs) if(r.contains(x1, y1)) total++;
        cout << total << endl;
    }
}
