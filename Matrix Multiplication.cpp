// TASK : https://cses.fi/problemset/task/1722/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct Matrix{
    int n, m;
    vector <vector<int>> x;
    Matrix(int n = 0, int m = 0, int val = 0){
        this -> n = n;
        this -> m = m;
        x.assign(n, vector<int>(m, val));
    }

    Matrix operator *(Matrix B){
        assert(m == B.n);
        Matrix C(n, B.m);
        for(int i = 0; i < C.n; ++i)
            for(int j = 0; j < C.m; ++j)
                for(int k = 0; k < m; ++k)
                    (C.x[i][j] += ll(x[i][k]) * B.x[k][j] % MOD) %= MOD;
        return C;
    }

    Matrix Pow(ll n){
        if (n == 1)
            return (*this);
        Matrix tmp = Pow(n >> 1);
        tmp = tmp * tmp;
        if (n & 1)
            tmp = tmp * (*this);
        return tmp;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Matrix A(2, 2), B(2, 1);
    A.x[0][0] = 0;
    A.x[0][1] = 1;
    A.x[1][0] = 1;
    A.x[1][1] = 1;
    B.x[0][0] = 0;
    B.x[1][0] = 1;
    ll n;
    cin >> n;
    if (n <= 1)
        return cout << B.x[n][0], 0;
    A = A.Pow(n - 1);
    B = A * B;
    cout << B.x[1][0];
    return 0;
}
