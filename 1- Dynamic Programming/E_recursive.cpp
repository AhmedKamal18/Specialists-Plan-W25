#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e3;

int memo[N][N];;
string grid[N];
int n;

int dp(int i, int j) {
    if (grid[i][j] == '*') return 0;
    if (i == n - 1 && j == n - 1) return 1;
    if (memo[i][j] != -1) return memo[i][j];
    int res = 0;
    // move down
    if (i + 1 < n) res = dp(i + 1, j);
    // move right
    if (j + 1 < n) res += dp(i, j + 1), res %= mod;
    return memo[i][j] = res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grid[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
