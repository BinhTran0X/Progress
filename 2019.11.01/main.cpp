#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

void SC31_CodeChef() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[10];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int i = 0; i < 10; i++) {
                arr[i] += (s[i] == '1') ? 1 : 0;
            }
        }
        int res = 0;
        for (int i = 0; i < 10; i++) {
            if (arr[i] % 2 == 1) res++;
        }
        cout << res << '\n';
    }
}

void HRDSEQ_CodeChef() {
    vector<int> arr;
    arr.push_back(-1);
    arr.push_back(0);
    int n = 1;
    for (int j = 0; j < 130; j++) {
        int x = arr[n];
        int able = 0;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] == x) {
                arr.push_back(n - i);
                able = 1;
                break;
            }
        }
        if (able == 0) arr.push_back(0);
        n++;
    }
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        int x = arr[N];
        int res = 0;
        for (int i = 1; i <= N; i++) {
            if (x == arr[i]) res++;
        }
        cout << res << '\n';
    }
    //for (int i : arr) cout << i << ' ';
}

int main()
{
    rwFile();
    HRDSEQ_CodeChef();
    ///SC31_CodeChef();
}
