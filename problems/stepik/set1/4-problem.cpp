#include <iostream>
using namespace std;

char solveRec(int* arr, int n, int sum, char** table) {
    if (table[n][sum] != 'U')
        return table[n][sum];

    if (sum == 0) {
        table[n][sum] = 'Y';
        return 'Y';
    }

    if (n == 0 || sum < 0) {
        table[n][sum] = 'N';
        return 'N';
    }

    table[n][sum] = (solveRec(arr, n - 1, sum - arr[n], table) == 'Y' ||
            solveRec(arr, n - 1, sum, table) == 'Y') ? 'Y' : 'N';
    return table[n][sum];
}

string solve(int *arr, int n, int sum) {
    char** table = new char*[n + 1];
    for (int i = 0; i < n + 1; ++i)
        table[i] = new char[sum + 1];

    for (int i = 0; i < n + 1; ++i) 
        for (int j = 0; j < sum + 1; ++j) 
            table[i][j] = 'U';

    return (solveRec(arr, n, sum, table) == 'Y') ? "True" : "False";
}

int main() {
    int n, sum;
    cin >> n;
    int* arr = new int[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> sum;
    cout << solve(arr, n, sum) << endl;
    return 0;
}