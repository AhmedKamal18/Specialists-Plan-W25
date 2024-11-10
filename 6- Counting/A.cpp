#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt_a(n), cnt_b(n);
    vector<pair<int, int> > arr(n);
    for (auto &[a, b] : arr) cin >> a >> b, cnt_a[--a]++, cnt_b[--b]++;
    ll res = (ll)n * (n - 1) * (n - 2) / 6;
    for (auto &[a, b] : arr) res -= (ll)(cnt_a[a] - 1) * (cnt_b[b] - 1);
    cout << res << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}