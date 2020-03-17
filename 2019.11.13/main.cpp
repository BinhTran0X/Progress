#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int MAXN = 2e5 + 10;
const int oo = 2e9;
typedef pair<int,int> i2;
int ST[MAXN * 4];
i2 hero[MAXN];
int mons[MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = mons[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > u || r < v) {
        return -oo;
    }
    if (l <= u && v <= r) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    int left = get(id * 2, l, mid, u, v);
    int right = get(id * 2 + 1, mid + 1, r, u, v);
    return max(left, right);
}

bool cmp(i2 x, i2 y) {
    if (x.first > y.first) return true;
    if (x.first == y.first) {
        if (x.second > y.second) return true;
        return false;
    }
    return false;
}

void D_Div2_CF() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> mons[i];
        int m; cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> hero[i].second;
            cin >> hero[i].first;
        }
        vector<i2> arr;
        arr.push_back(i2(0, 0));
        arr.push_back(hero[1]);
        int len = 1;
        for (int i = 2; i <= m; i++) {
            if (hero[i].first != arr[len].first) {
                arr.push_back(hero[i]);
                len++;
            }
            else {
                arr[len].second = max(arr[len].second, hero[i].second);
            }
        }
        sort(arr.begin(), arr.end(), cmp);
        //for (auto i : arr) cout << i.first << " " << i.second << " ";
        int start = 1;
        long long res = 0;
        int able = 1;
        int MAX = get(1, 1, n, 1, n);
        int mm = -oo;
        for (int i = 1; i <= len; i++) {

        }
        while (start <= n) {
            int i;
            for (i = 0; i <= len; i++) {
                int xxx = get(1, 1, m, start, start + arr[i].first - 1);
                if (xxx <= arr[i].second) {
                    start += arr[i].first;
                    res++;
                    break;
                }
            }
            if (i > len) {
                able = 0;
                break;
            }
        }
        if (able == 0) cout << -1 << '\n';
        else cout << res << '\n';
    }
}

int main()
{
    rwFile();
    D_Div2_CF();
}
