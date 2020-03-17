#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long Pow(long long b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void CHFDIV() { ///CodeChef
    const int maxN = 1e6 + 5;
    int check[maxN];
    memset(check, 0, sizeof(check));
    vector<int> prime;
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            prime.push_back(i);
            for (int j = i * 2; j < maxN; j += i) check[j] = 1;
        }
    }
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        long long res = 1;
        for (int i : prime) {
            if (i > n) break;
            if (gcd(1LL * i, k) != 1) continue;
            long long p = i;
            long long tmp = n;
            int e = 0;
            while (tmp >= p) {
                e += tmp / p;
                tmp /= p;
            }
            res = res * Pow(p, e) % MOD;
        }
        cout << res << '\n';
    }
}

long long F(long long p, long long q, long long n) {
    if (p == 0) return 0;
    long long res = n / (q / gcd(p, q));
    long long val = 1LL * n * p / q;
    res += val * n;
    res -= val * (val + 1) / 2 * (q / p);
    return res - F(q % p, p, val);
}

///https://open.kattis.com/problems/itsamodmodmodmodworld
void itsamodmodmodmodworld() {
    int w; cin >> w;
    while (w--) {
        long long p, q, n;
        cin >> p >> q >> n;
        p %= q;
        long long res = 1LL * p * n * (n + 1) / 2;
        res -= F(p, q, n) * q;
        cout << res << '\n';
    }
}

long long Phi(long long n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}

long long Pow(long long b, int e, long long mod) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2, mod);
    if (e % 2 == 0) return x * x % mod;
    return (x * x % mod) * b % mod;
}

///https://open.kattis.com/problems/powers
void powers() {
    vector<int> primes;
    const int maxN = 1e5;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    long long a, b; cin >> a >> b;
    vector<long long> factors;
    vector<int> P;
    int A = a;
    for (int i : primes) {
        if (a % i == 0) {
            int tmp = 1;
            while (a % i == 0) {
                a /= i;
                tmp *= i;
            }
            P.push_back(i);
            factors.push_back(tmp);
        }
    }
    if (a != 1) {
        P.push_back(a);
        factors.push_back(a);
    }
    int len = factors.size();
    long long M[len];
    for (int i = 0; i < len; i++) {
        M[i] = A / factors[i];
    }
    long long Y[len];
    for (int i = 0; i < len; i++) {
        Y[i] = Pow(M[i], factors[i] - factors[i] / P[i] - 1, factors[i]);
    }
    int X[len];
    for (int i = 0; i < len; i++) {
        int phi = factors[i] - factors[i] / P[i];
        if (b % phi == 0) X[i] = factors[i] - 1;
        else X[i] = factors[i] * (factors[i] + 1) / 2 % factors[i];
    }
    long long res = 0;
    for (int i = 0; i < len; i++) {
        res = (res + (X[i] * M[i] % A) * (Y[i] * M[i] % A)) % A;
    }
    cout << res;
    long long res1 = 0;
    for (int i = 0; i < A; i++) {
        res1 -= Pow(i, b, A);
        res1 = (res1 + A) % A;
    }
    cout << " " << res1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///CHFDIV();
    ///itsamodmodmodmodworld();
    for (int i = 0; i < 10; i++)
    powers();
}
