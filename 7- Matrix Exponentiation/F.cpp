#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

vector<vector<ll>> matrixMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                (res[i][j] += a[i][k] * b[k][j]);
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

void solve(){
    ll p, q, n;
    while (true){
        cin >> p >> q;
        if (p == 0 && q == 0) return;
        cin >> n;
        vector<vector<ll>> mat = {{p,-q},{1, 0}};
        vector res = matrixPower(mat, n - 1);
        ll ans = res[0][0] * p + res[0][1] * 2;
        cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

