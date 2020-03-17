#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const long long MOD = 1e9 + 7;

long long Pow(long long b, long long e = MOD - 2, long long m = MOD) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % m;
    return (x * x % MOD) * b % m;
}

void solveD_Multipliers() {
    int m; cin >> m;
    map<long long, long long> M;
    for (int i = 0; i < m; i++) {
        long long x; cin >> x;
        M[x]++;
    }
    long long exp = 1;
    int done = 0;
    for (auto i : M) {
        if (i.second % 2 == 1 && done == 0) {
            done = 1;
            long long temp = (i.second + 1) / 2;
            exp = exp * temp % (MOD - 1);
        }
        else exp = exp * (i.second + 1) % (MOD - 1);
    }

    if (done == 0) {
        for (auto &i : M) i.second /= 2;
    }
    long long res = 1;
    for (auto i : M) {
        long long b = i.first;
        long long e = i.second * exp % (MOD - 1);
        long long tmp = Pow(b, e);
        res = res * tmp % MOD;
    }
    cout << res;
}

void solveC_ShaassAndLights() {
    const int maxN = 1e4;
    long long fact[maxN];
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = fact[i - 1] * i % MOD;
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++) cin >> arr[i];
    sort(arr, arr + m);
    vector<int> diff;
    if (arr[0] != 1) diff.push_back(arr[0] - 1);
    int e = 0;
    long long Sum =  n - m;
    for (int i = 1; i < m; i++) {
        diff.push_back(arr[i] - arr[i - 1] - 1);
        if (arr[i] - arr[i - 1] - 2 > 0) e += arr[i] - arr[i - 1] - 2;
    }
    if (arr[m - 1] != n) diff.push_back(n - arr[m - 1]);
    long long res = Pow(2LL, e) * fact[Sum] % MOD;
    for (int i : diff) res = res * Pow(fact[i]) % MOD;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveD_Multipliers();
    solveC_ShaassAndLights();
}
