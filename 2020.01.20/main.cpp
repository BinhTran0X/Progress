#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveD_PetyaAndHisFriends() {
    int n; cin >> n;
    if (n == 2) {
        cout << -1;
        return;
    }
    long long arr[n];
    arr[0] = 2;
    for (int i = 1; i < n - 1; i++) arr[i] = arr[i - 1] * 2;
    arr[0] *= 5;
    arr[n - 1] = 5;
    for (int i = 1; i < n; i++) arr[i] *= 3;
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}

string toString(int a) {
    string res = "";
    while (a) {
        int t = a % 10;
        res += ('0' + t);
        a /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isPalindrome(int a) {
    string tmp = toString(a);
    int n = tmp.size();
    for (int i = 0; i < n; i++) if (tmp[i] != tmp[n - 1 - i]) return false;
    return true;
}

void solveA_PrimesOrPalindromes() {
    long long p, q; cin >> p >> q;
    const int maxN = 1e6;
    int rub[maxN];
    rub[1] = 1;
    for (int i = 2; i < maxN; i++) {
        if (isPalindrome(i)) rub[i] = rub[i - 1] + 1;
        else rub[i] = rub[i - 1];
    }
    //cout << rub[maxN - 1];
    vector<int> primes;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    //cout << (int)primes.size() - 42 * 1998;
    int i;
    for (i = maxN - 1; i > 0; i--) {
        int t = upper_bound(primes.begin(), primes.end(), i) - primes.begin();
        if (rub[i] * p >= q * t) break;
    }
    cout << i;
}

void solveC_TrailingLovesOrLoeufs() {
    const int maxN = 1e6;
    vector<long long> primes;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    long long n, b; cin >> n >> b;
    long long res = 1e18;
    for (long long i : primes) {
        if (b % i != 0 || i > b) continue;
        int e = 0;
        while (b % i == 0) {
            b /= i;
            e++;
        }
        long long ans = 0;
        long long tmp = n;
        while (tmp) {
            tmp /= i;
            ans += tmp;
        }
        ans /= e;
        //cout << i << ' ' << ans << '\n';
        res = min(res, ans);
    }
    if (b != 1) {
        long long tmp = n;
        long long ans = 0;
        while (tmp) {
            tmp /= b;
            ans += tmp;
        }
        res = min(res, ans);
    }
    cout << res;
}

void solveC_DevuAndPartitioningOfTheArray() {
    int n, k, p; cin >> n >> k >> p;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    int oLen = odd.size(), eLen = even.size();
    if (oLen < k - p || (oLen - k + p) % 2 != 0) {
        cout << "NO";
        return;
    }
    if ((oLen - k + p) / 2 + eLen < p) {
        cout << "NO";
        return;
    }
    vector<int> arr[k];
    for (int i = 0; i < k - p; i++) {
        arr[i].push_back(odd[i]);
    }
    for (int i = 0; i < eLen; i++) {
        arr[(k - p + i) % k].push_back(even[i]);
    }
    int x = 0;
    while (k - p + x * 2 < oLen) {
        arr[(k - 1 - x + n / k * k) % k].push_back(odd[k - p + x * 2]);
        arr[(k - 1 - x + n / k * k) % k].push_back(odd[k - p + x * 2 + 1]);
        x++;
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
        cout << arr[i].size() << " ";
        for (int j : arr[i]) cout << j << ' ';
        cout << '\n';
    }
}

void solveB_VeryInterestingGame() {
    long long a, b, mod;
    cin >> a >> b >> mod;
    if (b + 1 >= mod) {
        cout << 2;
        return;
    }
    long long tmp = 1, res = 2e9;
    for (int i = 0; i < 9; i++) tmp = tmp * 10 % mod;
    if (tmp == 0) {
        cout << 2;
        return;
    }
    for (long long i = 0; i < mod; i++) {
        long long temp = i * tmp % mod;
        if (temp > 0 && temp < mod - b) {
            res = i;
            break;
        }
    }
    if (res > a) {
        cout << 2;
        return;
    }
    int len = 9;
    tmp = res;
    while (tmp) {
        tmp /= 10;
        len--;
    }
    cout << "1 ";
    for (int i = 0; i < len; i++) cout << 0;
    cout << res;
}

int getAns(int a, int b) {
    int res = 0;
    while (b != 0) {
        res += a / b;
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return res - 1;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveB_PairsOfNumbers() {
    int n; cin >> n;
    if (n == 1) {
        cout << 0;
        return;
    }
    int res = 1e9;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) != 1) continue;
        res = min(res, getAns(i, n));
    }
    cout << res;
}

void solveB_Colliders() {
    int n, m; cin >> n >> m;
    //int arr[n + 1];
    vector<int> primes;
    int maxN = 1e5 + 1;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < 1000; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i * i; j < maxN; j += i) check[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) check[i] = i;
    }
    int On[maxN];
    memset(On, 0, sizeof(On));
    map<int, set<int>> M;
    while (m--) {
        char x;
        int num;
        cin >> x >> num;
        int tmp = num;
        if (x == '+') {
            if (On[num] == 1) {
                cout << "Already on\n";
                continue;
            }
            int able = 1;
            int conf;
            while (tmp != 1) {
                int p = check[tmp];
                while (tmp % p == 0) tmp /= p;
                if (!M[p].empty()) {
                    able = 0;
                    conf = *M[p].begin();
                    break;
                }
            }
            if (able == 0) {
                cout << "Conflict with " << conf << '\n';
                continue;
            }
            tmp = num;
            while (tmp != 1) {
                int p = check[tmp];
                while (tmp % p == 0) tmp /= p;
                M[p].insert(num);
            }
            On[num] = 1;
            cout << "Success\n";
        }
        else {
            if (On[num] == 0) {
                cout << "Already off\n";
                continue;
            }
            On[num] = 0;
            while (tmp != 1) {
                int p = check[tmp];
                while (tmp % p == 0) tmp /= p;
                M[p].erase(M[p].find(num));
            }
            cout << "Success\n";
        }
    }
}

