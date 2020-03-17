#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

typedef pair<int, int> i2;

const int maxN = 1e5 + 1;
const int maxM = 1e6 + 1;
vector<i2> adj[maxN];
int number[maxN], low[maxN], nC[maxN];
int order = 0;
int n, m;
stack<int> stk;
int SLTPLTM = 0, TP[maxN];

/// Strongly connected components (SSC)
void DFS_SCC(int u) {
    number[u] = ++order;
    low[u] = number[u];
    stk.push(u);
    for (i2 x : adj[u]) {
        int v = x.first;
        //int id = x.second;
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
            v =  stk.top();
            stk.pop();
            TP[v] = SLTPLTM;
        } while (v != u);
    }
}

void TJALG() { /// https://vn.spoj.com/problems/TJALG/
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++) {
        if (number[i] == 0) DFS_SCC(i);
    }
    cout << SLTPLTM;
}

int parent[maxN], L[maxN], R[maxN], child[maxN], D[maxN];
int cost[maxM];
long long res = 0;

void DFS_tree(int u) {
    L[u] = ++order;
    child[u] = 1;
    for (i2 x : adj[u]) {
        int id = x.second;
        int v = x.first;
        if (v == parent[u]) continue;
        parent[v] = u;
        D[v] = D[u] + cost[id];
        DFS_tree(v);
        child[u] += child[v];
        res += 1LL * cost[id] * child[v] * (n - child[v]);
        //cout << child[v] << " " << v << " ";
    }
    R[u] = order;
}

void NTTREE() { /// https://vn.spoj.com/problems/NTTREE/
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v >> cost[i];
        u++; v++;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    DFS_tree(1);
    cout << res;
}

vector<int> Adj[2 * maxN];
int val[2 * maxN];

void DFS_counter(int u) {
    for (int v : Adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        val[v] += val[u];
        DFS_counter(v);
    }
}

void solveD_Ki() { /// https://atcoder.jp/contests/abc138/tasks/abc138_d
    int q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    while (q--) {
        int p, x; cin >> p >> x;
        val[p] += x;
    }
    DFS_counter(1);
    for (int i = 1; i <= n; i++) cout << val[i] << " ";
}

int Used[maxN], inD[maxN], outD[maxN];

void DFS_topo(int u) {
    Used[u]++;
    L[u] = ++order;
    for (int v : Adj[u]) {
        if (Used[v] == 1) {
            //if (Used[u] != 1) continue;
            if (L[parent[v]] <= L[u] && L[u] <= R[parent[v]]) {
                parent[v] = u;
            }
            continue;
            //parent[v] = u;
        }
        //D[v] = D[u] + 1;
        parent[v] = u;
        DFS_topo(v);
    }
    R[u] = order;
}

void solveD_RestoreTheTree() { ///https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d
    cin >> n >> m;
    for (int i = 1; i < n + m; i++) {
        int u, v; cin >> u >> v;
        Adj[u].push_back(v);
        inD[v]++;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (inD[i] == 0) {
            root = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) R[i] = 1e9;
    DFS_topo(root);
    for (int i = 1; i <= n; i++) cout << parent[i] << "\n";
}

int color[maxN];

long long DFS_color(int u) {
    long long res = 1;
    for (int v : Adj[u]) {
        if (parent[u] == v) continue;
        parent[v] = u;
        long long tmp = DFS_color(v);
        if (color[v] == color[u]) res--;
        res += tmp;
    }
    return res;
}

void solveB_ColoringATree() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        Adj[p].push_back(i);
        Adj[i].push_back(p);
    }
    for (int i = 1; i <= n; i++) cin >> color[i];
    cout << DFS_color(1);
}

vector<int> Res;
int check[20000];

bool DFS_alphabet(int u) {
    L[u] = ++order;
    R[u] = 1e9;
    Used[u] = 1;
    bool res = true;
    for (int v : Adj[u]) {
        if (Used[v] == 1) {
            if (L[v] <= L[u] && L[u] <= R[v]) return false;
            else continue;
        }
        res &= DFS_alphabet(v);
    }
    R[u] = order;
    Res.push_back(u);
    return res;
}

void solveC_FoxAndNames() {
    int n; cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int able = 1;
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        int len = min(arr[i].size(), arr[i + 1].size());
        for (j = 0; j < len; j++) {
            if (arr[i][j] != arr[i + 1][j]) break;
        }
        if (j == len) {
            if (arr[i].size() > arr[i + 1].size()) {
                able = 0;
                break;
            }
            else continue;
        }
        int u = arr[i][j] - 'a' + 1;
        int v = arr[i + 1][j] - 'a' + 1;
        //cout << u << ' ' << v << '\n';
        if (check[u * 27 + v] == 0) {
            //cout << u << v << '\n';
            Adj[u].push_back(v);
            outD[u]++;
            inD[v]++;
            check[u * 27 + v] = 1;
        }
    }
    if (able == 0) {
        cout << "Impossible";
        return;
    }
    //for (int j = 1; j <= 26; j++) R[j] = 1e9;
    for (int i = 1; i <= 26; i++) {
        if (Used[i] == 0 && inD[i] == 0)
            able &= DFS_alphabet(i);
    }
    if (able && (int)Res.size() == 26) {
        int len = Res.size();
        for (int i = len - 1; i >= 0; i--)
            cout << char('a' + Res[i] - 1);
    }
    else cout << "Impossible";
    /*
    cout << endl;
    for (int i = 1; i <= 26; i++) {
        cout << char(i + 'a' - 1) << ": ";
        for (int j : Adj[i]) cout << char(j + 'a' - 1) <<  ' ';
        cout << '\n';
    }
    */
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///TJALG();
    ///NTTREE();
    ///solveD_Ki();
    ///solveD_RestoreTheTree();
    ///solveB_ColoringATree();
    solveC_FoxAndNames();
}
