#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int r, e, c;
    for (int i=0; i <n; i++) {
        cin >> r >> e >> c;

        if(r + c == e) {
            cout << "does not matter" << endl;
        } else if(r + c < e) {
            cout << "advertise" << endl;
        } else {
            cout << "do not advertise" << endl;
        }
    }

    return 0;
}
