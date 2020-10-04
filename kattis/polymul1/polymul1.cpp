#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int d1, d2, aux;
    for (int i = 0; i < n; i++) {
        cin >> d1;

        vector<int> res(550, 0);
        vector<int> vi;
        for (int j = 0; j <= d1; j++) {
            cin >> aux;
            vi.push_back(aux);
        }

        cin >> d2;

        for (int j = 0; j <= d2; j++) {
            cin >> aux;
            for (int k = 0; k <= d1; k++) {
                res[d2 - j + d1 - k] += aux * vi[k];
            }
        }

        cout << d1 + d2 << endl;
        for (int j = d1 + d2; j >= 0; j--) {
            cout << res[j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
