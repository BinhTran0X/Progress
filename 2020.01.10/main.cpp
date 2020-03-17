#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveB_NewYearsEve() {
    long long n, k;
    cin >> n >> k;
    if (k == 1) cout << n;
    else {
        long long res = 1;
        while (n) {
            res *= 2;
            n /= 2;
        }
        cout << res - 1;
    }
}

void solveB_PrimeMatrix() {
    vector<int> primes;
    int MAXN = 1e5 + 5;
    int check[MAXN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < MAXN; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            primes.push_back(i);
            long long tmp = (long long)i * i;
            if (tmp >= MAXN) continue;
            for (int j = i * i; j < MAXN; j += i) check[j] = 1;
        }
    }
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int row[n], col[m];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            int x = arr[i][j];
            int pos = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
            if (primes[pos] == x) continue;
            int tmp = primes[pos] - x;
            //cout << tmp << ' ';
            row[i] += tmp;
            col[j] += tmp;
        }
    }
    int res = 1e9;
    for (int i = 0; i < n; i++) res = min(res, row[i]);
    for (int i = 0; i < m; i++) res = min(res, col[i]);
    cout << res;
}

const int MAXN = 1e5 + 5;
int primes[MAXN];

void sieve() {
    for (int i = 2; i * i < MAXN; i++) {
        if (primes[i] == 0) primes[i] = i;
        for (int j = i * i; j < MAXN; j += i) {
            if (primes[j] == 0) primes[j] = i;
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (primes[i] == 0) primes[i] = i;
    }
}

void solveB_BashsBigDay() {
    sieve();
    int n;
    cin >> n;
    int arr[MAXN];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x != 1) {
            int tmp = primes[x];
            arr[tmp]++;
            while (x % tmp == 0) x /= tmp;
        }
    }
    int res = 1;
    for (int i = 0; i < MAXN; i++) res = max(res, arr[i]);
    cout << res;
}

void solveA_CowsAndPrimitiveRoots() {
    int p; cin >> p;
    p--;
    int res = 1;
    for (int i = 2; i <= p; i++) {
        if (p % i == 0) {
            while (p % i == 0) {
                res *= i;
                p /= i;
            }
            res /= i;
            res *= (i - 1);
        }
    }
    cout << res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveB_RoutineProblem() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c * b == a * d) {
        cout << "0/1";
    }
    if (c * b > d * a) {
        int x = c * b;
        int y = x - d * a;
        cout << y / gcd(x, y) << '/' << x / gcd(x, y);
    }
    if (c * b < d * a) {
        int x = a * d;
        int y = x - b * c;
        cout << y / gcd(x, y) << '/' << x / gcd(x, y);
    }
}

void solveB_FoxDividingCheese() {
    int a, b;
    cin >> a >> b;
    int tmp = gcd(a, b);
    a /= tmp;
    b /= tmp;
    int res = 0;
    while (a % 2 == 0) {
        a /= 2;
        res++;
    }
    while (a % 3 == 0) {
        a /= 3;
        res++;
    }
    while (a % 5 == 0) {
        a /= 5;
        res++;
    }
    if (a != 1) {
        cout << -1;
        return;
    }
    while (b % 2 == 0) {
        b /= 2;
        res++;
    }
    while (b % 3 == 0) {
        b /= 3;
        res++;
    }
    while (b % 5 == 0) {
        b /= 5;
        res++;
    }
    if (b != 1) {
        cout << -1;
        return;
    }
    cout << res;
}

void solveB_DrazilAndHisHappyFriends() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int bb, gg;
    cin >> bb;
    for (int i = 0; i < bb; i++) {
        int t; cin >> t;
        a[t] = 1;
    }
    cin >> gg;
    for (int i = 0; i < gg; i++) {
        int t; cin >> t;
        b[t] = 1;
    }
    int tmp = gcd(n, m);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            for (int j = 0; j < m; j++) {
                b[(i + j * tmp) % m] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] == 1) {
            for (int j = 0; j < n; j++) {
                a[(i + j * tmp) % n] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            for (int j = 0; j < m; j++) {
                b[(i + j * tmp) % m] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << "No";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] == 0) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveB_NewYearsEve();
    ///solveB_PrimeMatrix();
    ///solveB_BashsBigDay();
    ///solveA_CowsAndPrimitiveRoots();
    ///solveB_RoutineProblem();
    ///solveB_FoxDividingCheese();
    solveB_DrazilAndHisHappyFriends();
}
