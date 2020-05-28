#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    set<pair<string, string>> sol;
    int n;
    cin >> n;
    cin >> ws;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        sol.insert(make_pair(s2, s1));
    }

    for (auto it : sol)
        cout << it.second << endl;
        
    return 0;
}