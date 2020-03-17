#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

typedef pair<int, int> i2;

const int maxN = 1e6 + 5;
const int oo = 1e9;
vector<int> adj[maxN];
int check[maxN];
int Dist[maxN];
map<i2, int> M;

void BFS01(int s) {
    deque<int> D;
    D.push_front(s);
    check[s] = 1;
    while (!D.empty()) {
        int u = D.front();
        D.pop_front();
        for (int v : adj[u]) {
            if (check[v] == 0) {
                check[v] = 1;
                if (M[make_pair(u, v)]) {
                    D.push_back(v);
                    Dist[v] = min(Dist[u] + 1, Dist[v]);
                }
                else {
                    D.push_front(v);
                    Dist[v] = min(Dist[u], Dist[v]);
                }
            }
        }
    }
}

void BinGraph() {
    int n, m; cin >> n >> m;
    int s; cin >> s;
    for (int i = 0; i < n; i++) Dist[i] = oo;
    //for (int i = 0; i < n; i++) cout << Dist[i] << " ";
    Dist[s] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        int w; cin >> w;
        M[make_pair(u, v)] = w;
        M[make_pair(v, u)] = w;
    }
    BFS01(s);
    for (int i = 0; i < n; i++) cout << Dist[i] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    BinGraph();
    cout << '\n';
}
