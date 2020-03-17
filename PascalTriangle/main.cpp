#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

long long MOD = 1e9 + 7;

long long power(int b, int p = MOD - 2) {
    if (p == 0) return 1LL;
    if (p % 2 == 0) {
        long long x = power(b, p / 2);
        return (x * x) % MOD;
    }
    else {
        long long x = power(b, p / 2);
        return ((x * x) % MOD * b) % MOD;
    }
}

long long get7(long long n) {
    long long res = 1;
    while (n) {
        res *= 7;
        n /= 7;
    }
    return res / 7;
}

long long getLTE7(long long n) {
    long long res = -1;
    while (n) {
        res++;
        n /= 7;
    }
    return res;
}

long long arr[23];

long long F(long long n) {
    if (n < 7) return 0;
    long long max7 = get7(n);
    long long k = getLTE7(max7);
    long long ak = n / max7;
    long long res = ((ak * (ak + 1) % MOD) * ((MOD + 1) / 2) % MOD) * arr[k] % MOD;
    long long sp = power(7, k);
    long long spp = sp;
    sp = (sp * (sp - 1) % MOD) * ((MOD + 1) / 2) % MOD;
    res = (res + ((ak * (ak - 1) % MOD) * sp % MOD) * ((MOD + 1) / 2) % MOD) % MOD;
    long long r = n % max7;
    res = (res + ((ak * r % MOD) * (2 * spp - r - 1) % MOD) * ((MOD + 1) / 2) % MOD) % MOD;
    //cout << max7 << " " << k << " " << ak << " " << sp << '\n';
    return (res + (ak + 1) * F(r)) % MOD;
}

void solve() {
    arr[0] = 0;
    for (int i = 1; i < 23; i++) {
        long long xx = power(7, i - 1);
        xx = ((xx - 1) * xx % MOD) * ((MOD + 1) / 2) % MOD;
        xx %= MOD;
        arr[i] = arr[i - 1] * 28 + 21 * xx;
        arr[i] %= MOD;
        //cout << arr[i] << " ";
    }
    //cout << '\n';
    int t; cin >> t;
    int tt = t;
    while (t--) {
        long long n; cin >> n;
        cout << "Case " << tt - t << ": ";
        cout << F(n + 1);
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solve();
    //cout << getLTE7(21);
}
