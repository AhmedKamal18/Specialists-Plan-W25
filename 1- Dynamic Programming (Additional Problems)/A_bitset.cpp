#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

const int K = 501;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<bitset<K>> dp(k + 1), ndp(k + 1);
    dp[0][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int sum = 0; sum <= k; ++sum) {
            ndp[sum] = dp[sum]; // leave subset
            if (sum >= a[i]) {
                ndp[sum] |= dp[sum - a[i]]; // take subset, leave sub-subset
                ndp[sum] |= dp[sum - a[i]] << a[i]; // take subset, take sub-subset
            }
        }
        swap(dp, ndp);
    }
    cout << dp[k].count() << nl;
    for (int i = 0; i <= k; i++) {
        if (dp[k][i]) cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
