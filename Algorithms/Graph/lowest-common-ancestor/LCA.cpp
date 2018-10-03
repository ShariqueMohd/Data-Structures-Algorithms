#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ft first
#define sc second

#define li long int
#define lli long long int
#define ull unsigned long long int

/* Min-heap
struct heapCmp{
    bool operator()(int i, int j){
        return i>j;
    }
};
priority_queue<int, vector<int>, heapCmp> minHeap;
*/

/* Max-heap
priority_queue<int, vector<int> > maxHeap;
*/

template <typename T>  // reverse order (3..2..1)
bool cmp(T x, T y) {
    return x > y;
}

using namespace std;
const int N = 1e5 + 5, LOGN = 20;

int P[N];
int depth[N];
int ST[LOGN][N];
vector<int> G[N];

void dfs(int u, int par, int d) {
    P[u] = par;
    depth[u] = d;
    for (auto v : G[u]) {
        if (v != par) {
            dfs(v, u, d + 1);
        }
    }
}

void lca(int n) {
    for (int i = 1; i <= n; i++) {
        ST[0][i] = P[i];  // 2^0th parent
    }
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            if (ST[j - 1][i]) ST[j][i] = ST[j - 1][ST[j - 1][i]];
        }
    }
}

int query(int u, int v) {
    if (depth[u] != depth[v]) {
        if (depth[u] < depth[v]) swap(u, v);
        int d = depth[u] - depth[v], base = 0;
        while (base < LOGN) {
            if (d & (1 << base)) {
                u = ST[base][u];
                d -= (1 << base);
            }
            base += 1;
        }
    }
    for (int i = LOGN - 1; i >= 0; i--) {
        if (ST[i][u] != ST[i][v]) {
            u = ST[i][u];
            v = ST[i][v];
        }
    }
    return ST[0][u];
}

int main() {
    G[1].pb(2);
    G[1].pb(3);
    G[3].pb(4);
    G[3].pb(5);
    G[5].pb(6);
    G[2].pb(7);
    dfs(1, 1, 0);
    lca(6);
    cout << query(4, 6);
    return 0;
}