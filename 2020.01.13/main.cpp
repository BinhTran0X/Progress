#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA_LLPS() {
    string s; cin >> s;
    char x = 'a';
    int t = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] > x) {
            x = s[i];
            t = 1;
        }
        else if (s[i] == x) t++;
    }
    for (int i = 0; i < t; i++) cout << x;
}

void solveB_TavasAndSaDDas() {
    string s; cin >> s;
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res *= 2;
        res += (s[i] == '4') ? 0 : 1;
    }
    for (int i = 1; i < (int)s.size(); i++) res += pow(2, i);
    cout << res + 1;
}

void solveA_RaisingBacteria() {
    int x; cin >> x;
    if (x == 1) cout << 1;
    else {
        int res = 0;
        while (x) {
            res += x % 2;
            x /= 2;
        }
        cout << res;
    }
}

void solveB_LuckyNumbersEasy() {
    string s; cin >> s;
    int n = s.size();
    string res = "";
    if (s[0] > '7') {
        for (int i = 0; i < n + 1; i++) res += '4';
        cout << res;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '4' || s[i] == '7') res += s[i];
        else {
            if (s[i] - '4' < 0) {
                res += '4';
                break;
            }
            if (s[i] - '7' < 0) {
                res += '7';
                break;
            }
            if (s[i] > '7') {
                res += '4';
                for (int j = (int)res.size() - 2; j >= 0; j--) {
                    if (res[j] == '4') {
                        res[j] = '7';
                        for (int k = j + 1; k < (int)res.size(); k++) {
                            res[k] = '4';
                        }
                        break;
                    }
                    if (j == 0) {
                        res = "";
                        for (int k = 0; k <= n; k++) res += '4';
                        cout << res;
                        return;
                    }
                }
            }
        }
    }
    while ((int)res.size() < n) res += '4';
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveA_LLPS();
    ///solveB_TavasAndSaDDas();
    ///solveA_RaisingBacteria();
    solveB_LuckyNumbersEasy();
}
