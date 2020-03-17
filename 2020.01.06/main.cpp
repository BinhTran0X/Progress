#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void ENGLISH() { /// CodeChef
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int res[n - 1];
        for (int i = 0; i < n - 1; i++) {
            int c = 0;
            int len = min(arr[i].size(), arr[i + 1].size());
            for (int j = 0; j < len; j++) {
                if (arr[i][j] == arr[i + 1][j]) c++;
                else break;
            }
            res[i] = c * c;
        }
        int ans[n];
        ans[0] = 0;
        ans[1] = res[0];
        for (int i = 2; i < n; i++) {
            ans[i] = max(ans[i - 1], ans[i - 2] + res[i - 1]);
        }
        cout << ans[n - 1] << '\n';
    }
}

void CHFDORA() { /// CodeChef
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }
        long long res = m * n;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int c = 0;
                int k = 1;
                while (true) {
                    if (i + k < n && i - k >= 0 && j + k < m && j - k >= 0) {
                        if (arr[i + k][j] == arr[i - k][j] && arr[i][j + k] == arr[i][j - k]) {
                            c++;
                        }
                        else break;
                    }
                    else break;
                    k++;
                }
                res += c;
            }
        }
        cout << res << '\n';
    }
}

void DFMTRX() { /// CodeChef
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "Hooray\n1\n";
            continue;
        }
        if (n % 2 == 1) {
            cout << "Boo\n";
            continue;
        }
        int res[n + 1][n + 1];
        memset(res, 0, sizeof(res));
        for (int i = 0; i <= n; i++) {
            res[i][i] = n;
        }
        for (int i = 0; i < n - 1; i++) {
            res[i][n - 1] = i + 1;
            res[n - 1][i] = 2 * n - 1 - i;
            for (int j = 1; j < n / 2; j++) {
                res[(i + j) % (n - 1)][(i - j + n - 1) % (n - 1)] = i + 1;
                res[(i - j + n - 1) % (n - 1)][(i + j) % (n - 1)] = 2 * n - 1 - i;
            }
        }
        cout << "Hooray\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << res[i][j] << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///ENGLISH();
    ///CHFDORA();
    DFMTRX();
}
