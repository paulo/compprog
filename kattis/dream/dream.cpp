#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

map<string, int> msi;
map<int, string> mis;
int current = 0;

int main() {
    int n; // number of events
    cin >> n;

    char et;
    string ev;
    int d, jad, mx;
    bool happened, flag;
    for(int i = 0; i < n; i++) {
        cin >> et;

        switch(et) {
            case 'E':
                cin >> ev;
                mis[current] = ev;
                msi[ev] = current++;
                break;
            case 'D':
                cin >> d;
                for(int g=0; g < d; g++){
                    ev = mis[current-1-g];
                    mis.erase(current-1-g);
                    msi.erase(ev);
                }
                current -= d;
                break;
            case 'S':
                cin >> d;
                jad = current; mx = -1; flag = false;

                for(int k=0; k<d; k++) {
                    cin >> ev;
                    if(flag) continue;
                    happened = ev[0] != '!';

                    if(!happened) ev.erase(0, 1);
                    if(happened && msi.find(ev) == msi.end()) {
                        flag = true; continue;
                    }
                    if(happened && mx < msi[ev]) mx = msi[ev];
                    if(!happened && msi.find(ev) != msi.end()) {
                        if(msi[ev] < jad) jad = msi[ev];
                        continue;
                    }
                }

                if(!flag && jad == current) cout << "Yes" << endl;
                else if (flag || jad <= mx) cout << "Plot Error" << endl;
                else cout << current - jad << " Just A Dream" << endl;

                break;
        }
    }

    return 0;
}
