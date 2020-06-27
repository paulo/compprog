#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXT = 3600;
const int INF = 100000;
int reach[MAXT+1];

int main() {
    int n, t, tc;
    cin >> tc;

    for(int i=0; i < tc; i++) {
        cin >> n >> t;

        vector<int> buttons(n);
        for(int j=0; j < n; j++) cin >> buttons[j];
        for(int j=0; j <= MAXT; j++) reach[j] = INF;

        queue<int> q; // q stores the reacheable values
        q.push(0);
        reach[0] = 0; // reaching t = 0 costs 0 button presses

        while(!q.empty()){
            int u = q.front(); q.pop(); // reacheable time
            int r = reach[u]; // button presses to reach the reacheable time

            for (int j = 0; j < buttons.size(); j++) {
                int v = u + buttons[j]; // reacheable time by pressing button j
                v = max(0, min(v, MAXT)); // value must be within bounds
                if(reach[v] > r+1){ // if it costs more to reach v this way than the previous way, just maintain the previous way + 1
                    reach[v] = r+1;
                    q.push(v);
                }
            }
        }

        for(int j=t; j <= MAXT; j++) {
            if(reach[j] != INF) {
                cout << reach[j] << ' ' << j-t << endl;
                break;
            }
        }
    }

    return 0;
}
