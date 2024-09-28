#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n, vector<ll>(n));
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        cin >> g[--u][--v];
    }
    vector dp(n, vector(1<<n, -1ll));
    function<ll(int,int)> go = [&](int last, int mask) -> ll{
        if (__popcount(mask) == m) return 0;
        if (~dp[last][mask]) return dp[last][mask];
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (mask&(1<<i)) continue;
            ans = max(ans, a[i] + g[last][i] + go(i, mask | (1<<i)));
        }
        return dp[last][mask] = ans;
    };
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i] + go(i,1<<i));
    }
    cout << ans <<nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}