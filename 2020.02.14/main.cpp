#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveC_Multiplicity() {
    const int maxN = 1e3 + 5;
    const int MOD = 1e9 + 7;
    vector<int> div[maxN];
    int Size[maxN];
    memset(div, 0, sizeof(div));
    memset(Size, 0, sizeof(Size));
    for (int i = 2; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            div[j].push_back(i);
            Size[j]++;
        }
    }
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long res[maxN];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) {
        int t = arr[i];
        for (int j = Size[t] - 1; j >= 0; j--) {
            //cout << div[t][j] << '\n';
            res[div[t][j]] += res[div[t][j] - 1];
            res[div[t][j]] %= MOD;
        }
        res[1]++;
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + res[i]) % MOD;
    //for (int i = 0; i <= n; i++) cout << Size[i];
    //for (int i = 0; i <= n; i++) cout << res[i] << ' ';
    cout << ans;
}

const long long MOD = 1e9 + 9;

long long Pow(long long b, long long e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveA_AlternatingSum() {
    long long n, a, b, k;
    cin >> n >> a >> b >> k;
    int s[k];
    string ss; cin >> ss;
    for (int i = 0; i < k; i++) {
        if (ss[i] == '+') s[i] = 1;
        else s[i] = -1;
    }
    if (Pow(a, k) == Pow(b, k)) {
        long long tot = 0;
        for (int i = 0; i < k; i++) {
            tot += s[i] * Pow(b, i) * Pow(a, k - 1 - i) % MOD;
            tot %= MOD;
        }
        long long res = tot * (n + 1) / k * Pow(a, n + 1 - k) % MOD;
        res = (res + MOD) % MOD;
        cout << res;
        return;
    }
    //if (b > a) swap(a, b);
    long long res = 0;
    long long tmp = (Pow(a, n + 1) - Pow(b, n + 1) + MOD) % MOD;
    //cout << tmp << ' ';
    tmp = tmp * Pow((Pow(a, k) - Pow(b, k) + MOD) % MOD) % MOD;
    //cout << tmp << " ";
    for (int i = 0; i < k; i++) {
        long long temp = Pow(b, i) * Pow(a, k - 1 - i) % MOD;
        temp = temp * tmp % MOD;
        if (s[i] == -1) temp = MOD - temp;
        res = (res + temp) % MOD;
    }
    cout << res;
}

long long GCD, X, Y;
void extendedEuclid(long long A, long long B) {
    if (B == 0) {
        GCD = A;
        X = 1;
        Y = 0;
    }
    else {
        extendedEuclid(B, A % B);
        long long temp = X;
        X = Y;
        Y = temp - (A / B) * Y;
    }
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveC_Line() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long A = abs(a), B = abs(b), C = abs(c);
    if (C % gcd(A, B) != 0) {
        cout << -1;
        return;
    }
    extendedEuclid(A, B);
    if (a < 0) X = -X;
    if (b < 0) Y = -Y;
    long long tmp = -c / gcd(A, B);
    cout << X * tmp << " " << Y * tmp;
}

const long long MOD1 = 1e9 + 7;

long long Pow1(long long b, long long e = MOD1 - 2) {
    if (e == 0) return 1LL;
    long long x = Pow1(b, e / 2);
    if (e % 2 == 0) return x * x % MOD1;
    return (x * x % MOD1) * b % MOD1;
}

const int maxN = 3e6 + 1;
int prime[maxN];
long long F[maxN];

long long Ff(long long tmp) {
    long long add = 0;
    long long imod2 = (MOD1 + 1) / 2;
    while (tmp != 1) {
        int p = prime[tmp];
        long long nn = (imod2 * tmp % MOD1) * (p - 1) % MOD1;
        add = (add + nn) % MOD1;
        tmp /= p;
    }
    return add;
}

void solveD_MyPrettyGirlNoora() {
    for (int i = 2; i * i < maxN; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) {
                if (prime[j] != 0) prime[j] = min(prime[j], i);
                else prime[j] = i;
            }
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
    //for (int i = 2; i < 100; i++) if (prime[i] == i) cout << i  << '\n';
    //long long imod2 = (MOD1 + 1) / 2;
    F[1] = 0;
    for (long long i = 2; i < maxN; i++) {
        F[i] = F[i / prime[i]] + (i * (prime[i] - 1) / 2 % MOD1);
        F[i] %= MOD1;
    }
    long long t, l, r;
    cin >> t >> l >> r;
    long long T = 1;
    long long res = 0;
    for (int i = l; i <= r; i++) {
        //cout << add << ' ';
        res = (res + T * F[i]) % MOD1;
        res %= MOD1;
        T = T * t % MOD1;
    }
    cout << res;
}

void solveC_VasilyTheBearAndSequence() {
    int n; cin >> n;
    int arr[n];
    int check[32];
    for (int i = 0; i < 32; i++) check[i] = 4294967295;
    vector<int> res[32];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int tmp = arr[i];
        int c = 0;
        while (tmp != 0) {
            if (tmp % 2 == 1) {
                check[c] &= arr[i];
                res[c].push_back(arr[i]);
            }
            c++;
            tmp /= 2;
        }
    }
    long long pow2[32];
    pow2[0] = 1;
    for (int i = 1; i < 32; i++) pow2[i] = 2 * pow2[i - 1];
    for (int i= 31; i >= 0; i--) {
        if (check[i] % pow2[i] == 0) {
            cout << res[i].size() << '\n';
            for (int j : res[i]) cout << j << ' ';
            break;
        }
    }
}

