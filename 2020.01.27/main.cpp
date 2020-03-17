#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int MOD = 1e9 + 7;

long long Pow(long long b, int e = MOD - 2) {
    if (e == 0) return 1LL;
    long long x = Pow(b, e / 2);
    if (e % 2 == 0) return x * x;
    return x * x * b;
}

struct factor {
    long long p;
    int e1, e2;
    factor() {}
    factor(long long _p, int _e1, int _e2) {
        p = _p;
        e1 = _e1;
        e2 = _e2;
    }
};

void solveB_NastyaStudiesInformatics() {
    vector<long long> primes;
    const int maxN = 1e5;
    int check[maxN];
    memset(check, 0, sizeof(check));
    for (int i = 2; i < maxN; i++) {
        if (check[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) check[j] = 1;
        }
    }
    long long l, r, x, y;
    cin >> l >> r >> x >> y;
    if (x == y) {
        if (x <= r && x >= l) cout << 1;
        else cout << 0;
        return;
    }
    map<long long, int> xFactor, yFactor;
    long long prod = x * y;
    for (long long i : primes) {
        if (x % i == 0) {
            int c = 0;
            while (x % i == 0) {
                x /= i;
                c++;
            }
            xFactor[i] = c;
        }
        if (y % i == 0) {
            int c = 0;
            while (y % i == 0) {
                y /= i;
                c++;
            }
            yFactor[i] = c;
        }
    }
    vector<factor> choice;
    int able = 1;
    long long same = 1;
    for (long long i : primes) {
        if (yFactor[i] != 0 || xFactor[i] != 0) {
            if (xFactor[i] == yFactor[i]) {
                same *= Pow(i, xFactor[i]);
                prod /= Pow(i, 2 * xFactor[i]);
                continue;
            }
            choice.push_back(factor(i, xFactor[i], yFactor[i]));
        }
        if (xFactor[i] > yFactor[i]) {
            able = 0;
            break;
        }
    }
    if (able == 0) {
        cout << 0;
        return;
    }
    if (x != y) {
        if (x != 1) choice.push_back(factor(x, 1, 0));
        if (y != 1) choice.push_back(factor(y, 0, 1));
    }
    else if (x != 1) {
        prod /= x * x;
        same *= x;
    }
    //cout << prod << ' ';
    long long state = Pow(2, (int)choice.size());
    int res = 0;
    for (int i = 0; i < state; i++) {
        int t = i;
        long long tmp = 1;
        for (int i = 0; i < (int)choice.size(); i++) {
            if (t % 2 == 0) tmp *= Pow(choice[i].p, choice[i].e1);
            else tmp *= Pow(choice[i].p, choice[i].e2);
            t /= 2;
        }
        if (l <= tmp * same && r >= tmp * same) {
            //cout << tmp << ' ' << prod / tmp << '\n';
            tmp = prod / tmp;
            if (l <= tmp * same && r >= tmp * same) {
                res++;
                //cout << tmp << '\n';
            }
        }
    }
    cout << res;
}

const int maxN = 1e6 + 1;
int prime[maxN];

void seive() {
    for (int i = 2; i < 1000; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < maxN; j += i) prime[j] = i;
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (prime[i] == 0) prime[i] = i;
    }
}

void solveA_TheMeaninglessGame() {
    int n; cin >> n;
    seive();
    while (n--) {
        long long a, b;
        cin >> a >> b;
        long long prod = a * b;
        long long c = cbrt(prod);
        if (c * c * c < prod) c++;
        if (c * c * c != prod) {
            cout << "No\n";
            continue;
        }
        int able = 1;
        while (c != 1) {
            int p = prime[c];
            int pa = 0, pb = 0;
            while (a % p == 0) {
                pa++;
                a /= p;
            }
            while (b % p == 0) {
                pb++;
                b /= p;
            }
            while (c % p == 0) c/= p;
            if (2 * pa - pb < 0 || 2 * pb - pa < 0) {
                able = 0;
                break;
            }
        }
        if (able) cout << "Yes\n";
        else cout << "No\n";
    }
}

double winnerOfTheGameOfMarbles(int a, int b) { /// CodeLearn
    if (a == 0 || b == 0) return 1;
    long double res = double(a) / (a + b);
    long double tmp = 1;
    while (b - 2 >= 0) {
        tmp = tmp * b / (a + b);
        tmp = tmp * (b - 1) / (a + b - 1);
        res += tmp * a / (a + b - 2);
        b -= 2;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    solveB_NastyaStudiesInformatics();
    ///solveA_TheMeaninglessGame();
    //cout << winnerOfTheGameOfMarbles(3, 2);
}
