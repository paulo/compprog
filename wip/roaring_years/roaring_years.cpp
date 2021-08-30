#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string solve(string s, int n) {
    int nn = n;
    string aux = s, aux2;
    int i;
    while (true) {
        cout << "round" << endl;
        ll x = stoll(aux.substr(0, nn));
        ll y;

        // TODO: Edge case for when last digit is 9
        for (i = nn; i < aux.size(); i += nn) {
            y = x + 1;
            x = y;
            aux2 = to_string(y);
            for (int j = 0; j < aux2.length(); j++) {
                aux[j + i] = aux2[j];
            }
        }
        cout << "aux: " << aux << endl;

        if (stoll(aux) >= stoll(s) && i == aux.size()) {
            cout << "here " << stoll(s) << " " << stoll(aux) << endl;
            return aux;
        } else {
            // increment first section
            x = stoll(s.substr(0, nn));
            cout << "x: " << x << endl;
            y = x + 1;
            aux2 = to_string(y);
            // if (aux2.size() > nn) { // TODO
            // nn++;
            // aux = " " + aux;
            // }

            for (int j = 0; j < aux2.length(); j++) {
                aux[j] = aux2[j];
            }

            // if (aux[nn - 1] != '9') {  // TODO: increment according to nn
            // aux[nn - 1] = aux[0] + 1;
            // } else {
            // aux[0] = '1';
            // aux = aux + "0";
            // }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string s;
    for (int tt = 1; tt <= t; tt++) {
        cin >> s;

        ll n = stoll(s);
        n++;
        s = to_string(n);

        ll m = LLONG_MAX;
        string res;
        cout << s << endl;
        for (int i = 1; i + i <= s.length(); i++) {
            res = solve(s, 1);
            cout << res << endl;
            m = min(m, stoll(res));
        }

        cout << "Case #" << tt << ": " << to_string(m) << endl;
    }

    return 0;
}
