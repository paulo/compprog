#include <iostream>

using namespace std;

const int INF = 999999999;

int main() {
    int n, b, h, w;
    cin >> n >> b >> h >> w;

    int price, minCost = INF;
    for (int i = 0; i < h; i++) {
        cin >> price;

        int avail = 0, aux;
        for (int j = 0; j < w; j++) {
            cin >> aux;
            avail = max(avail, aux);
        }

        if (price * n <= b && avail >= n) {
            minCost = min(price * n, minCost);
        }
    }

    if (minCost != INF) {
        cout << minCost << endl;
    } else {
        cout << "stay home" << endl;
    }

    return 0;
}
