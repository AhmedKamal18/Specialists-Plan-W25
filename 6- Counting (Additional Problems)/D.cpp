// و من هاب أسباب المنايا ينلنه   و إت يرق أسباب السماء بسلم

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e2;

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
    if (r < 0) return 0;
    if (n < r) return 0;
    return fac[n] * inv[n - r] % mod * inv[r] % mod;
}

void solve() {
    int n, i, j, x, y;
    cin >> n >> i >> j >> x >> y;
    i--, j--;
    if (x > y) {
        int ti = n - j - 1, tj = n - i - 1;
        i = ti, j = tj;
        swap(x, y);
    }
    if (y == n) {
        if (j == n - 1)
            cout << 0 << el;
        else
            cout << comb(x - 1, i) * comb(n - x - 1, j - i - 1) % mod << el;
        return;
    }
    ll res = 0;
    for (int k = i + 1; k < j; k++) {
        ll curr = comb(n - y - 1, j - k - 1);
        int rem = n - y - 1 - (j - k - 1);
        curr = curr * comb(y - x - 1, k - i - 1 - rem) % mod;
        curr = curr * comb(x - 1, i) % mod;
        res = (res + curr) % mod;
    }

    for (int k = j + 1; k < n - 1; k++) {
        ll curr = comb(n - y - 1, k - j - 1) * comb(y - x - 1, j - i - 1) % mod;
        curr = curr * comb(x - 1, i) % mod;
        res = (res + curr) % mod;
    }

    cout << res << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_fac();
    int t = 1;
    cin >> t;
    while (t--) solve();
}