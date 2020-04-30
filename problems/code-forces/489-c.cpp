#include <iostream>
using namespace std;

int main() {
    short m, s;
    cin >> m >> s;
    short* dig_max = new short[m]();
    short* dig_min = new short[m]();

    if ((m > 1 && s == 0) || (s > m * 9)) {
        cout << "-1 -1" << endl;
        return 0;
    }
    if (m == 1 && s == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    short dig_index = 0;
    dig_min[0] = dig_max[0] = 1;

    for (short i = 1; i < s; ++i) {
        ++dig_max[dig_index];
        if (dig_max[dig_index] == 9)
            ++dig_index;
    }

    dig_index = m - 1;
    for (short i = 1; i < s; ++i) {
        ++dig_min[dig_index];
        if (dig_min[dig_index] == 9)
            --dig_index;
    }

    for (short i = 0; i < m; ++i)
        cout << dig_min[i];
    cout << " ";
    for (short i = 0; i < m; ++i)
        cout << dig_max[i];

    return 0;
}