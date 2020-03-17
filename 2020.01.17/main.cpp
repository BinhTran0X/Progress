#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveF_CliqueInTheDivisibilityGraph() {
    int n; cin >> n;
    int maxN = 1e6 + 1;
    int c[maxN], arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        c[arr[i]]++;
        for (int j = arr[i] * 2; j < maxN; j += arr[i]) {
            c[j] = max(c[j], c[arr[i]]);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, c[arr[i]]);
    cout << res;
}

void solveB_ModularEquations() {
    int a, b; cin >> a >> b;
    if (a == b) {
        cout << "infinity";
        return;
    }
    if (a < b) {
        cout << 0;
        return;
    }
    int tmp = a - b;
    vector<int> div;
    for (int i = 1; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            div.push_back(i);
            if (i * i != tmp) div.push_back(tmp / i);
        }
    }
    sort(div.begin(), div.end());;
    int pos = upper_bound(div.begin(), div.end(), b) - div.begin();
    cout << div.size() - pos;
}

bool isPrime(int n, vector<int> primes) {
    for (int i : primes) {
        if (n == i) return true;
        if (n % i == 0) return false;
    }
    return true;
}

void solveD_Taxes() {
    vector<int> primes;
    int n, maxN = 1e5;
    int check[maxN];
    cin >> n;
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    if (n == 2) {
        cout << 1;
        return;
    }
    if (n % 2 == 0) cout << 2;
    else {
        if (isPrime(n, primes)) cout << 1;
        else {
            if (isPrime(n - 2, primes)) cout << 2;
            else cout << 3;
        }
    }
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void solveC_JotyAndChocolate() {
    long long n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    long long res = n / a * p + n / b * q - n / lcm(a, b) * min(p, q);
    cout << res;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveA_AliceAndBob() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int tmp = a[0];
    int maxx = a[0];
    for (int i = 1; i < n; i++) {
        tmp = gcd(a[i], tmp);
        maxx = max(maxx, a[i]);
    }
    int res = maxx / tmp - n;
    if (res % 2 == 1) cout << "Alice";
    else cout << "Bob";
}

void solveB_WeakenedCommonDivisor() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<int> primes;
    int maxN = 5e4;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    vector<int> res;
    for (int i : primes) {
        if (a[0] % i == 0 || b[0] % i == 0) {
            res.push_back(i);
            while (a[0] % i == 0) a[0] /= i;
            while (b[0] % i == 0) b[0] /= i;
        }
    }
    if (a[0] != 1) res.push_back(a[0]);
    if (b[0] != 1) res.push_back(b[0]);
    int ans = -1;
    for (int tmp : res) {
        int able = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] % tmp != 0 && b[i] % tmp != 0) {
                able = 0;
                break;
            }
        }
        if (able) {
            ans = tmp;
            break;
        }
    }
    cout << ans;
}

void solveA_WinOrFreeze() {
    long long q;
    cin >> q;
    if (q == 1) {
        cout << "1\n0";
        return;
    }
    vector<int> primes;
    int maxN = 1e6;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    int c = 0;
    long long tmp = q;
    for (int i : primes) {
        if (tmp % i == 0) {
            while (tmp % i == 0) {
                c++;
                tmp /= i;
            }
        }
    }
    if (tmp != 1 && c == 0) {
        cout << "1\n0";
        return;
    }
    if (tmp != 1) c++;
    if (c == 2) {
        cout << 2;
        return;
    }
    if (c < 2) {
        cout << "1\n0";
        return;
    }
    long long res = 1;
    int cc = 0;
    for (int i : primes) {
        if (q % i == 0) {
            while (q % i == 0 && cc < 2) {
                res *= i;
                cc++;
                q /= i;
            }
        }
        if (cc == 2) break;
    }
    cout << "1\n" << res;
}

void solveC_BlockTowers() {
    int n, m; cin >> n >> m;
    int i, two = 0, three = 0, six = 0, maxN = 1e7;
    for (i = 1; i < maxN; i++) {
        if (i % 2 == 0) {
            if (i % 3 == 0) six++;
            else two++;
        }
        else if (i % 3 == 0) three++;
        if (two >= n) {
            if (three + six >= m) break;
        }
        if (three >= m) {
            if (two + six >= n) break;
        }
        if (two < n && three < m && two + three + six >= m + n) break;
    }
    cout << i;
}

void solveC_CavePainting() {
    long long n, k; cin >> n >> k;
    long long maxN = min(10000000LL, k);
    vector<int> res;
    for (int i = 1; i <= maxN; i++) res.push_back(n % i);
    sort(res.begin(), res.end());
    int able = 0;
    for (int i = 0; i < (int)res.size() - 1; i++) {
        if (res[i] == res[i + 1]) {
            able = 1;
            break;
        }
    }
    if (able) cout << "No";
    else cout << "Yes";
}

void solveC_PrimesOnInterval() {
    const int maxN = 1e6 + 5;
    int check[maxN];
    memset(check, 0, sizeof(check));
    vector<int> primes;
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    int a, b, k;
    cin >> a >> b >> k;
    int res, l = 1, r = b - a + 2;
    int t = 0;
    while (l < r) {
        res = (l + r) / 2;
        int able = 1;
        for (int x = a; x <= b - res + 1; x++) {
            int s = lower_bound(primes.begin(),primes.end(), x) - primes.begin();
            int e = upper_bound(primes.begin(),primes.end(), x + res - 1) - primes.begin();
            //if (x == 8) cout << s << " " << e << " " << res << '\n';
            int tmp = e - s;
            //if (primes[e] > b) tmp--;
            if (tmp < k) {
                able = 0;
                break;
            }
        }
        //cout << res << " " << able << '\n';
        if (able == 0) {
            l = res + 1;
        }
        else {
            r = res;
        }
        t++;
        //if (t == 10) break;
    }
    res = (l + r) / 2;
    if (res == b - a + 2) cout << -1;
    else cout << res;
}

bool checkPrime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solveA_PrimePermutation() {
    string s; cin >> s;
    int n = s.size();
    int c = n - 1;
    int res[n];
    memset(res, 0, sizeof(res));
    res[0] = -1;
    for (int i = n / 2 + 1; i <= n; i++) {
        if (checkPrime(i)) {
            c--;
            res[i - 1] = -1;
        }
    }
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
        arr[s[i] - 'a']++;
    }
    //for (int i = 0; i < n; i++) cout << res[i] << ' ';
    int able = 0;
    if (c == 0) {
        cout << "YES\n" << s;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] >= c) {
            able = 1;
            for (int j = 0; j < n; j++) {
                if (res[j] == 0) {
                    res[j] = i;
                    arr[i]--;
                }
            }
            break;
        }
    }
    if (able == 0) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (res[i] == -1) {
            for (int j = 0; j < 26; j++) {
                if (arr[j] > 0) {
                    res[i] = j;
                    arr[j]--;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        char x = res[i] + 'a';
        cout << x;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveF_CliqueInTheDivisibilityGraph();
    ///solveB_ModularEquations();
    ///solveD_Taxes();
    ///solveC_JotyAndChocolate();
    ///solveA_AliceAndBob();
    ///solveB_WeakenedCommonDivisor();
    ///solveA_WinOrFreeze();
    ///solveC_BlockTowers();
    ///solveC_CavePainting();
    solveC_PrimesOnInterval();
    ///solveA_PrimePermutation();
}
