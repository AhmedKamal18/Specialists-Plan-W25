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

vector<ll> matrixMul(vector<ll>& a, vector<vector<ll>>& b) {
    vector<ll> res(a.size());
    for (int j = 0; j < a.size(); j++) {
        for (int k = 0; k < a.size(); k++) {
            (res[j] += a[k] * b[k][j] % mod) %= mod;
        }
    }
    return res;
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector M(30, vector(n, vector<ll>(n)));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        M[0][u][v]++;
    }
    for (int i = 1; i < 30; ++i) {
        M[i] = matrixMul(M[i-1], M[i-1]);
    }
    while (q--){
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        vector res = vector<ll>(n);
        res[u] = 1;
        for (int i = 0; i < 30; ++i) {
            if (k & (1 << i)) res = matrixMul(res, M[i]);
        }
        cout << res[v] << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
