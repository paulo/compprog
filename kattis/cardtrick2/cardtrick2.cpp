#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, aux;

    while(t-->0) {
        cin >> n;

        deque<int> q;
        while(n > 0) {
            q.push_front(n);

            for(int i=0; i<n; i++){
                aux = q.back();
                q.pop_back();
                q.push_front(aux);
            }

            n--;
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop_front();
        }

        for(auto x:res) cout << x << ' ';
        cout << endl;
    }
}
