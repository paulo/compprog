#include <iostream>

using namespace std;

int main() {
    int l, n, p, current = 0, barred = 0;
    cin >> l >> n;

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s >> p;

        if (s == "enter") {
            if(current + p > l) barred ++;
            else current += p;
        } else {
            current -= p;
        }
    }

    cout << barred << endl;

    return 0;
}
