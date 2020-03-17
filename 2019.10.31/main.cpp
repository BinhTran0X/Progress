#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int oo = 1e9;

void SPOJ_KAGAIN() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n + 2], L[n + 2], R[n + 2];
        for (int i = 1; i <= n; i++) cin >> arr[i];
        arr[0] = arr[n + 1] = 0;
        deque<int> Min, Max;
        Min.push_back(0);
        for (int i = 1; i <= n; i++) {
            while (arr[i] <= arr[Min.back()]) {
                Min.pop_back();
            }
            L[i] = Min.back() + 1;
            Min.push_back(i);
        }
        Max.push_back(n + 1);
        for (int i = n; i > 0; i--) {
            while (arr[i] <= arr[Max.back()]) {
                Max.pop_back();
            }
            R[i] = Max.back() - 1;
            Max.push_back(i);
        }
        int l, r;
        long long Sum = 0;
        for (int i = 1; i <= n; i++) {
            long long res = (R[i] - L[i] + 1) * arr[i];
            if (res > Sum) {
                Sum = res;
                l = L[i];
                r = R[i];
            }
        }
        cout << Sum << " " << l << " " << r << '\n';
    }
}

void SPOJ_MINK() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int A[n + 1];
        A[0] = oo;
        for (int i = 1; i <= n; i++) cin >> A[i];
        deque<int> D;
        D.push_back(0);
        vector<int> res;
        for (int i = 1; i < k; i++) {
            while (!D.empty() && A[i] < A[D.back()]) {
                D.pop_back();
            }
            D.push_back(i);
        }
        for (int i = k; i <= n; i++) {
            while (!D.empty() && A[i] < A[D.back()]) {
                D.pop_back();
            }
            D.push_back(i);
            while (D.front() + k - 1 < i) {
                D.pop_front();
            }
            res.push_back(D.front());
        }
        for (int i : res) cout << A[i] << " ";
        cout << '\n';
    }
}

int main()
{
    rwFile();

    ///SPOJ_MINK();
    ///SPOJ_KAGAIN();
}



