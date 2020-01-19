//  Codeforces https://codeforces.com/problemset/problem/1288/A - Deadline

#include <iostream>
using namespace std;

int main() {
    short T;
    int n, d;
    cin >> T;
    for (short i = 0; i < T; i++) {
        cin >> n >> d;
        if (((long long)(1 - n)*(1 - n) - 4 * (long long)(d - n)) >= 0)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

/*  Answer:
    Let n >= 1, d >= 1, x >= 0
    Identity k <= ceil(k) < k + 1

    We have x + d/(x + 1) <= x + ceil(d/(x + 1)) and x + ceil(d/(x + 1)) <= n
    to satisfy the solution YES
    If we combine the two inequalities we will get:
        x + d/(x + 1) <= n  ->
        x^2 + x(1 - n) + (d - n) <= 0   a = 1, b = 1 - n, c = d - n
    Let f = x^2 + x(1 - n) + (d - n), then to satisfy "YES" f must satisfy 
    f < 0 or f = 0.
    Let D = (1 - n)^2 - 4(d - n) the discriminant of f. If D < 0, then 
    f != 0 and we will have that f > 0 because 0 <= (a = 1) for every x.

    Therefore if D < 0, then it is impossible to satisfy "YES".
    */