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
    vector<int> dp(S + 1), ndp(dp);
    dp[0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int sum = 0; sum <= S; sum++) {
            ndp[sum] = dp[sum];
            if (sum - i >= 0) ndp[sum] = (ndp[sum] + dp[sum - i]) % mod;
        }
        swap(dp, ndp);
    }
    cout << 1ll * dp[S] * inv_2 % mod;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
