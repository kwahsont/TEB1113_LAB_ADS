// i made two djikstra implementations for learning purposes. one uses adjacency list and the other uses adjacency matrix. the first one is more efficient and uses priority queue, while the second one is more straightforward and uses a simple array to keep track of distances.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {     

    int V = adj.size();

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; 

        cout << "Visiting node " << u << " (distance " << d << ")\n";

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                cout << "  -> updated node " << v << " to " << dist[v] << "\n";
            }
        }
    }

    return dist;
}

int main() {
    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    vector<int> dist = dijkstra(adj, src);

    cout << "\nFinal shortest distances from node " << src << ":\n";
    for (int i = 0; i < (int)dist.size(); i++)
        cout << "  Node " << i << ": " << dist[i] << "\n";

    return 0;
}