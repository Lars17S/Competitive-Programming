#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
 
int solve(map<int, int> mp, map<int, int>::reverse_iterator it) {
    // "list" already empty (all numbers were deleted)
    if (mp.size() == 1)
        return 0;

    // Iterator not possible
    if (it->first == -1)
        return -1;

    // Ignore a_it
    int ignore_ait = solve(mp, next(it, 1));

    // Use a_it
    int a_it = it->first;
    // Delete numbers with keys +1, -1
    if (mp.count(a_it + 1) > 0)
        mp.erase(a_it + 1);

    if (mp.count(a_it - 1) > 0)
        mp.erase(a_it - 1);

    --mp[a_it];
    // Erase key a_it if there is no more elements in the "list"
    if (mp[a_it] == 0)
        mp.erase(a_it);

    int use_ait = a_it + solve(mp, mp.rbegin());
    return max(ignore_ait, use_ait);
}
 
int main() {
    int n;
    map<int, int> mp;
    cin >> n;
 
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        mp[num] = (mp.count(num) != 0) ? mp[num] + 1 : 1;
    }
    // Dummy element
    mp[-1] = -1;
    cout << solve(mp, mp.rbegin());
    //auto it = mp.rbegin();
    //testRec(mp, it);
    return 0;
}