#include <iostream>
#include <algorithm>

using namespace std;

int N = 300; // maximum number of gallery rows (overzealous just for easier definition of multidimensional arrays)

// An alternative to the recursive functions and simpler storage is to store everything
// in these multidimensional arrays and iteratively fill them (no need for extra function
// calls to get previous state
int main() {
    int n, k;
    cin >> n >> k;

    int rows[N][2];
    for(int i=0; i<n; i++) cin >> rows[i][0] >> rows[i][1];

    // Set up DP array - dp[i][j][k] is max for row i with j rooms blocked with k being the mask for the
    // last row. k = 0 no block, k = 1 left blocked, k = 2, right blocked.
    int dp[N][N][3];

    for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<3; k++) dp[i][j][k] = -1;

    // Setting up first row (i=0)
    dp[0][0][0] = rows[0][0] + rows[0][1]; // No rooms blocked
    if(k > 0) dp[0][1][1] = rows[0][1]; // Left room blocked
    if(k > 0) dp[0][1][2] = rows[0][0]; // Right room blocked

    // Fill remaining dp rows
    for(int i = 1; i < n; i++) {
        // For each amount of rooms blocked
        for(int j = 0; j <= i+1 && j <= k; j++) {
            // Take both rooms and build off best answer on previous row with same blocked roms.
            if(*max_element(dp[i-1][j], dp[i-1][j]+3) >= 0) {
                dp[i][j][0] = rows[i][0] + rows[i][1] + *max_element(dp[i-1][j], dp[i-1][j]+3);
            }

            if(j==0) continue;
            // Have to build off no rooms blocked on prior row or the same room blocked.
            if(max(dp[i-1][j-1][1], dp[i-1][j-1][0]) > -1) {
                dp[i][j][1] = rows[i][1] + max(dp[i-1][j-1][1], dp[i-1][j-1][0]);
            }
             if(max(dp[i-1][j-1][2], dp[i-1][j-1][0]) > -1) {
                dp[i][j][2] = rows[i][0] + max(dp[i-1][j-1][2], dp[i-1][j-1][0]);
            }
        }
    }

    cout << *max_element(dp[n-1][k], dp[n-1][k]+3);

    return 0;
}
