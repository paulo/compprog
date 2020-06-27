#include <iostream>
#include <set>
#include <string>

using namespace std;

// 10 3
// 1 4 8
//
// 1 2 3 4 6 7 8 9 10

int main() {
    int w, p;

    // Take size and partitions
    cin >> w >> p;

    int parts[p+2];
    set <int> diffComb;

    // Pre-insert edges
    parts[0] = 0;
    parts[p+1] = w;

    // Consume partitions
    for (int i = 1; i < p+1; i++){
       cin >> parts[i];
    }

    for (int i = p+1; i >= 0; i--){
        for (int j = i-1; j>=0; j--){
            diffComb.insert(parts[i]-parts[j]);
        }
    }

    for (int const pi: diffComb){
        cout << pi << ' ';
    }

    return 0;
}
