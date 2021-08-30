#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<char> reverseWords(const vector<char>& arr) {
    vector<char> res(arr.size());
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        res[i] = arr[n - 1 - i];
    }

    int lastI = 0;
    for (int i = 0; i < n; i++) {
        if (res[i] == ' ') {
            for (int j = lastI, k = i - 1; j < k; j++, k--) {
                swap(res[j], res[k]);
            }
            lastI = i + 1;
        }
    }

    for (int j = lastI, k = n - 1; j < k; j++, k--) {
        swap(res[j], res[k]);
    }

    return res;
}

int main() {
    vector<char> arr = {'p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k',
                        'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};

    for (auto x : arr) cout << x << " ";
    cout << endl;

    for (auto x : reverseWords(arr)) cout << x << " ";
    cout << endl;

    return 0;
}
