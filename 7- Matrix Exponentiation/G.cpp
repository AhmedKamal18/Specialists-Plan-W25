#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<vector<ll>> matrixMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector res(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                (res[i][j] += a[i][k] * b[k][j] % (mod - 1)) %= (mod - 1);
            }
        }
    }
    return res;
}


vector<vector<ll>> matrixPower(vector<vector<ll>> a, ll n) {
    vector res(a.size(), vector<ll>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n) {
        if (n & 1) res = matrixMul(res, a);
        a = matrixMul(a, a);
        n >>= 1;
    }
    return res;
}

void solve() {
    ll n, c;
    vector<ll> f(3);
    cin >> n >> f[2] >> f[1] >> f[0] >> c;
    vector<vector<ll>> mat = {{1, 1, 1, 2, -6 + mod - 1},
                              {1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 0, 0, 1, 1},
                              {0, 0, 0, 0, 1}};
    vector<vector<ll>> res = matrixPower(mat, n - 3);
    ll ans = pow_mod(c, ((4 * res[0][3]) % (mod - 1) + res[0][4]) % (mod - 1));
    for (int i = 0; i < 3; ++i) {
        ans = (ans * pow_mod(f[i], res[0][i])) % mod;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
