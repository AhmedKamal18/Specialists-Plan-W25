#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(rbegin(a), rend(a));
    vector s(n, vector(p, 0ll));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) cin >> s[i][j];
    }

    const int inf = 1e17;
    vector dp(n, vector(1 << p, -1ll));
    function<ll(int, int)> go = [&](int i, int mask) {
        if (i == n) {
            return (__popcount(mask) < p ? -inf : 0);
        }
        if (~dp[i][mask]) return dp[i][mask];
        int ans = go(i + 1, mask);
        int rem_k = k - (i - __popcount(mask));
        if (rem_k > 0) {
            ans = a[i].first + go(i + 1, mask);
        }
        for (int j = 0; j < p; j++) {
            if (mask & (1 << j)) continue;
            ans = max(ans, s[a[i].second][j] + go(i + 1, mask | (1 << j)));
        }
        return dp[i][mask] = ans;
    };
    cout << go(0, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}