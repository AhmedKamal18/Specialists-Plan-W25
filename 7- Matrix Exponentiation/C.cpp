#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

const ll INF = 2e18;

vector<vector<ll>> matrixMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector res(a.size(), vector<ll>(b[0].size(), INF));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}


vector<vector<ll>> matrixPower(vector<vector<ll>>& a, ll n) {
    vector res(a.size(), vector<ll>(a.size(), INF));
    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 0;
    }
    while (n) {
        if (n & 1) res = matrixMul(res, a);
        a = matrixMul(a, a);
        n >>= 1;
    }
    return res;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector mat(n, vector<ll>(n, INF));
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        mat[--u][--v] = c;
    }
    vector res = matrixPower(mat, k);
    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = min(ans, res[i][j]);
        }
    }
    if(ans > 1e18){
        cout << "IMPOSSIBLE" << nl;
    }else{
        cout << ans << nl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
