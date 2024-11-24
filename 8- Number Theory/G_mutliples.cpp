#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(N + 1), a(N + 1), g(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i) a[i] += cnt[j];
    for (int i = N; i > 0; i--) {
        g[i] = a[i] * (a[i] - 1) / 2;
        for (int j = 2 * i; j <= N; j += i) g[i] -= g[j];
    }
    cout << g[1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
