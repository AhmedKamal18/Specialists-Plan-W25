#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e5 + 100;

ll fac[N + 1], inv[N + 1], dp[N + 1];

void pre_fac() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = (fac[i - 1] * i) % mod;
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = mod - mod / i * inv[mod % i] % mod;
    for (int i = 2; i <= N; i++) {
        inv[i] *= inv[i - 1];
        inv[i] %= mod;
    }
}

ll comb(int n, int r) {
    if (n < r) return 0;

    return ((fac[n] * inv[n - r]) % mod * inv[r]) % mod;
}

void solve() {
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 1; i < n; i += 2) {
        res += dp[i] * dp[n - 1 - i] % mod * comb(n - 1, i) % mod;
        res %= mod;
    }
    if (n == 1) res = 1;

    cout << res << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 1;
    for (int i = 3; i <= N; i += 2) dp[i] = (i - 1) * dp[i - 2] % mod;

    pre_fac();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}