#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> pent;
    unordered_map<int, bool> isPent;

    int aux;
    for(int i = 1; i < 10000; i++) {
        aux = i*(3*i - 1)/2;
        pent.push_back(aux);
        isPent[aux] = true;
    }

    int m = 1000000000;
    for(int i = 0; i < pent.size()-1; i++) {
        for(int j=i+1; j < pent.size(); j++){
            if(isPent.find(pent[i] + pent[j]) == isPent.end()) continue;
            if(isPent.find(abs(pent[i] - pent[j])) == isPent.end()) continue;

            m = min(m, abs(pent[i] - pent[j]));
        }
    }

    cout << m << endl;
}
