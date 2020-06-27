#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll total = 0;
    string s;
    int pwr;
    for(int i = 0; i < n; i++){
        cin >> s;
        pwr = atoi(&s[s.length() - 1]);
        total += pow(stoi(s.substr(0, s.length() - 1)), pwr);
    }

    cout << total << endl;
}
