#include <limits.h> 
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
  
// Number of vertices in the graph 
int V; 

int minDistance(int dist[], bool sptSet[]) { 
    // Initialize min value 
    int min = INT_MAX;
    int min_index; 
  
    for (int v = 0; v <= V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}

int* dijkstra(int** graph, int src) { 
    int* dist = new int[V + 1];
  
    bool* sptSet = new bool[V + 1]; // sptSet[i] will be true if vertex i is included in shortest 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i <= V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 

    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, sptSet);
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v <= V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
    } 
    return dist;
} 

int main() { 
    int M, C;
    cin >> V >> M >> C;
    cin >> ws;
    int* dist;
    int** graph = new int*[V + 1];
    string* index_city = new string[V + 1];
    unordered_map<string, int> city_severity;

    graph[0] = new int[V + 1]();
    for (int i = 1; i <= V; ++i) {
        getline(cin, index_city[i]);
        city_severity[index_city[i]] = -1;
        graph[i] = new int[V + 1]();
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    cin >> ws;
    for (int i = 0; i < C; ++i) {
        string str;
        getline(cin, str);
        size_t found = str.find_first_of("0123456789");
        string str_city = str.substr(0, found - 1);
        int severity = stoi(str.substr(found));
        city_severity[str_city] = severity;
    }

    string src_name;
    int src_index;
    getline(cin, src_name);

    for (int i = 1; i <= V; ++i)
        if (index_city[i] == src_name) {
            src_index = i;
            break;
        }

    dist = dijkstra(graph, src_index);
    
    set<pair<int, string>> sol;
    for (int i = 1; i <= V; ++i) {
        int eval = (dist[i] != INT_MAX && city_severity[index_city[i]] != -1) ? 
                dist[i] * city_severity[index_city[i]] : INT_MAX;
        sol.insert(make_pair(eval, index_city[i]));
    }
    
    int i = 0;
    auto it = sol.begin();
    for (int i = 0; i < 5; ++i) {
        cout << it->second << " " << it->first << endl;
        ++it;
    }

    return 0; 
} 