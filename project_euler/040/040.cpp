#include<iostream>

using namespace std;

int main() {
    long long total = 1, count = 0;
    string s;
    int next=1;
    for(int i = 1; i < 1000000; i++) {
        s = to_string(i);
        count += s.length();
        if(count >= next) {
            total *= (s[s.length()- (count-next+1)] - 48);
            next*=10;
        }
    }

    cout << total << endl;
}
