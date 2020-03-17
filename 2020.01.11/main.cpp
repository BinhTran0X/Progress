#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void solveA_MezoPlayingZoma() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') l++;
        else r++;
    }
    cout << l + r + 1;
}

void solveB_JustEatIt() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long arr[n];
        long long pre[n], suf[n];
        pre[0] = 0;
        suf[0] = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n - 1; i++) {
            pre[i + 1] = pre[i] + arr[i];
            suf[i + 1] = suf[i] + arr[n - 1 - i];
        }
        int able = 1;
        for (int i = 1; i < n; i++) {
            if (pre[i] <= 0) {
                able = 0;
                break;
            }
            if (suf[i] <= 0) {
                able = 0;
                break;
            }
        }
        if (able) cout << "YES\n";
        else cout << "NO\n";
    }
}

void solveC_FadiAndLCM() {
    long long x;
    cin >> x;
    vector<long long> div;
    for (int i = 2; i < 1e6; i++) {
        if (x % i == 0) {
            long long tmp = 1;
            while (x % i == 0) {
                tmp *= i;
                x /= i;
            }
            div.push_back(tmp);
        }
    }
    if (x != 1) div.push_back(x);
    long long maxx = 1e18, minn = 0;
    long long k = pow(2, div.size());
    //cout << k;
    for (int i = 0; i < k; i++) {
        int tmp = i;
        long long A = 1, B = 1;
        for (int j = 0; j < (int)div.size(); j++) {
            if (tmp % 2 == 1) A *= div[j];
            else B *= div[j];
            tmp /= 2;
        }
        if (max(A, B) < maxx) {
            maxx = max(A, B);
            minn = min(A, B);
        }
    }
    cout << maxx << " " << minn;
}

void ALDS1_1_D() { /// Aizu
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int maxx[n];
    maxx[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        maxx[i] = max(maxx[i + 1], arr[i + 1]);
    }
    int res = -1e9;
    for (int i = 0; i < n - 1; i++) res = max(res, maxx[i] - arr[i]);
    cout << res;
}

int S(int x) {
    if (x < 0) return 0;
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solveB_LittleDimaAndEquation() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> res;
    if (a == 1) {
        for (int i = 1; i <= 81; i++) {
            if (S(b * i + c) == i) res.push_back(b * i + c);
        }
    }
    if (a == 2) {
        for (int i = 1; i <= 81; i++) {
            long long tmp = (long long)b * i * i + c;
            if (tmp >= 1e9) break;
            if (S(tmp) == i) res.push_back(tmp);
        }
    }
    if (a == 3) {
        for (int i = 1; i <= 81; i++) {
            long long tmp = (long long)b * i * i * i + c;
            if (tmp >= 1e9) break;
            if (S(tmp) == i) res.push_back(tmp);
        }
    }
    if (a == 4) {
        for (int i = 1; i <= 81; i++) {
            long long tmp = (long long)b * i * i * i * i + c;
            if (tmp >= 1e9) break;
            if (S(tmp) == i) res.push_back(tmp);
        }
    }
    if (a == 5) {
        for (int i = 1; i <= 81; i++) {
            long long tmp = (long long)b * i * i * i * i * i + c;
            if (tmp >= 1e9) break;
            if (S(tmp) == i) res.push_back(tmp);
        }
    }
    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
}

void solveC_VladikAndFractions() {
    int n;
    cin >> n;
    if (n == 1) cout << -1;
    else cout << n << " " << n + 1 << " " << n * n + n;
}

void solveB_ArpasObviousProblemAndMehrdadsTerribleSolution() {
    int n, x; cin >> n >> x;
    long long pos[123456], arr[n];
    memset(pos, 0, sizeof(pos));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]]++;
    }
    long long res = 0;
    for (int i = 0; i < 1e5 + 5; i++) {
        if (pos[i] == 0) continue;
        int tmp = i ^ x;
        if (tmp > 1e5) continue;
        if (tmp == i) res += pos[i] * (pos[i] - 1);
        else res += pos[tmp] * pos[i];
    }
    cout << res / 2;
}

int toInt(char x) {
    return x - '0';
}

void solveD_PolycarpAndDiv3() {
    string s;
    cin >> s;
    int res = 0;
    int n = s.size();
    int check[n];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n; i++) {
        if (toInt(s[i]) % 3 == 0) {
            res++;
            check[i] = 1;
        }
        if (toInt(s[i]) % 3 == 1) {
            if (i < 1) continue;
            if (toInt(s[i - 1]) % 3 == 0) continue;
            if (toInt(s[i - 1]) % 3 == 2) {
                if (check[i - 1] == 0) {
                    res++;
                    check[i] = check[i - 1] = 1;
                }
                else continue;
            }
            if (i < 2) continue;
            if (toInt(s[i - 2]) % 3 == 1) {
                if (check[i - 2] == 0) {
                    res++;
                    check[i] = check[i - 1] = check[i - 2] = 1;
                }
                else continue;
            }
        }
        if (toInt(s[i]) % 3 == 2) {
            if (i < 1) continue;
            if (toInt(s[i - 1]) % 3 == 0) continue;
            if (toInt(s[i - 1]) % 3 == 1) {
                if (check[i - 1] == 0) {
                    res++;
                    check[i] = check[i - 1] = 1;
                }
                else continue;
            }
            if (i < 2) continue;
            if (toInt(s[i - 2]) % 3 == 2) {
                if (check[i - 2] == 0) {
                    res++;
                    check[i] = check[i - 1] = check[i - 2] = 1;
                }
                else continue;
            }
        }
    }
    cout << res;
}

void solveA_MashmokhAndNumbers() {
    int n, k; cin >> n >> k;
    if (n == 1) {
        if (k == 0) cout << 13;
        else cout << -1;
        return;
    }
    k = k - n / 2 + 1;
    if (k <= 0) {
        cout << -1;
        return;
    }
    int arr[n];
    arr[0] = k;
    arr[1] = k * 2;
    for (int i = 2; i < n; i++) arr[i] = 2 * k + i - 1;
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveC_FadiAndLCM();
    ///ALDS1_1_D();
    ///solveB_LittleDimaAndEquation();
    ///solveC_VladikAndFractions();
    ///solveB_ArpasObviousProblemAndMehrdadsTerribleSolution();
    ///solveD_PolycarpAndDiv3();
    solveA_MashmokhAndNumbers();
}
