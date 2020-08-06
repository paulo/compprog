#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, bool> m;

    int aux;
    for(int i = 0; i < 100; i++) {
        cin >> aux;
        aux = aux % 42;
        if(!m[aux]) m[aux] = true;
    }

    cout << m.size() << endl;

    return 0;
}
