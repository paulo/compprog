#include <math.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string s, p, m;
    int x, d;

    unordered_map<char, int> mp, ms, mres;
    while (cin >> x && x != 0) {
        cin >> s >> p >> m;
        cout << m << endl;

        for (int i = 0; i < s.size(); i++) ms[s[i]] = i;
        for (int i = 0; i < p.size(); i++) mp[p[i]] = i;

        vector<char> c(m.size());

        d = (int)(pow(m.size(), 1.5) + x) % m.size();

        for (int i = 0; i < m.size(); i++) {
            if (i == d) {
                c[i] = s[mp[m[i]]];
            } else {
                int index = mp[m[i]] ^ ms[m[(i + 1) % m.size()]];
                c[i] = s[index];
            }
        }

        string res = string(c.begin(), c.end());
        cout << res << endl;

        for (int i = 0; i < res.size(); i++) mres[res[i]] = i;
        vector<char> c2(m.size());

        for (int i = 0; i < res.size(); i++) {
            if (i == d) {
                c2[i] = p[ms[c[i]]];
            } else {
                int ci = ms[c[i]];  // index
                bool doo = true;
                int j = 0;

                cout << "index: " << ci << endl;
                for (; j < p.size() && doo; j++) {
                    for (int k = 0; k < s.size(); k++) {
                        if (ci == (j ^ k) && p[j] && s[j + 1]) {
                            doo = false;
                            cout << "here:" << ' ' << j << ' ' << k << endl;
                            break;
                        }
                    }
                }
                c2[i] = m[j];
            }
        }

        res = string(c2.begin(), c2.end());
        cout << res << endl << endl;
    }

    return 0;
}
