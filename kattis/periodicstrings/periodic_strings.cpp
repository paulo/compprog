#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int k = 1;
    while (k < int(s.length())) {
        if (int(s.length()) % k != 0) {
            k++;
            continue;
        }

        string sub = s.substr(0, k);

        bool valid = true;
        for (int i = 0; i < int(s.length()) / k && valid; i++) {
            for (int j = 0; j < k; j++) {
                if (s[i * k + j] != sub[j]) valid = false;
            }

            sub.insert(0, 1, sub[int(sub.length()) - 1]);
            sub.pop_back();
        }

        if (valid) break;
        k++;
    }

    cout << k << endl;

    return 0;
}
