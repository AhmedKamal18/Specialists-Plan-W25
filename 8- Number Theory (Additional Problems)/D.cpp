#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e5;

vector<int> divs[N + 1];
int phi[N + 1];

void pre() {
    for (int i = 1; i <= N; i++) phi[i] = i;
    for (int i = 2; i <= N; i++)
        if (phi[i] == i)
            for (int j = i; j <= N; j += i) phi[j] -= phi[j] / i;

    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i) divs[j].push_back(i);
}

void solve() {
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 1; i < n; i++)
        for (int d : divs[n - i]) {
            res += (ll)phi[(n - i) / d] * d * i / gcd(d, i) % mod;
            if (res >= mod) res -= mod;
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
