#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 3e6;

ll fac[N + 1], inv[N + 1], pw[N + 1];

void pre() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = mod - mod / i * inv[mod % i] % mod;
    for (int i = 2; i <= N; i++) {
        inv[i] *= inv[i - 1];
        inv[i] %= mod;
    }
    pw[0] = 1;
    for (int i = 1; i <= N; i++) pw[i] = 2 * pw[i - 1] % mod;
}

ll comb(int n, int r) {
    if (n < r) return 0;
    return fac[n] * inv[n - r] % mod * inv[r] % mod;
}

void solve() {
    int x, y;
    cin >> x >> y;
    vector<int> exp;
    for (int i = 2; (ll)i * i <= x; i++) {
        int e = 0;
        while (x % i == 0) x /= i, e++;
        if (e) exp.push_back(e);
    }
    if (x != 1) exp.push_back(1);
    ll res = 1;
    for (int e : exp) res = res * comb(y + e - 1, y - 1) % mod;
    res = res * pw[y - 1] % mod;
    cout << res << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t = 1;
    cin >> t;
    while (t--) solve();
}