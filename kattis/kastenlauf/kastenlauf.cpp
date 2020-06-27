#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;


struct loc {
    int x, y;
};

int d(loc l1, loc l2) { return abs(l2.x-l1.x) + abs(l2.y-l1.y); }

// They have twenty bottles.
// They drink one bottle every 50 metres.
bool reach[110][110];
int d_max=1000;

int main() {
    int tcases;
    cin >> tcases;

    for(int a=0; a<tcases;a++){
        int n;
        cin >> n;

        for(int i=0; i<n+2; i++) memset(reach, false, n+2);
        vector<loc> vl(n+2);
        int auxx, auxy;

        for(int j=0; j<n+2; j++) {
            cin >> auxx >> auxy;
            vl[j] = loc{auxx, auxy};
        }

        for(int j=0; j<n+2; j++) {
            for(int k=j; k<n+2; k++) {
                reach[j][k] = reach[k][j] = d(vl[j], vl[k]) > d_max ? false : true;
            }
        }

        for(int k=0; k<n+2; k++) {
            for(int i=0; i<n+2; i++) {
                for(int j=0; j<n+2; j++) {
                    if(reach[i][k] && reach[k][j]) reach[i][j] = true;
                }
            }
        }

        if(reach[0][n+1]) cout << "happy" << endl;
        else cout << "sad" << endl;
    }

    return 0;
}
