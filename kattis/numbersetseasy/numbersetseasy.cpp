#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const ll MAXN = 100000000;
ll parent[MAXN];

struct union_find {
    ll c;
    union_find(ll n) {
        for (ll i = 0; i < n; i++) parent[i] = i;
        c = n;
    }

    ll find(ll x) {
        if (parent[x] == x) {
            return x;
        } else if (parent[x] == -1) {
            parent[x] = x;
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unite(ll x, ll y) {
        ll px = find(x);
        ll py = find(y);

        if (px != py) c--;
        parent[px] = py;
    }
};

ll primes[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
               43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
               103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
               173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
               241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
               317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
               401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
               479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
               571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
               647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
               739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
               827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
               919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int main() {
    int t;
    cin >> t;

    ll a, b, p, prime;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> p;

        union_find uf(b - a + 1);
        for (ll j = a; j <= b; j++) {
            for (ll k = j + 1; k <= b; k++) {
                for (int y = 0;
                     y < sizeof(primes) / sizeof(ll) && primes[y] < j; y++) {
                    prime = primes[y];
                    if (prime < p) continue;
                    if (j % prime == 0 && k % prime == 0) {
                        uf.unite(j - a, k - a);
                        break;
                    }
                }
            }
        }

        cout << "Case #" << i << ": " << uf.c << endl;
    }

    return 0;
}
