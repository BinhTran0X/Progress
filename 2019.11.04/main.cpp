#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void GCDSUM() { /// SPOJ
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        long long res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                res += __gcd(i, j);
            }
        }
        cout << res << '\n';
    }
}

int main()
{
    rwFile();
    GCDSUM();
}
