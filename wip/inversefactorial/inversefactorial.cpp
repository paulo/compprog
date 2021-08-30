#include <iostream>
#include <vector>

using namespace std;

// From https://www.geeksforgeeks.org/divide-large-number-represented-string/
// string longDivision(string number, int divisor) {
// string ans;

// // Find prefix of number that is larger than divisor.
// int idx = 0;
// int temp = number[idx] - '0';
// while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');

// while (number.size() > idx) {
// ans += (temp / divisor) + '0';
// temp = (temp % divisor) * 10 + number[++idx] - '0';
// }

// if (ans.length() == 0) return "0";

// return ans;
// }

// int main() {
// string n;
// cin >> n;

// string res;

// for (int i = 2; n != "1"; i++) {
// res = n;
// // n = longDivision(n, i);
// // cout << n << endl;
// }

// cout << res << endl;

// return 0;
// }

const int MAXN = 10000000000;

// From https://math.stackexchange.com/questions/661227/factorial-length
int main() {
    vector<double> v(MAXN + 1);
    int l, i;
    for (i = 1; i <= MAXN; i++) {
        v[i] = v[i - 1] + log10(i);
        l = to_string(v[i]).length();
        if (l > 1000000) break;
    }

    cout << l << endl;
    cout << i << endl;
    cout << v[i] << endl;

    // while (cin >> n) {
    // cout << int(v[n]) + 1 << endl;
    // }

    return 0;
}
