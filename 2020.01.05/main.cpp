#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

struct i2 {
    int x, y;
    i2() {}
    i2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    bool operator==(i2 a) {
        return a.x == x && a.y == y;
    }
};

int res[2002][2002];

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void DFMTRX() { /// CodeChef
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "Hooray\n1\n";
            continue;
        }
        if (n % 2 == 1) {
            cout << "Boo\n";
            continue;
        }
        //i2 arr[n][n / 2];
        for (int i = 1; i < n; i++) {
            int diff = i;
            if (i == 2) cout << "lala";
            //int pos = 0;
            int len = gcd(n, diff);
            for (int j = 0; j < len; j++) {
                int last = 1 + j + diff;
                i2 End = i2(1 + j, 1 + j + diff);
                res[1 + j][1 + j + diff] = i;
                //if (diff == 2) cout << res[1 + j][1 + j + diff];
                res[1 + j + diff][1 + j] = 2 * n - i;
                //arr[i][pos++] = End;
                while (true) {
                    i2 newI2 = i2(last + diff, last + diff * 2);
                    while (newI2.x > n) newI2.x -= n;
                    while (newI2.y > n) newI2.y -= n;
                    if (newI2 == End) {
                        //last = arr[i][0].x + 1;
                        break;
                    }
                    //arr[i][pos++] = newI2;
                    res[newI2.x][newI2.y] = i;
                    res[newI2.y][newI2.x] = 2 * n - i;
                    last = last + 2 * diff;
                    while (last > n) last -= n;
                }
            }
        }
        /*
        for (int i = 1; i <= n; i++) res[i][i] = n;
        for (int i = 1; i < n; i++) {
            for (i2 tmp : arr[i]) {
                res[tmp.x][tmp.y] = i;
                res[tmp.y][tmp.x] = 2 * n - i;
            }
        }
        */
        cout << "Hooray\n";
        for (int i = 0; i <= n; i++) res[i][i] = n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) cout << res[i][j] << ' ';
            cout << '\n';
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (res[i][j] == 4) cout << i << ' ' << j << ' ';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    DFMTRX();
}
