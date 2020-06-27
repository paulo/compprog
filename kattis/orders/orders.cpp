#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string IMP = "Impossible";
string AMB = "Ambiguous";

const int M = 41100;
int mem[M];

int main() {
    int n, m;

    cin >> n;
    vector<int> cost(n);
    for(int i=0; i<n; i++) cin >> cost[i];

    cin >> m;
    vector<int> order(m);
    for(int i=0; i<m; i++) cin >> order[i];

    memset(mem, -1, M*sizeof(int));

    for(int i=0; i<n; i++){
        for(int j=0; j<*max_element(begin(order), end(order))+1; j++){
            if(mem[j] == -1) {
                if(j%cost[i] == 0) mem[j] = i;
                continue;
            }

            if(mem[j] == -2) {
                mem[j+cost[i]] = -2;
                continue;
            }

            if(mem[j+cost[i]] == -1) mem[j+cost[i]] = i;
            else mem[j+cost[i]] = -2;
        }
    }

    for(int i=0; i<m; i++){
        int r = mem[order[i]];
        if(r==-1) {
            cout << IMP << endl;
        } else if (r==-2) {
            cout << AMB << endl;
        } else {
            int ox = order[i];
            vector<int> res;

            while(ox>0){
                res.push_back(mem[ox]);
                ox-=cost[mem[ox]];
            }
            if(ox<0) {
                cout << AMB << endl;
            } else {
                for(int k=0; k<res.size(); k++) cout << res[k] + 1 << ' ';
                cout << endl;
            }
        }
    }

    return 0;
}
