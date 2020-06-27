#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string n, cp;
    vector<string> res;
    cin >> n;

    cp = n;

    sort(cp.begin(), cp.end());

    do {
        if(cp > n) res.push_back(cp);
    } while ( next_permutation(cp.begin(),cp.end()) );

    sort(res.begin(), res.end());

    if(res.size() != 0) cout << res[0] << endl;
    else cout << 0 << endl;
}
