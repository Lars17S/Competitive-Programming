#include <iostream>
using namespace std;

bool solveRec(int sum, int* bags, int i, int** dp) {
    if (i < 0)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (sum < bags[i])
        dp[i][sum] = solveRec(sum, bags, i - 1, dp);

    else if (sum == bags[i])
        dp[i][sum] = true;

    else
        dp[i][sum] = solveRec(sum - bags[i], bags, i - 1, dp) || solveRec(sum, bags, i - 1, dp);

    return dp[i][sum];
}

string solve(int sum, int* bags, int n) {
    int **dp;
    dp = new int*[n];
    for (int i = 0; i < n; ++i)
        dp[i] = new int[sum + 1];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = -1;

    return (solveRec(sum, bags, n - 1, dp)) ? "True" : "False";
}



int main() {
    int n;
    int sum = 0;
    cin >> n;
    int* bags = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> bags[i];
        sum += bags[i];
    }

    // If the total of candies is odd, then it is impossible
    if (sum % 2 != 0) {
        cout << "False" << endl;
        return 0;
    }

    // Otherwise, they must share exactly half of the total candies
    sum = sum / 2;
    cout << solve(sum, bags, n) << endl;
    return 0;
}