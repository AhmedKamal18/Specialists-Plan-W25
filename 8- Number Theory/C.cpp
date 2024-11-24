#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e7;

int mu[N + 1], vis[N + 1];

void pre() {
    for (int i = 1; i <= N; i++) mu[i] = 1;
    for (int i = 2; i <= N; i++)
        if (vis[i] == 0) {
            for (int j = i; j <= N; j += i) {
                vis[j] = 1;
                if (j % (i * i) == 0)
                    mu[j] = 0;
                else
                    mu[j] *= -1;
            }
        }
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll res = 0;
    for (int i = 1; i <= b; i++) {
        ll x = b / i - (a - 1) / i, y = d / i - (c - 1) / i;
        res += x * y * mu[i];
    }

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
