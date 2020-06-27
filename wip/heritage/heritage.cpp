#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

map<string, ll> msi;
vector<pair<string,int>> vs;
string name;

struct comp {
    bool operator() (const pair<string, ll>& s1, const pair<string,ll>& s2) const {
        return s1.first.length() + s1.second < s2.first.length() + s2.second;
    }
};


int main() {
    ll n, pnv;
    cin >> n >> name;

    vector<vector<ll>> m(50, vector<ll>(50,0));

    string pn;
    string::size_type aux;
    for(int i=0; i<n; i++) {
        cin >> pn >> pnv;

        msi[pn] = pnv;

        aux = name.find(pn);
        while(aux != string::npos) {
            vs.push_back(make_pair(pn, aux));
            aux = name.find(pn, aux+pn.size());
        }
    }

    sort(vs.begin(), vs.end(), comp());

    string dic;
    ll begi, dl, end, value;
    m[0][vs[0].second + vs[0].first.length()-1] = msi[vs[0].first];
    for(int i=1; i < vs.size(); i++) {
        begi = vs[i].second;
        dic = vs[i].first;
        value = msi[dic];
        dl = dic.length();
        end = begi + dl - 1;

        cout << dic << endl;

        for(int j=0; j < name.size(); j++) {
            if(j==begi){
                if(j > 0 && m[i-1][j-1] != 0) {
                    m[i][end] = m[i-1][j-1] * value + m[i-1][end];
                }
                m[i][begi] = m[i-1][begi] != 0 ? m[i-1][begi] : 0;
            } else if(j==end && begi == 0) {
                m[i][j] = value;
                // if(m[i][j]==0 && m[i-1][j] == 0) m[i][j] = value;
                // if(m[i][j]==0 && m[i-1][j] != 0) m[i][j] = m[i-1][j];
                // if(m[i][j]!=0 && m[i-1][j] == 0) m[i][j] = m[i-1][j];
                // else m[i][j] = value + m[i-1][j];
            } else m[i][j] = m[i-1][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < name.size(); j++){
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    cout << m[n-1][ll(name.size())-1] % 1000000007 << endl;

    return 0;
}
