#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 998244353, N = 2e5 + 100;

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

void solve() {
    int n;
    cin >> n;
    int mx = 0, mxc = 0, mx2 = 0, mx2c = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > mx) {
            mx2 = mx;
            mx2c = mxc;
            mx = x;
            mxc = 1;
        } else if (x == mx)
            mxc++;
        else if (x == mx2)
            mx2c++;
        else if (x > mx2) {
            mx2 = x;
            mx2c = 1;
        }
    }
    if (mxc > 1) {
        cout << fac[n] << el;
        return;
    }
    if (mx - mx2 > 1) {
        cout << 0 << el;
        return;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll curr = (comb(n - 1, mx2c) - comb(i, mx2c) + mod) % mod;
        res = (res + curr) % mod;
    }
    res = res * fac[n - mx2c - 1] % mod * fac[mx2c] % mod;
    cout << res << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_fac();
    int t = 1;
    cin >> t;
    while (t--) solve();
}