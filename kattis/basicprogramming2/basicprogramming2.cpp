#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t;

    vector<int> m(n);
    unordered_map<int, int> comp;
    bool sevens = false, dups = false;
    int lots = -1;
    vector<int> aux;
    for(int i=0; i<n; i++) {
        cin >> k;
        if(comp.find(k) != comp.end()) dups = true;
        m[i] = k;
        comp[k]++;
        if(comp[k] > n/2) lots = k;
        if(comp.find(7777-k) != comp.end()) sevens = true;
        if(k >= 100 && k <= 999) aux.push_back(k);
    }

    switch(t){
        case 1:
            if(sevens) cout << "Yes" << endl;
            else cout << "No" << endl;
            break;
        case 2:
            if(dups) cout << "Contains duplicate" << endl;
            else cout << "Unique" << endl;
            break;
        case 3:
            cout << lots << endl;
            break;
        case 4:
            sort(m.begin(), m.end());
            if(n % 2 == 0) cout << m[n/2-1] << ' ' << m[n/2] << endl;
            else cout << m[n/2] << endl;
            break;
        case 5:
            sort(aux.begin(), aux.end());
            for(auto x:aux) cout << x << ' ';
            cout << endl;
            break;
    }
}
