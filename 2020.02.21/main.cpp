#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const long long MOD = 1e9 + 7;

/// Find [v_p(1!2!...n!) % MOD] with a prime p
void FactorialExactExponent() {
    long long p, n; cin >> p >> n;
    long long tmp = p;
    long long res = 0;
    while (tmp <= n + 1) {
        long long val = (n + 1) / tmp;
        long long extra = val * (n + 1) % MOD;
        long long temp = (tmp * (val + 1) % MOD) * val % MOD;
        temp = temp * ((MOD + 1) / 2) % MOD;
        extra -= temp;
        extra = (extra + MOD) % MOD;
        res += extra;
        tmp *= p;
    }
    cout << res;
}

typedef pair<int, int> i2;

const int maxN = 1e5;
const int maxM = 5e5;

vector<i2> adj[maxN];
int Used[maxM], check[maxN], Count[maxN], D1[maxN], D2[maxN];

void DFS_stable(int u, int c) {
    check[u] = 1;
    for (i2 x : adj[u]) {
        int v = x.first;
        int id = x.second;
        if (Used[id] != 0) continue;
        if (check[v] == 0) {
            Used[id] = 1;
            if (c == 0) D1[v] = min(1 + D1[u], D1[v]);
            else D2[v] = min(1 + D2[u], D2[v]);
            Count[v]++;
            DFS_stable(v, c);
        }
    }
}

void STABLE() { /// https://vn.spoj.com/problems/STABLE/
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        D1[i] = D2[i] = 1e9;
    }
    DFS_stable(s, 0);
    memset(check, 0, sizeof(check));
    DFS_stable(s, 1);
    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (D1[i] == D2[i]) {
            res++;
            //cout << i << ' ';
        }
    }
    cout << res;
}

void MESSAGE() {
    int n, m; cin >> n >> m;
    int InD[n + 1];
    memset(InD, 0, sizeof(InD));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        InD[v]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (InD[i] == 0) res++;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///FactorialExactExponent();
    ///STABLE();
    MESSAGE();
}
