#include <iostream>
using namespace std;

short table[100][100] = {0};

int main() {
    short n;
    short num_ones = 0;
    short max = -15000;

    cin >> n;
    bool *bin = new bool[n];
    for (int i = 0; i < n; ++i) {
        cin >> bin[i];
        if (bin[i])
            ++num_ones;
    }
    
    // Base cases

    table[0][0] = (bin[0]) ? -1 : 1;
    if (max < table[0][0])
        max = table[0][0];
        
    for (short j = 1; j < n; ++j) {
        table[0][j] = (bin[j]) ? table[0][j - 1] - 1 : table[0][j - 1] + 1;
        if (max < table[0][j])
            max = table[0][j];
    }

    // Fill the table

    for (short i = 1; i < n; ++i)
        for (short j = i; j < n; ++j) {
            table[i][j] = (bin[j]) ? table[i][j - 1] - 1 : table[i][j - 1] + 1;
            if (max < table[i][j])
                max = table[i][j];
        }

    cout << max + num_ones << endl;
    return 0;
}