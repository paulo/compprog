#include <iostream>
#include <vector>

using namespace std;

const int N = 1000;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<bool> d1(N), d2(N);
    int i = 0;
    while(i < N) {
        for(int j = 0; j < a; j++) d1[i+j] = true;
        i+=a+b;
    }

    i = 0;
    while(i < N) {
        for(int j = 0; j < c; j++) d2[i+j] = true;
        i+=c+d;
    }

    int h;
    for(int i = 0; i < 3; i++) {
        cin >> h;

        if(d1[h-1] && d2[h-1]) cout << "both" << endl;
        else if(d1[h-1] || d2[h-1]) cout << "one" << endl;
        else cout << "none" << endl;
    }
}
