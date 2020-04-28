#include <iostream>
using namespace std;

int main() {
    int m, s;
    cin >> m >> s;
    int *dig_max = new int[m];
    int *dig_min = new int[m];
    // BUILD THE MAX
    if (s < 9) {
        dig_max[0] = s;
    }
    else {
        dig_max[0] = 9;
    }
    s = s - dig_max[0];
    if (dig_max[0] == 0 && m != 1) {
        cout << "-1 -1" << endl;
        return 0;
    }
    for (int i = 1; i < m; ++i) {
        if (s < 9) {
            dig_max[i] = s;
        }
        else {
            dig_max[i] = 9;
        }
        s = s - dig_max[i];
    }
    return 0;
}