#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6;

ll fast_power(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = a * res % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int ans[N + 1];

void solve() {
    int n, k;
    cin >> k >> n;
    if (n == 1) {
        cout << k << el;
        return;
    }
    vector<int> divs;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            divs.push_back(i);
            if (n / i != i) divs.push_back(n / i);
        }
    sort(divs.begin(), divs.end());

    ans[n] = fast_power(k, n) - k;
    if (ans[n] < 0) ans[n] += mod;
    for (int d : divs) {
        ans[d] = fast_power(k, d) - k;
        for (int i = 2; i * i <= d; i++)
            if (d % i == 0) {
                ans[d] -= ans[i];
                if (ans[d] < 0) ans[d] += mod;
                if (d / i != i) ans[d] -= ans[d / i];
                if (ans[d] < 0) ans[d] += mod;
            }
        ans[n] -= ans[d];
        if (ans[n] < 0) ans[n] += mod;
    }
    cout << ans[n] << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
