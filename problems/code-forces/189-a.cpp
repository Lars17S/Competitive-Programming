#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, n;
    int sol[5000];
    cin >> n >> a >> b >> c;
    
    for (int i = 0; i <= n; ++i)
        sol[i] = -1;
    sol[0] = 0;
    sol[n] = 1;
    sol[a] = 1;
    sol[b] = 1;
    sol[c] = 1;

    
    for (int i = 1; i <= n; ++i) {
        int max_a, max_b, max_c;
        max_a = max_b = max_c = -1;

        if (i >= a && (sol[i - a] != -1))
            max_a = sol[i - a] + sol[a];

        if (i >= b && (sol[i - b] != -1))
            max_b = sol[i - b] + sol[b];

        if (i >= c && (sol[i - c] != -1))
            max_c = sol[i - c] + sol[c];
        
        sol[i] = max(max(max(max_a, max_b), max_c), sol[i]);
    }

    cout << sol[n] << endl;
    return 0;
}