#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6;

int memo[N + 1];

int dp(int n) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    int tmp = n;
    int res = 1e9;
    while (tmp) {
        int d = tmp % 10;
        if (d != 0) res = min(res, 1 + dp(n - d));
        tmp /= 10;
    }
    return memo[n] = res;
}

void solve() {
    int n;
    cin >> n;
    memset(memo, -1, sizeof memo);
    cout << dp(n);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
