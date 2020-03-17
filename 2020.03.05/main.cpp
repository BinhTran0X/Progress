#include <bits/stdc++.h>
#define TASK "task"
using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void solveC_KuroniAndImpossibleCalculation() {
    int n, m; cin >> n >> m;
    if (n > m) {
        cout << 0;
        return;
    }
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long res = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) res = res * abs(arr[i] - arr[j]) % m;
    }
    cout << res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void maximalLucky() {
    int l1, r1, t1, l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;
    int gap = gcd(t1, t2);

}

const int maxN = 1e5 + 5;
int prime[maxN];
vector<int> primes;

void Sieve() {
    for (int i = 0; i < maxN; i++) prime[i] = i;
    for (int i = 2; i < maxN; i++) {
        if (prime[i] != i) continue;
        primes.push_back(i);
        for (int j = i; j < maxN; j += i) {
            if (prime[j] > i) prime[j] = i;
        }
    }
}

void solveD_RecoverIt() {
    Sieve();
    int n; cin >> n;
    vector<int> p, c;
    map<int, int> M;
    for (int i = 0; i < 2 * n; i++) {
        int x; cin >> x;
        if (prime[x] == x) {
            p.push_back(x);
        }
        else c.push_back(x);
        M[x]++;
    }
    sort(p.begin(), p.end());
    sort(c.begin(), c.end(), greater<int>());
    vector<int> a;
    int pLen = p.size();
    int cLen = c.size();
    for (int i = 0; i < cLen; i++) {
        if (M[c[i]] <= 0) continue;
        int tmp = c[i] / prime[c[i]];
        M[c[i]]--;
        M[tmp]--;
        a.push_back(c[i]);
        n--;
    }
    for (int i = 0; i < pLen; i++) {
        if (M[p[i]] <= 0) continue;
        int tmp = primes[p[i] - 1];
        a.push_back(p[i]);
        M[tmp]--;
        M[p[i]]--;
        n--;
    }
    for (int i : a) cout << i << " ";
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void solveB_RemaindersGame() {
    int n, k; cin >> n >> k;
    //int arr[n];
    long long res = 1;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        if (k % x == 0) {
            res = lcm(res, x);
        }
    }
    if (res == k) cout << "Yes";
    else cout << "No";
}

int ST[maxN * 4];
int arr[maxN];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ST[id] = gcd(ST[id * 2], ST[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    ST[id] = gcd(ST[id * 2], ST[id * 2 + 1]);
}

bool res = true;

int get(int id, int l, int r, int u, int v, int x) {
    if (l > v || r < u) {
        return 0;
    }
    if (l >= u && r <= v) return ST[id];
    int mid = (l + r) / 2;
    int left = get(id * 2, l, mid, u, v, x);
    int right = get(id * 2 + 1, mid + 1, r, u, v, x);
    if (left == 0 || right == 0) return gcd(left, right);
    if (x % left != 0 && x % right != 0) res = false;
    //cout << res << ' ';
    return gcd(left, right);
}

void solveD_BashAndAToughMathPuzzle() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v, x; cin >> u >> v >> x;
            int tmp = get(1, 1, n, u, v, x);
            if (res) cout << "YES\n";
            else cout << "NO\n";
            res = true;
        }
        else {
            int pos, val; cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
    }
    for (int i = 1; i < 4 * n; i++) cout << ST[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveC_KuroniAndImpossibleCalculation();
    ///solveD_RecoverIt();
    ///solveB_RemaindersGame();
    solveD_BashAndAToughMathPuzzle();
}
