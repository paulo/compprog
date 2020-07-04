#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int aux;
    for(int i = 0; i < n; i++){
        cin >> aux;
        cout << aux;
        if(aux % 2 == 0) cout << " is even";
        else cout << " is odd";
        cout << endl;
    }

    return 0;
}
