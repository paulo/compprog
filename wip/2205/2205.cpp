#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<string> res;

bool compare(string s1, string s2) {
    int c = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) c++;
    }

    return c <= 1;
}

void backtrack(string s, int i, int n) {
    if (i < 0) {
        res.pb(s);
        // cout << s << endl;
        return;
    }
    backtrack(s, i - 1, n);
    s[i] = '1';
    backtrack(s, i - 1, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s = string(n, '0');
    // cout << s << endl;
    backtrack(s, n - 1, n);
    sort(res.begin(), res.end(), compare);

    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}
