#include <iostream>

using namespace std;

int main(){
    string s;
    int guess = 500, high=1001, low=1;

    cout << guess << endl << flush;

    while(cin >> s && s != "correct") {
        if(s == "lower") high = guess;
        else low = guess;

        guess = (low+high)/2;
        cout << guess << endl << flush;
    }
}
