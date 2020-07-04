#include <iostream>

using namespace std;

// We could do a shortest path with the graph, but they already say that
// the graph is connected, so the minimum number of edges is vertices-1
int main() {
    int t, n, m, a, b;
    cin >> t;

    for(int k=0; k<t; k++){
        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> a >> b;
        cout << n-1 << endl;
    }

    return 0;
}
