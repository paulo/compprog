#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510; // maximum number of musicians
const int T = 5010; // maximum time of concert

int breaks[N];
int costs[N][T];

int main() {
    int t, n;
    cin >> t >> n;
    memset(costs, 0, T*N*sizeof(int));

    for(int i=0; i<n; i++) cin >> breaks[i];

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=t; j++) {
            if (breaks[i-1] <= j){
                // Since we want to maximize for break size, we add breaks[i-1]
                // If we wanted to maximize for number of musitians, we would add 1
                costs[i][j] = max(costs[i-1][j], costs[i-1][j-breaks[i-1]] + breaks[i-1]);
            } else costs[i][j] = costs[i-1][j];
        }
    }

    map<int, bool> res;
    t = costs[n][t];
    int xn = n;
    while(t>0){
        if(costs[n][t] != costs[n-1][t]){
            res[n-1]=true;
            t-=breaks[n-1];
        }
        n--;
    }

    int a=0, b=0;
    for(int i=0;i<xn;i++){
        if(res[i]){
            cout << a << ' ';
            a+= breaks[i];
        } else {
            cout << b << ' ';
            b+= breaks[i];
        }
    }

    return 0;
}
