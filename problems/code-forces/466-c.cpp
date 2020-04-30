#include <iostream>
using namespace std;
 
const int MAX_SIZE = 100000;
long long sum[MAX_SIZE];
 
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
 
    int p = 0;
    int count = 0;
    while ((p < n - 2)) {
        int q = p + 1;
        while ((q < n - 1)) {
            if ((sum[p] == sum[q] - sum[p]) && (sum[p] == sum[n - 1] - sum[q]))
               ++count;
            ++q;
        }
        ++p;
    }
 
    cout << count << endl;
 
    return 0;
}