#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 1e4, M = 2520, mod = 1e9 + 7;
int dp[N][M], a[N];

int go(int i, int rem) {
    if (i == n) return (rem == 0);
    if (dp[i][rem] != -1) return dp[i][rem];
    int ans = go(i + 1, rem);
    (ans += go(i + 1, rem * a[i] % M)) %= mod;
    return dp[i][rem] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
