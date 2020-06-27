#include <iostream>

using namespace std;

int main() {
    int e, f, c;
    cin >> e >> f >> c;

    int total = 0, aux = e + f, newb;
    while(aux >= c) {
        newb = aux / c;
        total += newb;
        aux = newb + (aux % c);
    }

    cout << total << endl;
}
