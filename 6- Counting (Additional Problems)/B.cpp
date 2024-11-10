#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7;

const int d = 30;
const int inv_2 = (mod + 1) / 2;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(d);
    vector<ll> pw3(n + 1), pw2(d);
    pw3[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++) pw3[i] = 3 * pw3[i - 1] % mod;
    for (int i = 1; i < d; i++) pw2[i] = (1 << i) % mod;

    for (int &x : a) {
        cin >> x;
        for (int i = 0; i < d; i++)
            if (x & (1 << i)) cnt[i]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int idx, x;
        cin >> idx >> x;
        idx--;
        for (int i = 0; i < d; i++)
            if (a[idx] & (1 << i)) cnt[i]--;
        for (int i = 0; i < d; i++)
            if (x & (1 << i)) cnt[i]++;
        a[idx] = x;

        ll res = 0;
        for (int i = 0; i < d; i++) {
            ll tmp =
                pw3[n - cnt[i]] * inv_2 % mod * (pw3[cnt[i]] - 1 + mod) % mod;
            res += tmp * pw2[i] % mod;
            res %= mod;
        }
        cout << res << el;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}