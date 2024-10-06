#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n', sp = ' ';

const int mod = 1e9 + 7, N = 500;

int memo[N][N];

string s;

int dp(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    if (memo[l][r] != -1) return memo[l][r];
    int res = 1 + dp(l + 1, r);
    for (int i = l + 1; i <= r; i++)
        if (s[l] == s[i]) res = min(res, dp(l + 1, i - 1) + dp(i, r));
    return memo[l][r] = res;
}

void solve() {
    int n;
    cin >> n;
    memset(memo, -1, sizeof memo);
    cin >> s;
    cout << dp(0, n - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
