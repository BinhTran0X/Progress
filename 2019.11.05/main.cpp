#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int maxN = 1e6 + 1;
vector<int> DP[9 * maxN];

void LSTBTF() { ///CodeChef
    DP[1].push_back(1);
    for (int i = 2; i < 9 * maxN; i++) {
        for (int j = 1; j < 10; j++) {
            if (i - j * j >= 0) {
                for (int k : DP[j]) DP[i].push_back(k + 1);
            }
            else break;
        }
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
    }
}

const int oo = 2e9;

struct i2 {
    int x, y;
    i2() {}
    i2(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

bool compare(i2 a, i2 b) {
    return a.x < b.x;
}

void CAMC() { /// CodeChef
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        i2 A[n];
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            A[i] = i2(x, i % m);
        }
        sort(A, A + n, compare);
        queue<i2> Q;
        int arr[m];
        for (int i = 0; i < m; i++) arr[i] = 0;
        int Count = m;
        int res = oo;
        for (int i = 0; i < n; i++) {
            Q.push(A[i]);
            if (arr[A[i].y] == 0) Count--;
            arr[A[i].y]++;
            while (Count == 0) {
                res = min(res, Q.back().x - Q.front().x);
                arr[Q.front().y]--;
                if (arr[Q.front().y] == 0) Count++;
                Q.pop();
            }
        }
        cout << res << '\n';
    }
}

int main()
{
    rwFile();
    CAMC();
    //LSTBTF();
}
