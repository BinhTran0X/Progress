#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void solveD_AlexAndJulian() {
    int n; cin >> n;
    int div2[65];
    memset(div2, 0, sizeof(div2));
    vector<long long> arr[65];
    for (int i = 0; i < n; i++) {
        long long b; cin >> b;
        int e = 0;
        long long tmp = b;
        while (tmp % 2 == 0) {
            tmp /= 2;
            e++;
        }
        div2[e]++;
        arr[e].push_back(b);
    }
    int ans = 0;
    for (int i = 0; i < 65; i++) {
        if (div2[i] > div2[ans]) ans = i;
    }
    cout << n - div2[ans] << '\n';
    for (int i = 0; i < 65; i++) {
        if (i == ans) continue;
        for (long long j : arr[i]) cout << j << ' ';
    }
}

void solveE_MissingNumbers() {
    int n; cin >> n;
    long long arr[n];
    for (int i = 1; i < n; i += 2) cin >> arr[i];
    int able = 1;
    arr[0] = -1;
    for (long long i = 1; i < 10000000; i++) {
        long long tmp = i * i + arr[1];
        long long x = sqrt(tmp);
        if (x * x == tmp) {
            arr[0] = i * i;
            break;
        }
    }
    long long X = 0;
    int start = 1;
    if (arr[0] != -1) {
        start = 3;
        X = arr[0] + arr[1];
    }
    for (int i = start; i < n; i += 2) {
        long long tmp;
        if (arr[i] % 2 == 1) {
            tmp = (arr[i] - 1) / 2;
            arr[i - 1] = tmp * tmp  - X;
            X = (tmp + 1) * (tmp + 1);
        }
        else {
            if (arr[i] % 4 != 0) {
                able = 0;
                break;
            }
            tmp = arr[i] / 4 - 1;
            arr[i - 1] = tmp * tmp - X;
            X = (tmp + 2) * (tmp + 2);
        }
        if (arr[i - 1] <= 0) {
            able = 0;
            cout << arr[i - 1];
            break;
        }
    }
    if (able == 0) {
        cout << "No";
        //return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ///solveD_AlexAndJulian();
    solveE_MissingNumbers();
}
