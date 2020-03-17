#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

typedef pair<int, int> i2;

const int maxN = 1e5 + 5;
int k;
int prime[maxN];

void Sieve() {
    for (int i = 2; i * i < maxN; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
}

void Sang() {
    for (int i = 0; i < maxN; i++) prime[i] = i;
    for (int i = 2; i < maxN; i++) {
        if (prime[i] != i) continue;
        for (int j = i; j < maxN; j += i) prime[j] = i;
    }
}

vector<i2> factorize(int n) {
    vector<i2> res;
    while (n != 1) {
        int p = prime[n];
        int e = 0;
        while (n % p == 0) {
            e++;
            n /= p;
        }
        e %= k;
        if (e == 0) continue;
        res.push_back(i2(p, e));
    }
    return res;
}

void solveD_PowerProducts() {
    Sang();
    /*
    Sang();
    for (int i = 0; i < 100; i++) cout << prime[i] << ' ';
    cout << endl;
    memset(prime, 0, sizeof(prime));
    Sieve();
    for (int i = 0; i < 100; i++) cout << prime[i] << ' ';
    */
    int n; cin >> n >> k;
    map<vector<i2>, int> M;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vector<i2> tmp = factorize(x);
        res += M[tmp];
        for (auto &i : tmp) {
            i.second = (k - i.second) % k;
        }
        M[tmp]++;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveD_PowerProducts();
}
