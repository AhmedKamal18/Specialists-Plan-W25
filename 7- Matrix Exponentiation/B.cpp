#include <bits/stdc++.h>
using namespace std;
using ll = unsigned int;
const char nl = '\n';

vector<vector<ll>> matrixMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector res(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                res[i][j] += a[i][k] * b[k][j];
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
    int k;
    cin >> k;
    vector mat(65, vector<ll>(65));
    vector<int> dx = {1,1,-1,-1,2,2,-2,-2};
    vector<int> dy = {2,-2,2,-2,1,-1,1,-1};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int cell = 8*i + j;
            for (int l = 0; l < 8; ++l) {
                int nx = i + dx[l];
                int ny = j + dy[l];
                if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
                int new_cell = nx*8 + ny;
                mat[cell][new_cell] = 1;
            }
        }
    }
    for (int i = 0; i < 65; ++i) {
        mat[64][i] = 1;
    }
    vector<vector<ll>> res = matrixPower(mat, k + 1);
    cout << res[64][0] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
