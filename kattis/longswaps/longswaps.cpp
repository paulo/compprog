#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<char> vc, orig;
    char aux;
    int i=0;

    while(cin >> noskipws >> aux && aux != ' ') {
        orig.push_back(aux);
        vc.push_back(aux);
    }

    int n;
    cin >> n;

    // If this is the case, characters can swap arround freely
    // If not, the middle n characters will be constrained
    if(n <= vc.size()/2) {
        cout << "Yes" << endl;
        return 0;
    }

    sort(vc.begin(), vc.end());

    // If the middle n characters are constrained but don't move,
    // the solution is still valid
    bool valid = true;
    for(int i=vc.size()-n; i<n; i++) {
        if(vc[i] != orig[i]){
            valid = false;
            break;
        }
    }

    if(valid) cout << "Yes" << endl;
    else cout << "No" << endl;
}
