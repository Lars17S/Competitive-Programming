#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;
bool dist[MAX_SIZE] = {false};

int main() {
    int n, m;
    cin >> n >> m;
    int *num = new int[n];
    int *sum_dist = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    sum_dist[n - 1] = 1;
    dist[num[n - 1]] = true;

    for (int i = n - 2; i >= 0; --i) {
        if (!dist[num[i]]) {
            sum_dist[i] = sum_dist[i + 1] + 1;
            dist[num[i]] = true;
        }
        else {
            sum_dist[i] = sum_dist[i + 1];
        }
    }

    for (int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        cout << sum_dist[l - 1] << endl;
    }

    return 0;
}