#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
 
short den[5] = {1, 5, 10, 20, 100};
 
int sol(int n, int val) {
    if (n == 0) 
        return val;
 
    int ignore_den = sol(n - 1, val);
    int use_den = (val < den[n]) ? INT_MAX : val / den[n] + sol(n - 1, val % den[n]);
    return min(ignore_den, use_den);
}
 
int main() {
    int val;
    cin >> val;
    cout << sol(4, val);
    return 0;
}