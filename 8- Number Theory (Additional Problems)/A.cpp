#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6;

ll cnt[N + 1], a[N + 1], pw[N + 1], g[N + 1];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i) a[i] += cnt[j];
    ll res = 0;
    for (int i = N; i > 1; i--) {
        g[i] = a[i] * pw[a[i] - 1] % mod;
        for (int j = 2 * i; j <= N; j += i) {
            g[i] -= g[j];
            if (g[i] < 0) g[i] += mod;
        }
        res += g[i] * i % mod;
        if (res >= mod) res -= mod;
    }
    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pw[0] = 1;
    for (int i = 1; i <= N; i++) pw[i] = 2 * pw[i - 1] % mod;
    int t = 1;
    while (t--) solve();
}
