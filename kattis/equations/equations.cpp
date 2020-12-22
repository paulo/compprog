#include <ctype.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

struct eq {
    int x, y, c;
    eq(int _x, int _y, int _c) {
        x = _x;
        y = _y;
        c = _c;
    }
};

int gcd(int a, int b) {
    if (b == 0) return a;
    if (b < 0) return -gcd(a, -b);
    if (a < 0) return gcd(-a, b);
    return gcd(b, a % b);
}

void pretty(int a, int b) {
    if (a % b == 0) {
        cout << a / b << endl;
        return;
    }
    int d = gcd(a, b);
    a = a / d;
    b = b / d;

    char buffer[50];
    sprintf(buffer, "%d/%d", a, b);
    cout << string(buffer) << endl;
}

// Solve using Cramer's rule: https://en.wikipedia.org/wiki/Cramer%27s_rule
void solve(eq e1, eq e2) {
    int x1 = (-e1.c * e2.y) - (e1.y * -e2.c);
    int y1 = (e1.x * -e2.c) - (-e1.c * e2.x);
    int det = (e1.x * e2.y) - (e1.y * e2.x);

    if (det) {
        pretty(x1, det);
        pretty(y1, det);

        return;
    }

    if ((e1.c != 0 && e1.x == 0 && e1.y == 0) ||
        (e2.c != 0 && e2.x == 0 && e2.y == 0)) {
        cout << "don't know" << endl << "don't know" << endl;
        return;
    }

    if (e1.x && !e1.y && !e2.x)
        pretty(-e1.c, e1.x);
    else if (e2.x && !e2.y && !e1.x)
        pretty(-e2.c, e2.x);
    else if (e2.x && !e2.y && e1.x && !e1.y && e2.x * e1.c == e1.x * e2.c)
        pretty(-e1.c, e1.x);
    else
        cout << "don't know" << endl;

    if (e1.y && !e1.x && !e2.y)
        pretty(-e1.c, e1.y);
    else if (e2.y && !e2.x && !e1.y)
        pretty(-e2.c, e2.y);
    else if (e2.y && !e2.x && e1.y && !e1.x && e2.y * e1.c == e1.y * e2.c)
        pretty(-e1.c, e1.y);
    else
        cout << "don't know" << endl;
}

eq parse(string s) {
    int x = 0, y = 0, con = 0, aux;
    int currentDigit = 0;
    bool positive = true;
    bool leftSide = true;
    bool lastWasDigit = false;

    for (char c : s) {
        if (c == ' ' || c == '\n') continue;

        if (isdigit(c)) {
            aux = c - 48;
            currentDigit = currentDigit * 10;
            currentDigit = abs(currentDigit) + aux;
            currentDigit = ((positive && leftSide) || (!positive && !leftSide))
                               ? currentDigit
                               : -currentDigit;
            lastWasDigit = true;
        }

        if (c == '=') {
            leftSide = false;
            positive = true;
            con += currentDigit;
            currentDigit = 0;
            lastWasDigit = false;
        }

        if (c == '+') {
            con += currentDigit;
            positive = true;
            currentDigit = 0;
            lastWasDigit = false;
        }

        if (c == '-') {
            con += currentDigit;
            positive = lastWasDigit
                           ? false
                           : !positive;  // handle - after a negative digit
            currentDigit = 0;
            lastWasDigit = false;
        }

        if (c == 'x') {
            if (currentDigit) {
                x += currentDigit;
            } else {
                if ((positive && leftSide) || (!positive && !leftSide))
                    x += 1;
                else
                    x -= 1;
            }

            positive = true;
            currentDigit = 0;
            lastWasDigit = false;
        }

        if (c == 'y') {
            if (currentDigit) {
                y += currentDigit;
            } else {
                if ((positive && leftSide) || (!positive && !leftSide))
                    y += 1;
                else
                    y -= 1;
            }

            positive = true;
            currentDigit = 0;
            lastWasDigit = false;
        }
    }

    if (currentDigit) con += currentDigit;

    return eq(x, y, con);
}

int main() {
    int t;
    cin >> t;

    string s1, s2;
    getline(cin, s1);
    for (int i = 0; i < t; i++) {
        getline(cin, s1);
        getline(cin, s2);

        eq e1 = parse(s1);
        eq e2 = parse(s2);

        solve(e1, e2);
        cout << endl;

        getline(cin, s1);  // consume empty line
    }

    return 0;
}
