#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, t, a, b, c, t0;
    cin >> n >> t >> a >> b >> c >> t0;


    map<ll,ll> mll;
    vector<pair<ll,ll>> vll;
    vll.push_back(make_pair(t0, 0));
    mll[t0] = 0;

    ll aux, mxx = 1, cycle = -1;
    for(int i = 1; i < n; i++) {
        aux = (a * vll[i-1].first + b) % c + 1;
        if(mll.find(aux) != mll.end()){
            cycle = mll[aux];
            break;
        } else {
            mxx = i;
            mll[aux] = i;
            vll.push_back(make_pair(aux, i));
        }
    }

    vector<pair<int, int>> cyc;
    if(cycle != -1){
        for(int i = cycle; i < n; i++) cyc.push_back(vll[i]);
    }

    // for(int i = 0; i < n; i++) cout << vll[i] << ' ';
    // cout << endl;

    sort(vll.begin(), vll.end());
    sort(cyc.begin(), cyc.end());

    ll totalT = 0, totalP = 0, sum = 0, ptime;
    if(cycle == -1) {
        for(int i = 0; i < vll.size() && totalP < n; i++) {
            ptime = vll[i].first;
            if(sum+ptime > t) {
                break;
            }

            sum += ptime;
            totalT = (totalT + sum) % 1000000007;
            totalP++;
        }
    } else {
        for(int i = 0; i < cycle && totalP < n; i++) {
            ptime = vll[i].first;
            if(sum+ptime > t) {
                break;
            }

            sum += ptime;
            totalT = (totalT + sum) % 1000000007;
            totalP++;
        }

        for(int i = 0; i < cyc.size() && totalP < n; i++) {
            ptime = cycle[i].first;
            if(sum+ptime > t) {
                break;
            }

            sum += ptime;
            totalT = (totalT + sum) % 1000000007;
            totalP++;
            if(i==c)
        }



    }

    cout << totalP << ' ' << totalT << endl;

    return 0;
}
