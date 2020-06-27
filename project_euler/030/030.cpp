#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

const int POWER = 5;

int main() {
    ll maxn = pow(9, POWER)*10; // limiting to 10 digit numbers
    ll total = 0;

    string s;
    for(int i = 10; i < maxn; i++) {
        s = to_string(i);

        ll aux=0;
        for(int j=0; j<s.length(); j++) aux+=pow(s[j]-48, POWER);
        if(aux==i) total += i;
    }

    cout << total << endl;
}
