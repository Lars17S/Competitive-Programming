#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int sum_a = 0;
    int sum_b = 0;
    int n, num;
    cin >> n;
    int* bags = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> bags[i];

    sort(bags, bags + n);
    
    for (int i = n - 1; i >= 0; --i) {
        if (sum_a < sum_b)
            sum_a += bags[i];
        else
            sum_b += bags[i];
    }

    if (sum_a == sum_b)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}