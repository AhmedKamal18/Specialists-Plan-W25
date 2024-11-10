#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 2e3;

ll memo[N + 1];
vector<int> cnt;

int n;

ll fac[N + 1], inv[N + 1];

void pre_fac() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
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
    return fac[n] * inv[n - r] % mod * inv[r] % mod;
}

ll dp(int k) {
    if (memo[k] != -1) return memo[k];
    ll res = 1;
    for (int i = 0; i < n; i++) res = res * comb(cnt[i] + k - 1, k - 1) % mod;
    ll sub = 0;
    for (int i = 1; i < k; i++) sub = (sub + comb(k, i) * dp(k - i)) % mod;
    res += mod - sub;
    res %= mod;
    return memo[k] = res;
}

void solve() {
    int k;
    cin >> n >> k;
    cnt = vector(n, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    memset(memo, -1, sizeof memo);
    cout << dp(k) << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_fac();
    int t = 1;
    cin >> t;
    while (t--) solve();
}