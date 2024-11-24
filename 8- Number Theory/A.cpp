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

void solve(ll n) {
    ll n1, n2, c1, c2;
    if (n == 0) return;
    cin >> c1 >> n1 >> c2 >> n2;
    bool flag = false;
    if (c1 * n2 < c2 * n1) swap(c1, c2), swap(n1, n2), flag = true;
    ll x, y;
    ll g = ext_euclid(n1, n2, x, y);
    if (n % g) {
        cout << "failed" << el;
        return;
    }
    x *= n / g, y *= n / g;

    ll k = x * g / n2;
    x -= k * n2 / g;
    y += k * n1 / g;
    while (x < 0) x += n2 / g, y -= n1 / g;

    if (y < 0) {
        cout << "failed" << el;
        return;
    }

    if (flag) swap(x, y);
    cout << x << sp << y << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
}
