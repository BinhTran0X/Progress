#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveC_FindMaximum() {
    int n; cin >> n;
    int a[n + 1], pre[n + 1], s[n + 1];
    memset(pre, 0, sizeof(pre));
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    string bin; cin >> bin;
    for (int i = 0; i < n; i++) {
        if (bin[i] == '1') pre[i + 1] = pre[i] + a[i + 1];
        else pre[i + 1] = pre[i];
    }
    //for (int i = 0; i <= n; i++) cout << pre[i] << ' ';
    long long res = pre[n];
    for (int i = 0; i < n; i++) {
        if (bin[i] == '1') {
            long long tmp = pre[n] - pre[i + 1] + s[i];
            res = max(res, tmp);
        }
    }
    cout << res;
}

void solveB_WellKnownNumbers() {
    long long s, k; cin >> s >> k;
    long long a[50], ss[50];
    a[1] = 1;
    a[0] = 0;
    ss[0] = 0;
    ss[1] = 1;
    for (int i = 2; i < 50; i++) {
        a[i] = ss[i - 1];
        //if (i > k) a[i] -= a[i - k];
        ss[i] = ss[i - 1] + a[i];
        if (i > k) ss[i] -= a[i - k];
    }
    //for (int i = 0; i < 50; i++) cout << a[i] << ' ';
    vector<long long> res;
    while (s != 0) {
        int p = lower_bound(a, a + 50, s) - a;
        if (a[p] == s) {
            res.push_back(s);
            res.push_back(0);
            break;
        }
        else {
            res.push_back(a[p - 1]);
            s -= a[p - 1];
        }
    }
    cout << res.size() << '\n';
    for (long long i : res) cout << i << ' ';
}

void something() {
    string s = "qd ucyhf yi q fhycu dkcruh mxeiu huluhiu yi q tyvvuhudj fhycu dkcruh. oekh jqia yi je vydt jxu djx ucyhf";
    int n = s.size();
    string a = "abcdefghijklmnopqrstuvwxyz";
    for (int j = 1; j < 26; j++) {
        string t = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') t += s[i];
            else {
                int xx = s[i] - 'a' + j;
                if (xx >= 26) xx -= 26;
                char tmp = 'a' + xx;
                t += tmp;
            }
        }
        cout << j << " " <<  t << '\n';
    }
}

bool isPrime(int a, vector<int> p) {
    int pos = lower_bound(p.begin(), p.end(), a) - p.begin();
    if (pos == (int)p.size()) return false;
    if (p[pos] == a) return true;
    return false;
}

int revInt(int a) {
    int ans = 0;
    while (a) {
        ans = ans * 10 + a % 10;
        a /= 10;
    }
    return ans;
}

void solveF_ucyhf10emirp() {
    int d; cin >> d;
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
    vector<int> res;
    for (int i : primes) {
        if (i < 10) continue;
        int tmp = revInt(i);
        if (tmp == i) continue;
        if (isPrime(tmp, primes)) res.push_back(i);
    }
    sort(res.begin(), res.end());
    cout << res[d - 1];
    //cout << res[tmp - 1];
}

void solveC_HackingCypher() {
    string s; cin >> s;
    int a, b; cin >> a >> b;
    int n = s.size();
    if (n < 2) {
        cout << "NO";
        return;
    }
    int pre[n], suf[n], ten[n];
    ten[0] = 1;
    for (int i = 1; i < n; i++) {
        ten[i] = ten[i - 1] * 10 % b;
    }
    pre[0] = (s[0] - '0') % a;
    for (int i = 1; i < n - 1; i++) {
        pre[i] = pre[i - 1] * 10 + (s[i] - '0');
        pre[i] %= a;
    }
    suf[n - 2] = (s[n - 1] - '0') % b;
    for (int i = n - 3; i >= 0; i--) {
        if (i < 0) break;
        suf[i] = suf[i + 1] + ten[n - 2 - i] * (s[i + 1] - '0');
        suf[i] %= b;
    }
    /*
    for (int i = 0; i < n; i++) cout << pre[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << suf[i] << ' ';
    */
    for (int i = 0; i < n - 1; i++) {
        if (pre[i] == 0 && suf[i] == 0 && s[i + 1] != '0') {
            cout << "YES\n";
            for (int j = 0; j <= i; j++) cout << s[j];
            cout << '\n';
            for (int j = i + 1; j < n; j++) cout << s[j];
            return;
        }
    }
    cout << "NO";
}

