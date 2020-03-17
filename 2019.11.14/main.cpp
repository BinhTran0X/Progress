#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

const int MOD = 1e9 + 7;

long long power(int b, int p) {
    if (p == 0) return 1LL;
    if (p % 2 == 0) {
        return (power(b, p / 2) % MOD) * (power(b, p / 2) % MOD) % MOD;
    }
    else {
        return ((((power(b, p / 2) % MOD) * (power(b, p / 2) % MOD)) % MOD) * b) % MOD;
    }
}

struct Matrix {
    long long M[2][2];
    Matrix() {
        M[0][0] = M[1][1] = 1;
        M[0][1] = M[1][0] = 0;
    }
    Matrix(int a, int b, int c, int d) {
        M[0][0] = a;
        M[0][1] = b;
        M[1][0] = c;
        M[1][1] = d;
    }
};

Matrix mult(Matrix a, Matrix b) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C.M[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C.M[i][j] += a.M[i][k] * b.M[k][j];
                C.M[i][j] %= MOD;
            }
        }
    }
    return C;
}

Matrix exp(Matrix a, int p) {
    if (p == 0) {
        Matrix C;
        return C;
    }
    if (p % 2 == 0) {
        return mult(exp(a, p / 2), exp(a, p / 2));
    }
    else {
        return mult(a, mult(exp(a, p / 2), exp(a, p / 2)));
    }
}

void printM(Matrix a) {
    cout << a.M[0][0] << " " << a.M[0][1] << '\n';
    cout << a.M[1][0] << " " << a.M[1][1] << '\n';
}

Matrix base = Matrix(2, 4, 1, 0);

long long F(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 4;
    Matrix Ans = exp(base, n - 2);
    long long res = 6 * Ans.M[0][0] + 2 * Ans.M[0][1] - power(2, n - 1);
    return res;
}

void K_ACM_Brazil_19_20() {
    long long n; cin >> n;
    //for (int i = 0; i < 10; i ++) cout << F(i) * 2 - i * pow(2, i) << " ";
    long long res = 8 * F(n) - n * power(2, n + 1);
    res = ((res % MOD) + MOD) % MOD;
    cout << res;
}

int main()
{
    rwFile();
    K_ACM_Brazil_19_20();
}
