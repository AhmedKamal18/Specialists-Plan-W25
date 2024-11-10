#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int res = 1;
    while (k) {
        res = (ll)res * n % mod;
        k--;
    }
    cout << res << el;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}