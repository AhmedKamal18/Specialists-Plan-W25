#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';
const ll mod = 1e9 + 7;

vector<vector<ll>> matrixMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector res(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                (res[i][j] += a[i][k] * b[k][j]) %= mod;
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
    int k;
    ll n;
    cin >> k >> n;
    vector mat(k, vector<ll>(k));
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if(gcd(i,j) == 1){
                mat[i - 1][j - 1] = 1;
            }
        }
    }
    vector res = matrixPower(mat, n - 1);
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            (ans += res[i][j]) %= mod;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

