#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2][20][20][1 << 10];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    function<ll(int, int, int, int, int)> go = [&](int tight, int i, int sz, int mask, int mx) -> ll{
        if (i == sz) return (mx > 0 && __popcount(mask) == mx);
        ll &ans = dp[tight][i][sz][mask];
        if (ans != -1 && tight == 0) return ans;
        ans = 0;
        int hi = (tight ? s[i] - '0' : 9);
        for (int d = 0; d <= hi; d++) {
            int new_mask = (d == 0 && mx == 0 ? mask : mask | (1 << d));
            ans += go(tight && d == hi, i + 1, sz, new_mask, max(mx, d));
        }
        return ans;
    };
    cout << go(1, 0, n, 0, 0) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    while (t--) solve();
}
