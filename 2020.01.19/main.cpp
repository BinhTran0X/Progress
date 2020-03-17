#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const long long MOD = 1e9 + 7;

long long Pow(int b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveA_OnNumberOfDecompositionsIntoMultipliers() {
    vector<int> primes;
    const int maxN = 4e4;
    int check[maxN];
    memset(check, 0,sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    int n; cin >> n;
    map<int,int> M;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int i : primes) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                    M[i]++;
                }
            }
            if (x == 1) break;
        }
        if (x != 1) M[x]++;
    }
    long long fact[maxN];
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = fact[i - 1] * i % MOD;
    long long res = 1;
    for (auto i : M) {
        long long tmp = fact[n + i.second - 1] * Pow(fact[n - 1]) % MOD;
        tmp = tmp * Pow(fact[i.second]) % MOD;
        res = res * tmp % MOD;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveA_OnNumberOfDecompositionsIntoMultipliers();
}
