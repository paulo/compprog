#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < int(s.length()); i++) {
            s[i] = tolower(s[i]);
        }
        if (s.find("problem") != string::npos)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
