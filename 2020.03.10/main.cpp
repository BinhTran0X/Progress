#include <bits/stdc++.h>
#define TASK "task"

using namespace std;

void rwFile() {
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

void ForegoneSolution() { /// Code Jam
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        string n; cin >> n;
        string a = "", b = "";
        for (int j = 0; j < (int)n.size(); j++) {
            if (n[j] == '4') {
                a += '1';
                b += '3';
            }
            else {
                a += n[j];
                b += '0';
            }
        }
        int start = 0;
        for (int j = 0; i < (int)b.size(); j++) {
            if (b[j] != '0') {
                start = j;
                break;
            }
        }
        string tmp = "";
        for (int j = start; j < (int)b.size(); j++) tmp += b[j];
        cout << a << ' ' << tmp << '\n';
    }
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    ForegoneSolution();
}
