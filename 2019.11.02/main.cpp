#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void Zpo() { /// HackerEarth
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int adj[n + 1];
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            adj[u]++;
            adj[v]++;
        }
        int val[n + 1];
        for (int i = 0; i < n; i++) cin >> val[i + 1];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (adj[i] > 1 && val[i] != 0) res++;
        }
        cout << res << '\n';
    }
}

void Em() {
    int n, q; cin >> n >> q;
    int gcd = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        gcd = __gcd(gcd, x);
    };
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (x % gcd == 0) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}

void Dn() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            res.push_back(arr[i]);
            break;
        }
        if (arr[i] != arr[i + 1]) {
            res.push_back(arr[i]);
        }
        else i++;
    }
    for (int i : res) cout << i << " ";
    cout << '\n';
}

void Oaof() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int inDeg[n + 1], outDeg[n + 1];
        memset(inDeg, 0, sizeof(inDeg));
        memset(outDeg, 0, sizeof(outDeg));
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            inDeg[v]++;
            outDeg[u]++;
        }
        if (n == 1) {
            cout << "Yes\n";
            continue;
        }
        int able = 1;
        for (int i = 1; i <= n; i++) {
            if (inDeg[i] != 1 || outDeg[i] != 1) {
                able = 0;
                break;
            }
        }
        if (able == 0) cout << "No";
        else cout << "Yes";
        cout << '\n';
    }
}

void Niar() {
    int l, r, n;
    cin >> l >> r >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int maxN = r - l + 1;
    long long DP[maxN];
    memset(DP, 1, sizeof(DP));
    for (int i = 0; i < n; i++) {

    }
}

int main()
{
    rwFile();
    Niar();
    //Oaof();
    //Dn();
    //Em();
    //Zpo();
}
