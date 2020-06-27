#include <iostream>
#include <map>
#include <stack>

using namespace std;

map<int, int> m = {
    {0, 0},
    {1, 1},
    {10, 2},
    {11, 3},
    {100, 4},
    {101, 5},
    {110, 6},
    {111, 7},
};

int main() {
    string s, aux;
    cin >> s;

    while(!(s.length() % 3 == 0)) s = "0" + s;

    stack<int> res;
    int i = s.length();
    while(i-3>=0){
        aux = s.substr(i-3, 3);
        res.push(m[stoi(aux)]);
        i-=3;
    }

    while(!res.empty()) {
        cout << res.top();
        res.pop();
    }
    cout << endl;
}
