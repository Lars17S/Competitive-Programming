#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100000;

int main() {
    string s;
    int m;
    getline(cin, s);
    int *sum = new int[s.length()];
    
    sum[0] = (s[0] == s[1]) ? 1 : 0;
    for (int i = 1; i < s.length() - 1; ++i)
        sum[i] = (s[i] == s[i + 1]) ? sum[i - 1] + 1 : sum[i - 1];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int ans, l, r;
        cin >> l >> r;
        --l;
        --r;
        if (l == 0)
            ans = sum[r - 1];
        else if (l == r - 1)
            ans = (s[l] == s[l + 1]) ? 1 : 0;
        else
            ans = sum[r - 1] - sum[l - 1];
        cout << ans << endl;
    }
    return 0;
}