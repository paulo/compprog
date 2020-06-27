#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

const int N = 50;
typedef long long ll;

ll v[N];
ll total = 0;

// Generate every combination that goes up to 200
void generate(int at, int sum, int n) {
    if(sum >= 200) return;

    if (at == n) {
        if(sum < 200) total += sum;
        return;
    } else {
        sum += v[at];
        generate(at + 1, sum, n);
        sum -= v[at];
        generate(at + 1, sum, n);
    }
}

int main() {
    int n;
    cin >> n;

    memset(v, -1, N*sizeof(int));

    ll all = 0, base = pow(2, n-1);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        all += (v[i] * base);
    }

    generate(0, 0, n);

    cout << all - total << endl;
}
