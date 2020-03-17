#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int maxN = 1e6 + 5;
const long long MOD = 998244353LL;

int prime[maxN];

void Sieve() {
    for (int i = 2; i * i < maxN; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
}

long long Phi(long long x) {
    long long res = 1;
    while (x != 1) {
        int p = prime[x];
        while (x % p == 0) {
            res *= p;
            x /= p;
        }
        res -= res / p;
        res %= MOD;
    }
    return res;
}

long long Pow(long long b, long long e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

long long S = 0;

long long res(long long m) {
    if (m == 1) return 3;
    return res(m - 1) + S * Pow(3LL, m - 2) * 2;
}

/// https://open.kattis.com/problems/anothercoinweighingpuzzle
void anothercoinweighingpuzzle() {
    Sieve();
    long long m, k; cin >> m >> k;
    for (int i = 1; i <= k; i++) {
        S = (S + Phi(i)) % MOD;
    }
    S = 4 * S - 1;
    cout << res(m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    anothercoinweighingpuzzle();
}
