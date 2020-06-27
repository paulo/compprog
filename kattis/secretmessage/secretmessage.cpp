#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int k, m;

    string message, full;
    char c;
    for(int i=0; i<n;i++){
        cin >> message;

        k = ceil(sqrt(message.length()));
        m = k*k;
        full = message + string(m-message.length(), '*');

        for(int j=0; j<k;j++){
            for(int g=k-1; g>=0;g--){
                c = full.at(g*k+j);
                if(c != '*'){
                    cout << c;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
