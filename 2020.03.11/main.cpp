#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void solveA_CutRibbon() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int res[10000];
    memset(res, 0, sizeof(res));
    res[a] = res[b] = res[c] = 1;
    for (int i = 0; i <= n; i++) {
        if (res[i] == 0) continue;
        res[i + a] = max(res[i] + 1, res[i + a]);
        if (b != a) res[i + b] = max(res[i] + 1, res[i + b]);
        if (c != b && c != a) res[i + c] = max(res[i] + 1, res[i + c]);
    }
    //for (int i = 0; i <= n; i++) cout << res[i] << " ";
    cout << res[n];
}

void solveB_BerSUBall() {
    int n, m;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    cin >> m;
    int g[m];
    for (int i = 0; i < m; i++) cin >> g[i];
    sort(b, b + n);
    sort(g, g + m);
    int i = 0, j = 0, res = 0;
    while (i < n && j < m) {
        if (abs(b[i] - g[j]) <= 1) {
            res++;
            i++;
            j++;
        }
        else {
            if (b[i] > g[j]) j++;
            else i++;
        }
    }
    cout << res;
}

void solveB_DreamoonAndWiFi() {
    string s1, s2; cin >> s1 >> s2;
    int a = 0, b = 0;
    int n = s1.size();
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '-') a--;
        else a++;
        if (s2[i] == '-') b--;
        if (s2[i] == '+') b++;
        if (s2[i] == '?') c++;
    }
    int diff = abs(a - b);
    double res = 1;
    if (diff > c || (diff - c) % 2 != 0) res = 0;
    else {
        int x = (diff + c) / 2;
        for (int i = 1; i <= c; i++) res *= (i / 2.);
        for (int i = 1; i <= x; i++) res /= i;
        for (int i = 1; i <= c - x; i++) res /= i;
    }
    cout << fixed << setprecision(10) << res;
}

void solveC_Equalize() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if (n == 1) {
        if (a == b) cout << 0;
        else cout << 1;
        return;
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i - 1] != b[i - 1] && a[i] != a[i - 1]) {
                res++;
                a[i] = b[i];
                a[i - 1] = b[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) res++;
    }
    cout << res;
}

void solveB_LectureSleep() {
    int n, k; cin >> n >> k;
    int a[n], t[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            res += a[i];
            a[i] = 0;
        }
    }
    int preS[n + 1];
    preS[0] = 0;
    for (int i = 1; i <= n; i++) preS[i] = preS[i - 1] + a[i - 1];
    int Max = 0;
    for (int i = k; i <= n; i++) Max = max(Max, preS[i] - preS[i - k]);
    cout << res + Max;
}

void solveB_GameOfCreditCards() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int res1 = 0, res2 = 0, check1[n], check2[n];
    memset(check1, 0, sizeof(check1));
    memset(check2, 0, sizeof(check2));
    for (int i = 0; i < n; i++) {
        int pos1 = -1, tmp1 = -1, pos2 = -1, tmp2 = -1;
        for (int j = 0; j < n; j++) {
            if (check1[j] == 0) {
                if (b[j] > a[i]) {
                    if (pos1 != -1) {
                        if (int(b[j] - '0') < tmp1) {
                            pos1 = j;
                            tmp1 = int(b[j] - '0');
                        }
                    }
                    else {
                        pos1 = j;
                        tmp1 = int(b[j] - '0');
                    }
                }
            }
            if (check2[j] == 0) {
                if (b[j] >= a[i]) {
                    if (pos2 != -1) {
                        if (int(b[j] - '0') < tmp2) {
                            pos2 = j;
                            tmp2 = int(b[j] - '0');
                        }
                    }
                    else {
                        pos2 = j;
                        tmp2 = int(b[j] - '0');
                    }
                }
            }
        }
        if (pos1 != -1) {
            check1[pos1] = 1;
            res1++;
        }
        if (pos2 != -1) {
            check2[pos2] = 1;
            res2++;
        }
    }
    cout << n - res2 << '\n' << res1;
}

