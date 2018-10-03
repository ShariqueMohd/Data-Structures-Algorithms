#include <bits/stdc++.h>

#define Null -1
#define INF 1e10
#define lli long long int
#define pii pair<int, int>

using namespace std;
const int N = 1e5 + 5;

lli dist[N];
int predecessor[N];
vector<pii> G[N];  // pii : {v,w} for a vertex u

// Graph gotta be directed. Nodes: 1 to n
// return True if there is a negative weight cycle, else False

template <class T, class E>
bool BellmanFord(T n, E &G, T source) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        predecessor[i] = Null;
    }
    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto edge : G[u]) {  // (vertex->v){w}
                auto v = edge.first;
                auto w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    predecessor[v] = u;
                }
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        for (auto edge : G[u]) {
            auto v = edge.first;
            auto w = edge.second;
            if (dist[u] + w < dist[v]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, edgecount;
    cin >> n >> edgecount;
    for (int i = 1; i <= edgecount; i++) {
        int u, v, w;
        cin >> u, v, w;
        G[u].push_back({v, w});
    }

    bool hasNegCycle = BellmanFord(n, G, 1);  // source = 1, here
    cout << hasNegCycle << "\n";
    return 0;
}