#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

vector<vector<ll>> matrixMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector res(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                (res[i][j] += a[i][k] * b[k][j] % mod)%=mod;
            }
        }
    }
    return res;
}


vector<vector<ll>> matrixPower(vector<vector<ll>>& a, ll n) {
    vector res(a.size(), vector<ll>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (n) {
        if (n & 1) res = matrixMul(res, a);
        a = matrixMul(a, a);
        n >>= 1;
    }
    return res;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> base(n);
    for (int i = 0; i < n; ++i) {
        cin >> base[i];
    }
    vector mat(n + 3, vector<ll>(n+3));
    for (int i = 0; i < n; ++i) {
        cin >> mat[0][i];
    }
    ll p, q, r;
    cin >> p >> q >> r;
    mat[0][n + 2] = p, mat[0][n + 1] = q, mat[0][n] = r;
    for (int i = 1; i < n; ++i) {
        mat[i][i - 1] = 1;
    }
    mat[n][n] = mat[n][n + 2] = 1, mat[n][n + 1] = 2;
    mat[n + 1][n + 1] = mat[n + 1][n + 2] = 1;
    mat[n + 2][n + 2] = 1;
    if (k < n){
        cout << base[k] << nl;
        return;
    }
    vector res = matrixPower(mat, k - n + 1);
    ll ans = (res[0][n + 2] + res[0][n + 1] * n + res[0][n] * n * n)%mod;
    for (int i = 0; i < n; ++i) {
        (ans += res[0][i] * base[n - i - 1] % mod) %= mod;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
