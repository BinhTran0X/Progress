#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int maxN = 1e5 + 5;
const int maxM = 5e5 + 5;

typedef pair<int, int> i2;

vector<i2> adj[maxN];
i2 Direct[maxM];
int low[maxN], number[maxN], order = 0, nC[maxN], UsedEdge[maxM];
bool Cau[maxM], Khop[maxN];
int n, m;

void DFS_cut(int u) {
    number[u] = ++order;
    low[u] = n + 1;
    nC[u] = 0;
    for (i2 x : adj[u]) {
        int v = x.first;
        int id = x.second;
        if (UsedEdge[id] == 0) {
            UsedEdge[id] = 1;
            Direct[id] = {u, v};
            if (number[v] == 0) {
                nC[u]++;
                DFS_cut(v);
                low[u] = min(low[u], low[v]);
                if (low[v] > number[u]) Cau[id] = true;
                if (low[v] >= number[u]) Khop[u] = true;
            }
            else low[u] = min(low[u], number[v]);
        }
    }
}

void Graph_() { /// SPOJ
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (number[i] == 0) {
            DFS_cut(i);
            if (nC[i] < 2) Khop[i] = false;
        }
    }
    cout << count(Khop + 1, Khop + 1 + m, true) << " ";
    cout << count(Cau + 1, Cau + 1 + n, true);
}

namespace StrongConnectedComponent {

stack<int> stk;
int SLTPLTM = 0, TP[maxN];

void DFS_SCC(int u) {
    number[u] = ++order;
    low[u] = number[u];
    stk.push(u);
    for (i2 x : adj[u]) {
        int v = x.first;
        if (TP[v] != 0) continue;
        if (number[v] == 0) {
            DFS_SCC(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], number[v]);
    }
    if (number[u] == low[u]) {
        int v;
        SLTPLTM++;
        do {
            v = stk.top();
            stk.pop();
            TP[v] = SLTPLTM;
        } while (v != u);
    }
}

}

void solveE_ReachabilityFromTheCapital() {
    cin >> n >> m;
    int s; cin >> s;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        //adj[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (number[i] == 0) {
            StrongConnectedComponent::DFS_SCC(i);
        }
    }
    cout << StrongConnectedComponent::SLTPLTM - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    Graph_();
    ///solveE_ReachabilityFromTheCapital();
}
