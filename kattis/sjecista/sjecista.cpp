#include <iostream>

using namespace std;

// For each quadruple of vertices there are two diagonals joining opposite points of the four which intersect in the interior. We need to find how many 4-element combinations of these vertices are there
int main() {
    int n;
    cin >> n;

    // nCr(n, r) = (n!)/((r!) * ((n-r)!))
    // nC4 = n! / (4! * (n-4)!)
    // (n!)/((n-4)!) = n*(n-1)*(n-2)*(n-3)
    cout << long(n*(n-1)*(n-2)*(n-3)/24) << endl;
}
