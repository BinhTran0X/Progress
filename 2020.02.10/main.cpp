#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveC_VanyaAndScales() {
    long long w, m;
    cin >> w >> m;
    if (w == 2) {
        cout << "YES";
        return;
    }
    int able = 1;
    while (m) {
        long long tmp = m % w;
        m /= w;
        if (tmp == w - 1) {
            m++;
            continue;
        }
        if (tmp == 1 || tmp == 0) continue;
        able = 0;
        break;
    }
    if (able == 1) cout << "YES";
    else cout << "NO";
}

void solveC_BearAndPrimeNumbers() {
    const int maxN = 1e6 + 5;
    int prime[maxN];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i * i < maxN; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    vector<int> primes;
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) {
            prime[i] = i;
            primes.push_back(i);
        }
    }
    int n; cin >> n;
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x != 1) {
            int p = prime[x];
            while (x % p == 0) x/= p;
            M[p]++;
        }
    }
    vector<int> res;
    int len = 0;
    for (int i : primes) {
        if (i == 2) res.push_back(M[i]);
        else res.push_back(res[len - 1] + M[i]);
        len++;
    }
    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        int left = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
        int right = upper_bound(primes.begin(), primes.end(), r) - primes.begin();
        if (left == 0) cout << res[right - 1] << '\n';
        else cout << res[right - 1] - res[left - 1] << '\n';
    }
    //for (int i : res) cout << i << ' ';
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveC_NekoDoesMaths() {
    int a, b;
    cin >> a >> b;
    if (a % b == 0 || b % a == 0) {
        cout << 0;
        return;
    }
    int diff = abs(a - b);
    long long minLCM = a / gcd(a, b) * 1LL * b;
    int res = 0;
    for (int i = 1; i * i <= diff; i++) {
        if (diff % i != 0) continue;
        int tmp = i;
        int newRes = (tmp - a % tmp) % tmp;
        int newA = a + newRes;
        int newB = b + newRes;
        long long newLCM = 1LL * newA / gcd(newA, newB) * newB;
        if (newLCM < minLCM) {
            minLCM = newLCM;
            res = newRes;
        }
        tmp = diff / i;
        newRes = (tmp - a % tmp) % tmp;
        newA = a + newRes;
        newB = b + newRes;
        newLCM = 1LL * newA / gcd(newA, newB) * newB;
        if (newLCM < minLCM) {
            minLCM = newLCM;
            res = newRes;
        }
    }
    cout << res;
}

const int maxN = 2e6 + 5;
const long long MOD = 1e9 + 7;

long long Fact[maxN];

long long Pow(int b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

long long Choose(int n, int k) {
    return (Fact[n] * Pow(Fact[k]) % MOD) * Pow(Fact[n - k]) % MOD;
}

void solveH_Bots() {
    Fact[0] = 1;
    for (int i = 1; i < maxN; i++) Fact[i] = Fact[i - 1] * i % MOD;
    int n; cin >> n;
    long long res = 0;
    for (int i = 1; i <= n + 1; i++) {
        res += Choose(n + i, i);
        res %= MOD;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveC_VanyaAndScales();
    ///solveC_BearAndPrimeNumbers();
    ///solveC_NekoDoesMaths();
    solveH_Bots();
}
