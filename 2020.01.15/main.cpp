#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const long long MOD = 1e9 + 7;

long long Pow(long long b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveB_MashmokhAndACM() {
    long long n, k;
    cin >> n >> k;
    long long DP[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) DP[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) DP[i][1] = 1;
    //for (int j = 1; j <= k; j++) DP[1][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < k; j++) {
            for (int x = i; x <= n; x += i) {
                DP[x][j + 1] += DP[i][j];
                if (DP[x][j + 1] > MOD) DP[x][j + 1] -= MOD;
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) cout << DP[i][j] << " ";
        cout << '\n';
    }
    */
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += DP[i][k];
        if (res > MOD) res -= MOD;
    }
    cout << res;
}

void solveB_VileGrasshoppers() {
    int p, y; cin >> p >> y;
    vector<int> primes;
    int maxN = 4e4;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            check[i] = 1;
            for (int j = i * i; j < maxN; j += i) check[j] = 1;
        }
    }
    int pos = upper_bound(primes.begin(), primes.end(), p) - primes.begin();
    int res = -1;
    for (int i = 0; i <= 1000; i++) {
        if (y - i <= 0) break;
        int able = 1;
        for (int j = 0; j < pos; j++) {
            if ((y - i) % primes[j] == 0) {
                able = 0;
                break;
            }
        }
        if (able) {
            res = y - i;
            break;
        }
    }
    if (res <= p) cout << -1;
    else cout << res;
}

long long MOD2 = 998244353;

long long Fx(string x) {
    long long res = 0;
    for (int i = 0; i < (int)x.size(); i++) {
        res = (res + x[i] - '0') * 100;
    }
    return (res / 10) % MOD2;
}

long long Fy(string y) {
    long long res = 0;
    for (int i = 0; i < (int)y.size(); i++) {
        res = (res + y[i] - '0') * 100;
    }
    return (res / 100) % MOD2;
}

void solveD1_SubmarineInTheRybinskSeaEasyEdition() {
    long long n; cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (arr[0] == "1000000000") {
        long long tmp = 1e18;
        cout << (n * n * 11 % MOD2) * (tmp % MOD2) % MOD2;
        return;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + Fx(arr[i]) * n) % MOD2;
        res = (res + Fy(arr[i]) * n) % MOD2;
    }
    cout << res;
}

void solveA_VasyaAndPetyasGame() {
    int n; cin >> n;
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            arr[i] = i;
            for (int j = i * i; j <= n; j += i) arr[j] = 1;
        }
    }
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == i) {
            int p = i;
            while (p <= n) {
                res.push_back(p);
                p *= i;
            }
        }
    }
    cout << res.size() << '\n';
    for (int i : res) cout << i << " ";
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveC_MeaninglessOperations() {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int tmp = 1;
        while (tmp <= n) {
            tmp *= 2;
        }
        if (tmp == n + 1) {
            int res = n;
            for (int i = 2; i * i < n; i++) {
                if (n % i == 0) {
                    res /= i;
                    break;
                }
            }
            if (res == n) res = 1;
            cout << res << '\n';
            continue;
        }
        int x = (tmp - n - 1);
        cout << (x ^ n) << '\n';
    }
}

void solveA_kthDivisor() {
    long long n, k; cin >> n >> k;
    vector<long long> div;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (1LL * i * i != n) div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    if (k > (int)div.size()) cout << -1;
    else cout << div[k - 1];
}

long long Gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveA_LCMChallenge() {
    long long n; cin >> n;
    if (n <= 2) {
        cout << n;
        return;
    }
    long long res = n * (n - 1);
    long long tmp = res;
    for (int i = n - 2; i >= 1; i--) {
        res = max(res, tmp * i / Gcd(tmp, i));
    }
    tmp = (n - 1) * (n - 2);
    for (int i = n; i >= 1; i--) {
        res = max(res, tmp * i / Gcd(tmp, i));
    }
    cout << res;
}

void solveB_DivideCandies() {
    long long n, m; cin >> n >> m;
    long long arr[m];
    memset(arr, 0, sizeof (arr));
    for (int i = 0; i < m; i++) {
        if (n < i) {
            arr[i] = 0;
            continue;
        }
        arr[i] = (n - i) / m + 1;
    }
    arr[0] = (n - m) / m + 1;
    if (n < m) arr[0] = 0;
    long long res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if ((i * i + j * j) % m == 0) res += arr[i] * arr[j];
        }
    }
    cout << res;
}

void solveC_RoundTableKnights() {
    int n; cin >> n;
    int arr[n];
    int check[n + 1];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n; i++) cin >> arr[i];
    int able = 0;
    for (int i = 3; i <= n; i++) {
        if (check[i] == 1) continue;
        if (n % i != 0) continue;
        check[i] = 1;
        int tmp = n / i;
        for (int j = 0; j < tmp; j++) {
            int pos = 1;
            for (int k = j; k < n; k += tmp) {
                if (arr[k] == 0) {
                    pos = 0;
                    break;
                }
            }
            if (pos) {
                //cout << i << " " << j << " ";
                able = 1;
                break;
            }
        }
        if (able == 1) break;
        for (int t = i * 2; t <= n; t += i) check[t] = 1;
    }
    if (able) cout << "YES";
    else cout << "NO";
}

const int MAXN = 5e6 + 1;

int minPrime[MAXN];

void Seive() {
    for (int i = 2; i * i < MAXN; i++) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j < MAXN; j += i) minPrime[j] = i;
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (minPrime[i] == 0) minPrime[i] = i;
    }
}

int F(int n) {
    int res = 0;
    while (n > 1) {
        n /= minPrime[n];
        res++;
    }
    return res;
}

void solveD_SoldierAndNumberGame() {
    Seive();
    long long res[MAXN];
    res[1] = res[0] = 0;
    for (int i = 2; i < MAXN; i++) res[i] = res[i - 1] + F(i);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << res[a] - res[b] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveB_MashmokhAndACM();
    ///solveB_VileGrasshoppers();
    ///solveD1_SubmarineInTheRybinskSeaEasyEdition();
    ///solveA_VasyaAndPetyasGame();
    ///solveC_MeaninglessOperations();
    ///solveA_kthDivisor();
    ///solveA_LCMChallenge();
    ///solveB_DivideCandies();
    ///solveC_RoundTableKnights();
    solveD_SoldierAndNumberGame();
}
