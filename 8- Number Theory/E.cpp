#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = N; i > 0; i--) {
        int c = 0;
        for (int j = i; j <= N; j += i) c += cnt[j];
        if (c > 1) {
            cout << i;
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}