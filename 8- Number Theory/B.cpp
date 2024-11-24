#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7;

ll ext_euclid(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ext_euclid(b, a % b, x1, y1);
    x = y1;
    ll q = a / b;
    y = x1 - q * y1;
    return g;
}

ll fast_power(ll a, ll n, ll mod = mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve() {
    ll a, b, d;
    cin >> a >> b >> d;
    ll k, y;
    ll g = ext_euclid(b, d, k, y);
    ll x = (d - a % d) % d;
    if (x % g) {
        cout << -1 << el;
        return;
    }
    k *= x / g;
    ll delta = d / g;
    ll c = k / delta;
    k -= c * delta;
    if (k < 0) k += delta;

    for (int i = 0; i < 30; i++) {
        ll tmp = a * fast_power(b, k + i * delta, d) % d;
        if (tmp == 0) {
            cout << k + i * delta << el;
            return;
        }
    }
    cout << -1 << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
