#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long* WV;
bool* visited;
unordered_map<long long, vector<long long>> edges;
long long minVal = 0;

void DFS(long long v) {
    // Mark the current node as visited and
    // prlong long it
    visited[v] = true;
    //cout << v << " ";
    //cout << "v: " << v << " WV[v]: " << WV[v] << " minVal = " << minVal << endl;
    if (minVal > WV[v]) {
        minVal = WV[v];
    }
 
    // Recur for all the vertices adjacent
    // to this vertex
    vector<long long>::iterator i;
    for (i = edges[v].begin(); i != edges[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    long long n, m, sum = 0;
    cin >> n >> m;
    WV = new long long [n+1];
    visited = new bool[n+1];
    for (long long i = 1; i <= n; ++i) {
        cin >> WV[i];
        visited[i] = false;
    }

    for (long long i = 1; i <= m; ++i) {
        long long v, u;
        cin >> v >> u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    for (long long i = 1; i <= n; ++i) {
        minVal = 0;
        if (!visited[i]) {
            minVal = WV[i];
            DFS(i);
        }
            
        sum += minVal;
    }


    cout << sum << endl;
    return 0;
}