void solveA_DivisibleBySeven() {
    int arr[] = {1869, 1968, 1689, 6198, 1698, 1986, 1896};
    string s; cin >> s;
    if (s.size() == 4) {
        cout << 1869;
        return;
    }
    vector<char> num;
    int check[] = {0, 0, 0, 0};
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1' && check[0] == 0) {
            check[0] = 1;
            continue;
        }
        if (s[i] == '6' && check[1] == 0) {
            check[1] = 1;
            continue;
        }
        if (s[i] == '8' && check[2] == 0) {
            check[2] = 1;
            continue;
        }
        if (s[i] == '9' && check[3] == 0) {
            check[3] = 1;
            continue;
        }
        num.push_back(s[i]);
    }
    int mod[] = {3, 2, 6, 4, 5, 1};
    string res = "";
    int len = num.size();
    long long ans = (num[len - 1] - '0') % 7;
    res += num[len - 1];
    int i;
    for (i = 0; i < len - 1; i++) {
        res += num[i];
        ans = (ans + mod[i % 6] * (num[i] - '0')) % 7;
        //cout << ans << ' ';
    }
    int j;
    for (j = 0; j < 7; j++) {
        if ((j * mod[i % 6] + ans) % 7 == 0) break;
    }
    reverse(res.begin(), res.end());
    cout << arr[j] << res;
    //cout << res << ' ' << ans << ' ';
    //reverse(res.begin(), res.end());
    //cout << res << arr[6 - ans];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveD_PetyaAndHisFriends();
    ///solveA_PrimesOrPalindromes();
    ///solveC_TrailingLovesOrLoeufs();
    ///solveC_DevuAndPartitioningOfTheArray();
    ///solveB_VeryInterestingGame();
    ///solveB_PairsOfNumbers();
    ///solveB_Colliders();
    solveA_DivisibleBySeven();
}
