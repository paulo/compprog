#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159265

int main() {
    int h, v;
    cin >> h >> v;

    cout << int(ceil(h / sin(v * PI / 180))) << endl;

    return 0;
}