void solveA_AsSimpleAsOneAndTwo() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int res = 0;
        vector<int> pos;
        for (int i = 2; i < n; i++) {
            if (s[i] == 'e') {
                if (s[i - 1] == 'n' && s[i - 2] == 'o') {
                    if (n >= 4 && s[i - 3] == 'w' && s[i - 4] == 't') {
                        pos.pop_back();
                        pos.push_back(i - 1);
                    }
                    else {
                        res++;
                        pos.push_back(i);
                    }
                }
            }
            if (s[i] == 'o' && s[i - 1] == 'w'&& s[i - 2] == 't') {
                res++;
                pos.push_back(i);
            }
        }
        cout << res << '\n';
        for (int i : pos) cout << i << ' ';
        cout << '\n';
    }
}

void solveC_MaximumSplitting() {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        if (n == 1 || n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
            cout << -1 << '\n';
            continue;
        }
        int res = 0;
        if (n % 2 == 1) {
            n -= 9;
            res++;
        }
        if (n % 4 != 0) {
            res += 1;
            n -= 6;
        }
        res += n / 4;
        cout << res << '\n';
    }
}

void solveB_MikeAndStrings() {
    int n; cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int len = arr[0].size();
    int res[n];
    int ans = 1e9;
    for (int id = 0; id < n; id++) {
        for (int i = 0; i < n; i++) res[i] = -1;
        res[id] = 0;
        for (int i = 0; i < n; i++) {
            string tmp = arr[i];
            for (int j = 0; j <= len + 1; j++) {
                if (tmp == arr[id]) {
                    res[i] = j;
                    break;
                }
                char f = tmp[0];
                tmp.erase(0, 1);
                tmp += f;
            }
            if (res[i] == -1) {
                cout << -1;
                return;
            }
        }
        int c = 0;
        for (int i = 0; i < n; i++) c += res[i] - res[id];
        ans = min(ans, c);
    }
    cout << ans;
}

void solveB_NewSkateboard() {
    string s; cin >> s;
    int n = s.size(), res[n];
    res[0] = (s[0] - '0') % 4;
    long long ans = 0;
    if (res[0] == 0) ans++;
    for (int i = 1; i < n; i++) {
        res[i] = (2 * res[i - 1] + int(s[i] - '0')) % 4;
        if (int(s[i] - '0') % 4 == 0) ans++;
    }
    for (int i = 1; i < n; i++) {
        if (res[i] == 0) ans += i;
    }
    cout << ans;
}

void solveC_Weather() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int neg[n], pos[n];
    neg[0] = 0, pos[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < 0) {
            neg[i] = neg[i - 1] + 1;
            pos[i] = pos[i - 1];
        }
        else if (arr[i - 1] == 0) {
            neg[i] = neg[i - 1];
            pos[i] = pos[i - 1];
        }
        else {
            neg[i] = neg[i - 1];
            pos[i] = pos[i - 1] + 1;
        }
    }
    int res = 1e9;
    for (int i = 1; i < n; i++) {
        int tmp = i - neg[i] + (n - 1 - i - pos[n - 1] + pos[i]);
        res = min(res, tmp);
    }
    if (arr[n - 1] <= 0) res++;
    cout << res;
}

void solveC_Letter() {
    string s; cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << 0;
        return;
    }
    int l[n], u[n];
    l[0] = u[0] = 0;
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1];
        u[i] = u[i - 1];
        if (islower(s[i - 1])) l[i]++;
        else u[i]++;
    }
    int res = u[n - 1];
    if (isupper(s[n - 1])) res++;
    for (int i = 1; i < n; i++) {
        int tmp = i - u[i] + u[n - 1] - u[i];
        if (!islower(s[n - 1])) tmp++;
        if (!islower(s[i])) tmp--;
        res = min(res, tmp);
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveA_CutRibbon();
    ///solveB_BerSUBall();
    ///solveB_DreamoonAndWiFi();
    ///solveC_Equalize();
    ///solveB_LectureSleep();
    ///solveB_GameOfCreditCards();
    ///solveA_AsSimpleAsOneAndTwo();
    ///solveC_MaximumSplitting();
    ///solveB_MikeAndStrings();
    ///solveB_NewSkateboard();
    ///solveC_Weather();
    solveC_Letter();
}
