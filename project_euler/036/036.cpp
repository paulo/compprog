#include<iostream>
#include<stdlib.h>

using namespace std;

string decToBinary(int n) {
    string s;
    char aux;

    while (n > 0) {
        aux = (n % 2) + 48;
        n = n / 2;
        s = aux + s;
    }

    return s;
}

bool palindrome(string s) {
    for(int i=0; i<=s.length()/2; i++) {
        if(s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}


int main() {
    int t = 0;

    string aux;
    for(int i=1; i<1000000; i++){
        aux = to_string(i);

        if(palindrome(aux) && palindrome(decToBinary(i))) t += i;
    }

    cout << t << endl;
}
