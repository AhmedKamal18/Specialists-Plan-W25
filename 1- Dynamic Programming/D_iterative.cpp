#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7;

int dp[10];

void solve() {
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 9; j > 0; j--) dp[j] = dp[j - 1];
        int res = 1e9;
        int tmp = i;
        while (tmp) {
            int d = tmp % 10;
            if (d != 0) res = min(res, 1 + dp[d]);
            tmp /= 10;
        }
        dp[0] = res;
    }
    cout << dp[0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
