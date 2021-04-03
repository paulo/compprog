#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int t = 0;

    for (int k = 1; k <= 5; k++) {
        cin >> s;
        for (int i = 0; i < int(s.length()) - 2; i++) {
            if (s[i] == 'F' && s[i + 1] == 'B' && s[i + 2] == 'I') {
                cout << k << " ";
                t++;
            }
        }
    }

    if (t == 0) cout << "HE GOT AWAY!" << endl;

    return 0;
}
