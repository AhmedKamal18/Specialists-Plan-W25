#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6;

int mu[N + 1], vis[N + 1];

void mobius() {
    for (int i = 1; i <= N; i++) mu[i] = 1;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) {
            for (int j = i; j <= N; j += i) {
                vis[j] = 1;
                if (j % ((ll)i * i) == 0)
                    mu[j] = 0;
                else
                    mu[j] *= -1;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(N + 1), a(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i) a[i] += cnt[j];

    ll res = 0;
    for (int i = 1; i <= N; i++) {
        res += a[i] * (a[i] - 1) / 2 * mu[i];
    }
    cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mobius();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
