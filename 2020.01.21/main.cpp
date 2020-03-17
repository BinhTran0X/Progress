#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void EqualSubarrays() { /// HackerEarth
    int n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    multiset<long long> res;
    long long val = 0, Sum = 0;
    int pt1 = 0, pt2 = 0;
    int ans = 0;
    while (pt2 < n) {
        res.insert(arr[pt2]);
        Sum += arr[pt2];
        long long maxx = *--res.end();
        //cout << maxx << ' ';
        val = maxx * (pt2 - pt1 + 1) - Sum;
        while (val > k) {
            //if (res.find(arr[pt1]) != res.end())
            res.erase(res.find(arr[pt1]));
            Sum -= arr[pt1];
            val = *--res.end() * (pt2 - pt1) - Sum;
            pt1++;
        }
        ans = max(ans, pt2 - pt1 + 1);
        pt2++;
    }
    cout << ans;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveC_Border() {
    int n, k; cin >> n >> k;
    int arr[n];
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= k;
        tmp = gcd(tmp, arr[i]);
    }
    set<long long> res;
    for (int i = 0; i < k; i++) res.insert(1LL * tmp * i % k);
    cout << res.size() << '\n';
    for (auto i : res) cout << i << ' ';
}

const long long MOD = 1e9 + 7;

long long Pow(long long b, long long e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

void solveD_IteratedLinearFunction() {
    long long a, b, n, x;
    cin >> a >> b >> n >> x;
    long long res = Pow(a, n) * x % MOD;
    long long tmp;
    if (a != 1) {
        tmp = Pow(a, n) - 1;
        tmp = tmp * Pow(a - 1) % MOD;
    }
    else tmp = n % MOD;
    tmp = tmp * b % MOD;
    res = (res + tmp) % MOD;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///EqualSubarrays();
    ///solveC_Border();
    solveD_IteratedLinearFunction();
}
