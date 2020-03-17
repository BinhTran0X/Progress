#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

long long MOD = 1e9 + 7;

void FACTGAME() { /// NTUCoder
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> primeList;
    int check[1000000];
    memset(check, 0, sizeof(check));
    check[1] = -1;
    for (int i = 2; i < 1000; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            primeList.push_back(i);
            for (int j = i * i; j < 1000000; j += i) check[j] = 2;
        }
    }
    int p = 0, c = 0, avail = 0;
    for (int i = 0; i < n; i++) {
        if (check[arr[i]] == 1) p++;
        else if (check[arr[i]] == 2) {
            c++;
            int Count = 0;
            for (int j : primeList) {
                if (i % j == 0) {
                }
            }
        }
    }
    if ((p - c) % 2 == 0) {
        if (avail) cout << "ALICE";
        else cout << "BOB";
    }
    else cout << "ALICE";
}

void TITO2() { /// NTUCoder
    long double a, b;
    cin >> a >> b;
    long long s = (long long) a;
    long long e = (long long) b;
    for (long long i = s - 1; i < s + 2; i++) {
        if (i >= a) {
            s = i - 1;
            break;
        }
    }
    for (long long i = e - 1; i < e + 2; i++) {
        if (i > b) {
            e = i - 1;
            break;
        }
    }
    long long res = e * (e + 1) % MOD;
    res = res * (2 * e + 1) % MOD;
    res = res * ((MOD + 1) / 2) % MOD;
    res = res * ((MOD + 1) / 3) % MOD;
    long long tmp =  s * (s + 1) % MOD;
    tmp = tmp * (2 * s + 1) % MOD;
    tmp = tmp * ((MOD + 1) / 2) % MOD;
    tmp = tmp * ((MOD + 1) / 3) % MOD;
    cout << (res - tmp + MOD) % MOD;
}

void OKHOA() { /// NTUCoder
    long long n; cin >> n;
    long long res = n;
    for (int i = 1; i < n; i++) res += (n - i) * i;
    cout << res;
}

void KAGARO() { /// NTUCoder
    int n, a, b;
    cin >> n >> a >> b;
    int x = __gcd(a, b);
    if (n % x != 0) {
        cout << -1;
        return;
    }
    a /= x;
    b /= x;
    n /= x;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    //FACTGAME();
    //TITO2();
    OKHOA();
}
