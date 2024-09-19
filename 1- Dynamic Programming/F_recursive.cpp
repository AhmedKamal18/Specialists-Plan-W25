#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n;
    cin >> n;
    int S = n * (n + 1) / 2;
    if (S & 1) {
        cout << 0;
        return;
    }
    const int mod = 1e9 + 7;
    const int inv_2 = (mod + 1) / 2;
    vector dp(n + 1, vector(S / 2 + 1, -1));
    function<int(int, int)> go = [&](int i, int sum) -> int {
        if (i == n + 1) return (sum == 0);
        if (dp[i][sum] != -1) return dp[i][sum];
        int ans = go(i + 1, sum);
        if (sum - i >= 0) ans = (ans + go(i + 1, sum - i)) % mod;
        return dp[i][sum] = ans;
    };
    cout << 1ll * go(1, S / 2) * inv_2 % mod;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
