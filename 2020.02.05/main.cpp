#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveB_GoodSequences() {
    const int maxN = 1e5 + 5;
    int prime[maxN];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < 1000; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
    int n; cin >> n;
    int arr[n];
    vector<int> Pos[maxN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int tmp = arr[i];
        while (tmp != 1) {
            int p = prime[tmp];
            while (tmp % p == 0) tmp /= p;
            Pos[p].push_back(arr[i]);
        }
    }
    if (n == 1) {
        cout << 1;
        return;
    }
    int res[maxN];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) continue;
        if (prime[arr[i]] == arr[i]) {
            res[arr[i]] = 1;
            continue;
        }
        int tmp = arr[i];
        while (tmp != 1) {
            int p = prime[tmp];
            while (tmp % p == 0) tmp /= p;
            auto pos = lower_bound(Pos[p].begin(), Pos[p].end(), arr[i]);
            if (pos == Pos[p].begin()) res[arr[i]] = max(1, res[arr[i]]);
            else res[arr[i]] = max(res[*--pos] + 1, res[arr[i]]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, res[arr[i]]);
    //for (int i = 0; i < n; i++) cout << res[arr[i]] << ' ';
    cout << ans;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solveC_MikeAndGCDProblem() {
    int n; cin >> n;
    int arr[n];
    int p = 0, even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 1) odd++;
        else even++;
        p = gcd(p, arr[i]);
        arr[i] = arr[i] % 2;
    }
    if (p != 1) {
        cout << "YES\n0";
        return;
    }
    if (even == 0 && odd % 2 == 1) {
        cout << "NO";
        return;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        while (arr[i] == 1) {
            c++;
            i++;
            if (i >= n) break;
        }
        if (c % 2 == 0) res += c / 2;
        else res+= (c + 1) / 2 + 1;
    }
    cout << "YES\n" << res;
}

void solveD_VasyaAndTriangle(){
    vector<int> primes;
    const int maxN = 1e5;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    long long n, m, k, N, M, K; cin >> N >> M >> K;
    n = N;
    m = M;
    k = K;
    int able = 1;
    int done = 0;
    for (int i : primes) {
        while (k % i == 0) {
            if (n % i == 0) n /= i;
            else if (m % i == 0) m /= i;
            else {
                if (i == 2 && done == 0) {
                    done = 1;
                }
                else {
                    able = 0;
                    break;
                }
            }
            k /= i;
        }
    }
    if (k != 1) {
        if (n % k == 0) n /= k;
        else if (m % k == 0) m /= k;
        else able = 0;
    }
    if (able == 0) {
        cout << "NO";
        return;
    }
    if (done == 0) {
        if (n * 2 <= N) n *= 2;
        else if (m * 2 <= M) m *= 2;
    }
    if (m * n * K != M * N * 2) {
        cout << "NO";
        return;
    }
    cout << "YES\n0 0\n" << "0 " << m << '\n' << n << " 0";
}

void solveC_WetSharkAndFlowers() {
    int n, p; cin >> n >> p;
    long double prob[n];
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        prob[i] = (r / p - (l - 1) / p) / (double)(r - l + 1);
        //cout << prob[i] << ' ';
    }
    long double res = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            res += prob[i] + prob[0] - prob[i] * prob[0];
        }
        else {
            res += prob[i] + prob[i + 1] - prob[i] * prob[i + 1];
        }
    }
    res *= 2000;
    cout << fixed << setprecision(10) << res;
}

void solveA_GCDTable() {
    int n; cin >> n;
    int arr[n * n];
    for (int i = 0; i < n * n; i++) cin >> arr[i];
    sort(arr, arr + n * n);
    int ans[n][n];
    map<int,int> M;
    for (int i = 0; i < n * n; i++) {
        M[arr[i]]++;
        //cout << arr[i] << ' ';
    }
    int i = n * n - 2;
    ans[0][0] = arr[n * n - 1];
    int j = 1;
    M[arr[n * n - 1]]--;
    while (i >= 0) {
        if (M[arr[i]] == 0) {
            i--;
            continue;
        }
        //cout << arr[i] << '\n';
        ans[j][j] = arr[i];
        //cout << ans[j][j] << '\n';
        M[arr[i]]--;
        for (int k = 0; k < j; k++) {
            int tmp = gcd(ans[j][j], ans[k][k]);
            ans[k][j] = ans[j][k] = tmp;
            M[tmp] -= 2;
        }
        i--;
        j++;
    }
    for (int i = 0; i < n; i++) cout << ans[i][i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveB_GoodSequences();
    ///solveC_MikeAndGCDProblem();
    ///solveD_VasyaAndTriangle();
    ///solveC_WetSharkAndFlowers();
    solveA_GCDTable();
}
