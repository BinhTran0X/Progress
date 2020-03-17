#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void solveD_Chocolate() {
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int f2 = 0, f3 = 0, s2 = 0, s3 = 0;
    long long x = a1 * b1, y = a2 * b2;
    while (x % 2 == 0) {
        x /= 2;
        f2++;
    }
    while (y % 2 == 0) {
        y /= 2;
        s2++;
    }
    while (x % 3 == 0) {
        x /= 3;
        f3++;
    }
    while (y % 3 == 0) {
        y /= 3;
        s3++;
    }
    if (x != y) {
        cout << -1;
        return;
    }
    int res = 0;
    while (f3 > s3) {
        f3--;
        f2++;
        res++;
        if (a1 % 3 == 0) a1 = a1 / 3 * 2;
        else b1 = b1 / 3 * 2;
    }
    while (s3 > f3) {
        s3--;
        s2++;
        res++;
        if (a2 % 3 == 0) a2 = a2 / 3 * 2;
        else b2 = b2 / 3 * 2;
    }
    while (f2 > s2) {
        f2--;
        res++;
        if (a1 % 2 == 0) a1 /= 2;
        else b1 /= 2;
    }
    while (s2 > f2) {
        s2--;
        res++;
        if (a2 % 2 == 0) a2 /= 2;
        else b2 /= 2;
    }
    cout << res << '\n';
    cout << a1 << ' ' << b1 << '\n';
    cout << a2 << ' ' << b2 << '\n';
}

void solveF_VideoCards() {
    int n; cin >> n;
    long long arr[n];
    const int maxN = 2e5 + 5;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long res[n];
    memset(res, 0, sizeof(res));
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n; i++) {
        long long tmp = arr[i];
        if (check[tmp] == 1) continue;
        for (int j = tmp; j < maxN; j += tmp) check[j] = 1;
        for (int j = 1; j * tmp <= arr[n - 1]; j++) {
            int r = lower_bound(arr, arr + n, j * tmp + tmp) - arr;
            int l = lower_bound(arr, arr + n, j * tmp) - arr;
            //cout << l << ' ' << r << '\n';
            res[i] += (r - l) * tmp * j;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, res[i]);
    //for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << ans;
}

const int maxN = 1e6 + 5;
int prime[maxN];

void Sieve() {
    for (int i = 0; i < maxN; i++) prime[i] = i;
    for (int i = 2; i < maxN; i++) {
        if (prime[i] != i) continue;
        for (int j = i; j < maxN; j += i) prime[j] = i;
    }
}

int digitalRoot(int x) {
    int tmp = 0;
    while (x >= 10) {
        while (x) {
            tmp += x % 10;
            x /= 10;
        }
        x = tmp;
        tmp = 0;
    }
    return x;
}

void solveC_DigitalRoot() {
    Sieve();
    int n; cin >> n;
    int C[10];
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= n; i++) C[digitalRoot(i)]++;

}

const long long MOD = 1e9 + 7;

long long Pow(long long b, int e) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveE_Unsolvable() {
    vector<int> res = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127,
                        521, 607, 1279, 2203, 2281, 3217, 4253, 4423,
                        9689, 9941, 11213, 19937, 21701, 23209, 44497,
                        86243, 110503, 132049, 216091, 756839, 859433,
                        1257787, 1398269, 2976221, 3021377, 6972593,
                        13466917, 20996011};
    int n; cin >> n;
    cout << Pow(2, res[n - 1] - 1) - 1;
}

typedef pair<long long, int> i2;

void solveC_PrimeNumber() {
    int n, x; cin >> n >> x;
    long long arr[n], m = -1;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
        m = max(m, arr[i]);
    }
    for (int i = 0; i < n; i++) arr[i] = m - arr[i];
    sort(arr, arr + n);
    vector<i2> lis;
    int id = 0;
    while (id < n) {
        int c = 0;
        long long tmp = arr[id];
        while (id < n && arr[id] == tmp) {
            id++;
            c++;
        }
        lis.push_back(i2(tmp, c));
    }
    //for (i2 i : lis) cout << i.first << ' ' << i.second << '\n';
    int len = lis.size();
    long long res = s - m;
    int i = 0;
    while (i < len) {
        if (lis[i].second % x == 0) {
            res++;
            if (i == len - 1) {
                lis[i].second /= x;
                while (lis[i].second % x == 0) {
                    lis[i].second /= x;
                    res++;
                }
                break;
            }
            if (lis[i + 1].first == lis[i].first + 1) {
                lis[i + 1].second += lis[i].second / x;
                i++;
            }
            else {
                lis[i].first++;
                lis[i].second /= x;
            }
        }
        else break;
    }
    res = min(res, s);
    cout << Pow(x, res);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveD_Chocolate();
    ///solveF_VideoCards();
    //solveC_DigitalRoot();
    ///solveE_Unsolvable();
    solveC_PrimeNumber();
}
