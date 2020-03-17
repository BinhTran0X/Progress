#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

namespace DSU {

const int MAXN = 1e6;
int par[MAXN];

int root(int v) {
    if (par[v] < 0) return v;
    else return (par[v] = root(par[v]));
}

void Merge(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (abs(par[x]) < abs(par[y])) {
        swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
}

}

const int MAXN = 1e5 + 5;
int arr[MAXN];

int root(int x) {
    if (arr[x] < 0) return x;
    return (arr[x] = root(arr[x]));
}

void Put(int s, int t) {
    if ((s = root(s)) == (t = root(t))) return;
    arr[t] += arr[s];
    arr[s] = t;
}

void solveE() { /// Hamro and tools
    int n, q;
    cin >> n >> q;
    memset(arr, -1, sizeof(arr));
    while (q--) {
        int s, t;
        cin >> s >> t;
        Put(s, t);
    }
    for (int i = 1; i <= n; i++) cout << root(i) << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveE();
}
