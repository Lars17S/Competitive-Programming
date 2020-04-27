#include <iostream>
using namespace std;

int sol[120000] = {0};
int key_count[120000] = {0};

int main() {
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ++key_count[num];
    }

    // Build the solution
    for (int i = 1; i < 120000; ++i)
        sol[i] = key_count[i] + sol[i - 1];

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int mon;
        cin >> mon;
        // If the money he can spend is larger than the maximum price of any bottle,
        // then he can buy in any store (also avoids stack overflow in sol array)
        if (mon > 100000)
            cout << n << endl;
        else cout << sol[mon] << endl;
    }

    return 0;
}