void solveA_PrimalSport() {
    int x; cin >> x;
    const int maxN = 1e6 + 1;
    int maxPrime[maxN];
    memset(maxPrime, 0, sizeof(maxPrime));
    for (int i = 2; i < maxN; i++) {
        if (maxPrime[i] == 0) {
            for (int j = i; j < maxN; j += i) maxPrime[j] = i;
        }
    }
    //for (int i = 2; i < maxN; i++) cout << maxPrime[i] << ' ';
    int res = 1e9;
    for (int i = 0; i < maxPrime[x]; i++) {
        int tmp = x - i;
        int ans = tmp - maxPrime[tmp] + 1;
        if (ans != 1) res = min(res, ans);
    }
    cout << res;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solveA_EnlargeGCD() {
    int n; cin >> n;
    int arr[n];
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp = gcd(tmp, arr[i]);
    }
    for (int i = 0; i < n; i++) arr[i] /= tmp;
    int isOne = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 1) {
            isOne = 0;
            break;
        }
    }
    if (isOne) {
        cout << -1;
        return;
    }
    int maxN = 15e6 + 1;
    int prime[maxN];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < 4e3; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
    map<int, int> M;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (arr[i] != 1) {
            int tmp = prime[arr[i]];
            while (arr[i] % tmp == 0) {
                arr[i] /= tmp;
            }
            M[tmp]++;
        }
    }
    for (pair<int, int> i : M) res = max(res, i.second);
    cout << n - res;
}

void solveK_Indivisibility() {
    long long n; cin >> n;
    long long res = n - n / 2 - n / 3 - n / 5 - n / 7;
    res += n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35;
    res -= n / 30 + n / 42 + n / 70 + n / 105;
    res += n / 210;
    cout << res;
}

void solveD_DimaAndLisa() {
    int maxN = 4e4;
    int check[maxN];
    memset(check, 0, sizeof(check));
    vector<int> primes;
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    int n; cin >> n;
    vector<int> res;
    for (int i = 0; i < 300; i++) {
        int tmp = n - i;
        int able = 1;
        for (int j : primes) {
            if (j == tmp) break;
            if (tmp % j == 0) {
                able = 0;
                break;
            }
        }
        if (able) {
            res.push_back(tmp);
            n = i;
            break;
        }
    }
    if (n == 0) {
        cout << "1\n" << res[0];
        return;
    }
    int p = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
    if (primes[p] == n) {
        cout << "2\n" << res[0] << " " << n;
        return;
    }
    for (int i : primes) {
        int pos = lower_bound(primes.begin(), primes.end(), n - i) - primes.begin();
        if (primes[pos] == n - i) {
            res.push_back(i);
            res.push_back(n - i);
            break;
        }
    }
    cout << "3\n";
    for (int i : res) cout << i << ' ';
}

bool Check(int e1, int e2) {
    if (e1 > e2) swap(e1, e2);
    for (int i = 0; i <= e1; i++) {
        if ((e1 - i) % 2 == 1) continue;
        if (i * 2 + (e1 - i) / 2 == e2) return true;
    }
    return false;
}

void solveA_TheMeaninglessGame() {
    const int maxN = 1e6 + 1;
    int prime[maxN];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= 1000; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 1; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
    int n; cin >> n;
    //for (int i = 0; i < 1e4; i++) cout << prime[i] << " ";
    while (n--) {
        int a, b; cin >> a >> b;
        int able = 1;
        while (a != 1 || b != 1) {
            if (prime[a] != prime[b]) {
                able = 0;
                break;
            }
            int p = prime[a];
            int aa = 0, bb = 0;
            while (a % p == 0) {
                a /= p;
                aa++;
            }
            while (b % p == 0) {
                b /= p;
                bb++;
            }
            if (!Check(aa, bb)) {
                able = 0;
                break;
            }
        }
        if (able) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveC_FindMaximum();
    ///solveB_WellKnownNumbers();
    ///solveF_ucyhf10emirp(); //something();
    ///solveC_HackingCypher();
    ///solveA_PrimalSport();
    ///solveA_EnlargeGCD();
    ///solveK_Indivisibility();
    ///solveD_DimaAndLisa();
    solveA_TheMeaninglessGame();
}
