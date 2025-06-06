#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 2e5 + 100;

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
    string s;
    cin >> s;
    n = s.size();
    vector<int> pre(n), suff(n);
    for (int i = 0, sum = 0; i < n; i++) {
        if (s[i] == '(') sum++;
        pre[i] = sum;
    }
    for (int i = n - 1, sum = 0; i >= 0; i--) {
        if (s[i] == ')') sum++;
        suff[i] = sum;
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '(') res = (res + comb(pre[i] + suff[i] - 1, pre[i])) % mod;

    cout << res << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_fac();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}