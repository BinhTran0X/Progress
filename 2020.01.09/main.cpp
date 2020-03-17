#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveB_MakeThemOdd() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n, greater<int>());
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            while (arr[i] % 2 == 0) {
                if (M[arr[i]] == 1) break;
                if (M[arr[i]] == 0) M[arr[i]] = 1;
                arr[i] /= 2;
            }
        }
        //int res = 0;
        //for (auto i : M) res++;
        //cout << res << '\n';
        cout << M.size() << '\n';
    }
}

void solveC_EveryoneIsAWinner() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> res;
        int i = 1;
        while (i <= n) {
            int x = n / i;
            res.push_back(x);
            i = n / x + 1;
        }
        cout << res.size() + 1 << '\n';
        cout << "0 ";
        for (int j = res.size() - 1; j >= 0; j--) cout << res[j] << ' ';
        cout << '\n';
    }
}

void solveA_TilePainting() {
    long long n;
    cin >> n;
    long long res = n;
    for (int i = 2; i <= 1e6 + 5; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res = i;
            break;
        }
    }
    if (res == n) {
        cout << res;
        return;
    }
    if (n == 1) cout << res;
    else cout << 1;
}

void solveA_BearAndPoker() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (arr[i] % 2 == 0) arr[i] /= 2;
        while (arr[i] % 3 == 0) arr[i] /= 3;
    }
    int able = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            able = 0;
            break;
        }
    }
    if (able) cout << "Yes";
    else cout << "No";
}

void solveC_NewYearAndTheSphereTransmission() {
    long long n; cin >> n;
    vector<long long> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            long long tmp = (n / i + 1) * (n + 2) / 2 - n - 1;
            res.push_back(tmp);
            if (i * i != n) {
                int j = n / i;
                tmp = (n / j + 1) * (n + 2) / 2 - n - 1;
                res.push_back(tmp);
            }
        }
    }
    sort(res.begin(), res.end());
    //cout << res.size() << '\n';
    for (long long i : res) cout << i << ' ';
}

int gcd(int a, int b) {
    if (a == 0) return abs(b);
    a = abs(a);
    b = abs(b);
    return gcd(b % a, a);
}

typedef pair<int, int> i2;

void solveD_ZeroQuantityMaximization() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<i2, int> M;
    vector<i2> Key;
    int extra = 0;
    for (int i = 0; i < n; i++) {
        i2 temp;
        if (b[i] == 0) {
            if (a[i] != 0) temp = i2(0, 0);
            else {
                extra++;
                continue;
            }
        }
        else {
            if (a[i] == 0) continue;
            int tmp = gcd(a[i], b[i]);
            if (a[i] < 0) tmp = -tmp;
            temp = i2(a[i] / tmp, b[i] / tmp);
        }
        M[temp] += 1;
        Key.push_back(temp);
    }
    int res = 0;
    for (auto i : Key) res = max(res, M[i]);
    cout << res + extra;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveB_MakeThemOdd();
    ///solveC_EveryoneIsAWinner();
    ///solveA_TilePainting();
    ///solveA_BearAndPoker();
    ///solveC_NewYearAndTheSphereTransmission();
    solveD_ZeroQuantityMaximization();
}
