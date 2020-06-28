#include <iostream>

using namespace std;

int main() {
    int n, t=0;
    while(cin >> n) if(n<0) t++;
    cout << t;

    return 0;
}
