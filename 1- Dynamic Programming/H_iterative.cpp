#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector dp(n + 1, vector(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], (s[i] == t[j]) + dp[i + 1][j + 1]});
        }
    }
    string ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        int move_s = dp[i + 1][j], move_t = dp[i][j + 1];
        int move_both = (s[i] == t[j]) + dp[i + 1][j + 1];
        if (dp[i][j] == move_s) i++;
        else if (dp[i][j] == move_t) j++;
        else {
            if (s[i] == t[j]) ans += s[i];
            i++, j++;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
