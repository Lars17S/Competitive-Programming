#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];
    int max_c = 0;
    int j = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] <= arr[i + 1])
            ++j;
        else {
            max_c = (max_c < j) ? j : max_c;
            j = 1;
        }
    }
    max_c = (max_c < j) ? j : max_c;
    cout << max_c;
    return 0;
}