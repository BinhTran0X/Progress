#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveD_MinimaxProblem() {
    int n, m; cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }
    int len = 1;
    for (int i = 0; i < m; i++) len *= 2;
    int mask[len];
    int l = 0, r = 1e9, res; //a, b;
    while (l < r) {
        res = (l + r) / 2;
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < m; j++) {
                t *= 2;
                if (arr[i][j] >= res) t++;
            }
            mask[t]++;
        }
        int able = 0;
        if (mask[len - 1] >= 2) able = 1;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (mask[i] > 0 && mask[j] > 0) {
                    if ((i ^ j) == len - 1) {
                        able = 1;
                        break;
                    }
                }
            }
        }
        if (able) {
            l = res;
        }
        else {
            r = res - 1;
        }
    }
    cout << res;
}

void solveB_Math() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1 0";
        return;
    }
    int m = n;
    int e = 0, val = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            val *= i;
            int t = 0;
            while (n % i == 0) {
                n /= i;
                t++;
            }
            e = max(e, t);
        }
    }
    int res = 0;
    for (int i = 2; i <= m; i++) {
        if (m % i == 0) {
            int t = 0;
            while (m % i == 0) {
                m /= i;
                t++;
            }
            if (e != t) {
                res = 1;
                break;
            }
        }
    }
    int x = 1;
    int tmp = 0;
    while (x < e) {
        x *= 2;
        tmp++;
    }
    if (x != e) res = 1;
    cout << val << ' ' << res + tmp << '\n';
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveC_ModifiedGCD() {
    int a, b; cin >> a >> b;
    int tmp = gcd(a, b);
    vector<int> lis;
    for (int i = 1; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            lis.push_back(i);
            if (i * i != tmp) lis.push_back(tmp / i);
        }
    }
    sort(lis.begin(), lis.end());
    int n; cin >> n;
    while (n--) {
        int l, h; cin >> l >> h;
        int pos = upper_bound(lis.begin(), lis.end(), h) - lis.begin();
        if (pos == 0) {
            cout << "-1\n";
            continue;
        }
        if (lis[pos - 1] >= l) cout << lis[pos - 1] << '\n';
        else cout << "-1\n";
    }
}

void solveD_AlmostAllDivisors() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 0) {
            cout << 1 << '\n';
            continue;
        }
        long long arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        long long res = arr[0] * arr[n - 1];
        for (int i = 0; i * 2 < n; i++) {
            if (arr[i] * arr[n - 1 - i] != res) {
                res = -1;
                break;
            }
        }
        if (res == -1) {
            cout << res << '\n';
            continue;
        }
        int t = 1;
        long long tmp = res;
        for (int i = 2; i<= tmp; i++) {
            if (tmp % i == 0) {
                int x = 0;
                while (tmp % i == 0) {
                    tmp /= i;
                    x++;
                }
                t *= x + 1;
            }
        }
        if (t != n + 2) cout << "-1\n";
        else cout << res << '\n';
    }
}

void solveA_Pride() {
    int n; cin >> n;
    int arr[n], c = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) c++;
    }
    if (c != 0) {
        cout << n - c;
        return;
    }
    int t = n;
    for (int i = 0; i < n - 1; i++) {
        int tmp = arr[i];
        for (int j = i + 1; j < n; j++) {
            tmp = gcd(tmp, arr[j]);
            if (tmp == 1) {
                t = min(t, j - i);
                break;
            }
        }
    }
    if (t == n) cout << -1;
    else cout << t + n - 1;
}

const long long MOD = 1e9 + 7;

long long Pow(long long b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void TPCLKNUM() { /// SPOJ
    long long n, k; cin >> n >> k;
    if (k > n) {
        cout << 0;
        return;
    }
    long long res = 0;
    for (int i = 0; i < n - k; i++) {
        long long tmp = Pow(10, n - k - i - 1) * (9 * (n - k - i) + 10) % MOD;
        if (i % 2 == 0) res = (res + tmp) % MOD;
        else res = (res + MOD - tmp) % MOD;
    }
    if ((n - k) % 2 == 1) res--;
    else res++;
    cout << res;
}

void solveA_RationalResistance() {
    long long a, b; cin >> a >> b;
    long long res = 0;
    while (a != 0) {
        if (a >= b) {
            res += a / b;
            a = a % b;
        }
        else swap(a, b);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveD_MinimaxProblem();
    ///solveB_Math();
    ///solveC_ModifiedGCD();
    ///solveD_AlmostAllDivisors();
    ///solveA_Pride();
    ///TPCLKNUM();
    ///solveA_RationalResistance();
}
