#include <iostream>
using namespace std;

bool solve(int *arr, int n, int sum) {
    // Base case
    if (sum == 0)
        return true;
    
    if (n < 0 || sum < 0)
        return false;

    return solve(arr, n - 1, sum - arr[n]) || solve(arr, n - 1, sum);
}

int main() {
    int n, sum;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> sum;
    if (solve(arr, n- 1, sum))
        cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}