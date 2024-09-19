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
    S /= 2;
    const int mod = 1e9 + 7;
    const int inv_2 = (mod + 1) / 2;
    vector dp(n + 2, vector(S + 1, 0));
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int sum = 0; sum <= S; sum++) {
            dp[i][sum] = dp[i + 1][sum];
            if (sum - i >= 0) (dp[i][sum] += dp[i + 1][sum - i]) %= mod;
        }
    }
    cout << 1ll * dp[1][S] * inv_2 % mod;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
