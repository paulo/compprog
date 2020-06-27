#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int divisorSum(int n) {
    int t = 0;
    for (int i=1; i<=n/2; i++) if (n%i==0) t+=i;
    return t;
}

int main() {
    vector<int> abund;

    for(int i=0; i<28124; i++){
        if(divisorSum(i) > i) abund.push_back(i);
    }

    unordered_map<int, bool> combs;

    for(int i=0; i<abund.size(); i++){
        for(int j=i; j<abund.size(); j++){
            combs[abund[i] + abund[j]] = true;
        }
    }

    int total = 0;
    for(int i=1; i<28124; i++) {
        if(combs.find(i) == combs.end()) total += i;
    }

    cout << total << endl;
}
