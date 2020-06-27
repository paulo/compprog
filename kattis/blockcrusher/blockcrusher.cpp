#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;

struct edge {
    int u, v;
    int weight;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<edge> adj[1500];
vector<int> p(1500, -1); // track previous when calculating cost with dijkstra
vector<int> dist(1500, INF);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();

        if (d > dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, w = adj[u][i].weight;

            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                p[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int h, w;

    char aux;
    while(cin >> h >> w && !(h==0 && w==0)) {
        vector<int> vi[h];

        for(int i=0; i < h; i++){
            vi[i] = vector<int>(w);
            for(int j=0; j < w; j++){
                cin >> aux;
                vi[i][j] = aux-48;
            }
        }

        // virtual vertex that reaches all vertices of first row
        for(int i=0; i < w; i++) adj[0].push_back(edge(0, i+1, vi[0][i]));

        // Build adjency list
        int ind=0, up, down, left, right, upl, downl, upr, downr;
        for(int i=0; i < h; i++){
            for(int j=0; j < w; j++){
                ind++;
                up = (i-1)*w+j+1;
                down = (i+1)*w+j+1;
                left = i*w+j;
                right = i*w+j+2;
                upl = (i-1)*w+j;
                upr = (i-1)*w+j+2;
                downl = (i+1)*w+j;
                downr = (i+1)*w+j+2;

                // up, down
                if(i>0) adj[ind].push_back(edge(ind, up, vi[i-1][j]));
                if(i<h-1) adj[ind].push_back(edge(ind, down, vi[i+1][j]));

                // left, right
                if(j > 0) adj[ind].push_back(edge(ind, left, vi[i][j-1]));
                if(j < w-1) adj[ind].push_back(edge(ind, right, vi[i][j+1]));

                // up, left, right
                if(i>0 && j>0) adj[ind].push_back(edge(ind, upl, vi[i-1][j-1]));
                if(i>0 && j<w-1) adj[ind].push_back(edge(ind, upr, vi[i-1][j+1]));

                // down, left, right
                if(i < h-1 && j>0) adj[ind].push_back(edge(ind, downl, vi[i+1][j-1]));
                if(i < h-1 && j<w-1) adj[ind].push_back(edge(ind, downr, vi[i+1][j+1]));
            }
        }

        // virtual vertex that reaches all vertices of last row
        for(int j=0; j < w; j++) adj[(h-1)*w+j+1].push_back(edge((h-1)*w+j+1, h*w+1, 0));

        dijkstra(0);

        vector<bool> path(h*w+2, true);
        int res = h*w+1;
        while(res != 0) {
            res = p[res];
            path[res] = false;
        }

        for(int i=0; i < h; i++){
            for(int j=0; j < w; j++){
                if(path[i*w+j+1]) cout << vi[i][j];
                else cout << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 0; i <1500; i++) adj[i].clear();
        p = vector<int>(1500, -1);
        dist = vector<int>(1500, INF);
    }
}
