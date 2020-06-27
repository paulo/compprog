#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, t;
    long long sum = 0, evens=0;
    cin >> n >> t;

    vector<int> m(n);
    vector<char> cs(n);
    for(int i=0; i<n; i++) {
        cin >> m[i];
        sum+=m[i];
        if(m[i] % 2 == 0) evens+=m[i];
        cs[i] = (m[i] % 26) + 97;
    }

    vector<int> aux;

    switch(t){
        case 1:
            cout << 7 << endl;
            break;
        case 2:
            if(m[0] > m[1]) cout << "Bigger" << endl;
            else if(m[0] == m[1]) cout << "Equal" << endl;
            else cout << "Smaller" << endl;
            break;
        case 3:
            aux.push_back(m[0]); aux.push_back(m[1]); aux.push_back(m[2]);
            sort(aux.begin(), aux.end());
            cout << aux[1] << endl;
            break;
        case 4:
            cout << sum << endl;
            break;
        case 5:
            cout << evens << endl;
            break;
        case 6:
            for(int j=0; j<n; j++) cout << cs[j];
            cout << endl;
            break;
        case 7:
            int ind=0;
            int cycles=0;
            while(true) {
                cycles++;
                ind = m[ind];
                if(ind < 0 || ind > n-1) {
                    cout << "Out" << endl;
                    break;
                }
                if(ind == n-1) {
                    cout << "Done" << endl;
                    break;
                }

                if(cycles > n) {
                    cout << "Cyclic" << endl;
                    break;
                }
            }
            break;
    }
}