void solveC_BeaverGame() {
    long long n, m, k;
    cin >> n >> m >> k;
    int fmove = 0;
    for (int i = 2; i * i <= m; i++) {
        if (m % i != 0) continue;
        if (i >= k || m / i >= k) {
            fmove = 1;
            break;
        }
    }
    if (k == 1 && m != 1) fmove = 1;
    if (fmove == 0) {
        cout << "Marsel";
        return;
    }
    if (n % 2 == 1) cout << "Timur";
    else cout << "Marsel";
}

void solveD_IceSculptures() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n == 4) {
        long long res = 0;
        for (int i = 0; i < n; i++) res += arr[i];
        cout << res;
        return;
    }
    long long res = -1e9;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        for (int j = 0; j < i; j++) {
            long long tmp = 0;
            for (int k = 0; j + k * i < n; k++) tmp += arr[j + k * i];
            res = max(res, tmp);
        }
        if (i == 1 || i == 2) continue;
        for (int j = 0; j < n / i; j++) {
            long long tmp = 0;
            for (int k = 0; j + k * n / i < n; k++) tmp += arr[j + k * n / i];
            res = max(res, tmp);
        }
    }
    cout << res;
}

void solveC_TheFootballSeason() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    extendedEuclid(w, d);
    if (p % GCD != 0) {
        cout << -1;
        return;
    }
    X *= p / GCD;
    Y *= p / GCD;
    //cout << X << ' ' << Y << ' ';
    long long LCM = w * d / GCD;
    long long a = LCM / w;
    long long b = LCM / d;
    //cout << X << ' ' << Y << '\n';
    if (X > Y) {
        long long alpha = (-Y + b - 1) / b;
        long long x = X - alpha * a;
        long long y = alpha * b + Y;
        long long z = n - x - y;
        if (x < 0 || y < 0 || z < 0) cout << -1;
        else cout << x << ' ' << y << ' ' << z;
    }
    else {
        long long alpha = Y / b;
        long long x = alpha * a + X;
        long long y = Y - alpha * b;
        long long z = n - x - y;
        if (x < 0 || y < 0 || z < 0) cout << -1;
        else cout << x << ' ' << y << ' ' << z;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveC_Multiplicity();
    ///solveA_AlternatingSum();
    ///solveC_Line();
    ///solveD_MyPrettyGirlNoora();
    ///solveC_VasilyTheBearAndSequence();
    ///solveC_BeaverGame();
    ///solveD_IceSculptures();
    solveC_TheFootballSeason();
}
