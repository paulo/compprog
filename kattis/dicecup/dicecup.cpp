#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int pos[400];
    memset(pos, 0, 400*sizeof(int));

    int maxTimes = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pos[i+j]++;
            maxTimes = max(pos[i+j], maxTimes);

        }
    }

    for(int i = 0; i < 400; i++) if(pos[i] == maxTimes) cout << i << endl;

    return 0;
}
