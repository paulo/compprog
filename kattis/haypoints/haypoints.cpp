#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    unordered_map<string, int> dic;

    string s;
    int val;
    for(int i = 0; i < m; i++) {
        cin >> s >> val;
        dic[s] = val;
    }

    for(int i = 0; i < n; i++) {
        int total = 0;
        while(cin >> s && s != ".") {
            if(dic.find(s) != dic.end()){
                total += dic[s];
            }
        }
        cout << total << endl;
    }

    return 0;
}
