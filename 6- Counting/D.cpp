#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e5 + 100;

ll inv[N + 1], cat[N + 1];

void pre() {
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) inv[i] = mod - mod / i * inv[mod % i] % mod;
    cat[0] = 1;
    for (ll i = 0; i < N - 3; i++) {
        cat[i + 1] = (4ll * i + 2ll) * cat[i] % mod;
        cat[i + 1] = cat[i + 1] * inv[i + 2] % mod;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll res = cat[n];
    for (int i = 0; i < n; i++) res = res * k % mod;
    cout << res << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}