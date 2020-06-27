#include<iostream>
#include<unordered_map>
#include<math.h>

using namespace std;

int divisorSum(int n) {
    int t = 0;
    for (int i=1; i<=n/2; i++) if (n%i==0) t+=i;
    return t;
}

int main() {
    unordered_map<int, int> m;

    for(int i = 1; i < 10000; i++) m[i] = divisorSum(i);

    int total = 0;
    for(int i = 1; i < 10000; i++) if(i == m[m[i]] && i != m[i]) total += i;

    cout << total << endl;
}
