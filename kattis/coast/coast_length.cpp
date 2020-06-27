#include <iostream>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool *matrix = new bool[n*m]{false};

    char aux;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aux;
            matrix[i*m+j] = aux == '1';
        }
    }

    bool *visited = new bool[n*m];
    bool *new_matrix = new bool[n*m];

    // Let's make it all land at the beginning
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
            visited[i*m+j] = false;
	    new_matrix[i*m+j] = true;
	}
    }

    function<void(int,int)>dfs = [&] (int i, int j) {
        if(i<0 || i>=n) return;
        if(j<0 || j>=m) return;
        if(visited[m*i+j]) return;
        if(!matrix[m*i+j]){ // If it's not land, let's fix the new matrix
            new_matrix[m*i+j] = false;
            visited[m*i+j] = true;
            dfs(i-1, j);
            dfs(i+1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        }
    };

    // DFS through the initial matrix by its borders in order build a new map
    // that ignores Lakes and islands in lakes, as per requirements
    for(int j = 0; j < m; j++) dfs(0, j);
    for(int j = 0; j < m; j++) dfs(n-1, j);
    for(int i = 0; i < n; i++) dfs(i, 0);
    for(int i = 0; i < n; i++) dfs(i, m-1);

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(new_matrix[i*m+j]){
                if(i>0) {
                    if(!new_matrix[(i-1)*m+j]) total++; //up is not land
                } else total++;
                if(i<n-1) {
                    if(!new_matrix[(i+1)*m+j]) total++; //down is not land
                } else total++;
                if(j>0) {
                    if(!new_matrix[i*m+j-1]) total++; // left is not land
                } else total++;
                if(j<m-1) {
                    if(!new_matrix[i*m+j+1]) total++; // right is not land
                } else total++;
            }
        }
    }

    cout << total;

    // Note: Not dealocating the memory to save time processing time
    return 0;
}
