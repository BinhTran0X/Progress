#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long Phi(long long x) {
    long long res = 1;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            long long c = 1;
            while (x % i == 0) {
                x /= i;
                c *= i;
            }
            res *= c - c / i;
        }
    }
    if (x != 1) res *= x - 1;
    return res;
}

void solveD_SameGCDs() {
    int t; cin >> t;
    while (t--) {
        long long a, m;
        cin >> a >> m;
        m /= gcd(a, m);
        cout << Phi(m) << '\n';
    }
}

void solveB_PseudorandomSequencePeriod() {
    int a, b, m, r;
    cin >> a >> b >> m >> r;
    int check[m];
    memset(check, 0, sizeof(check));
    check[r] = 1;
    int res = -1;
    for (int i = 2; i <= m + 1; i++) {
        r = (a * r + b) % m;
        if (check[r] != 0) {
            res = i - check[r];
            break;
        }
        else check[r] = i;
    }
    cout << res;
}

void solveC_Monitor() {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long p = gcd(x, y);
    x /= p;
    y /= p;
    if (x > a || y > b) {
        cout << "0 0";
        return;
    }
    long long mid, l = 1, r = 2e9;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (x * mid > a || y * mid > b) {
            r = mid - 1;
        }
        else l = mid;
    }
    cout << x * l << " " << y * l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveD_SameGCDs();
    ///solveB_PseudorandomSequencePeriod();
    solveC_Monitor();
}
