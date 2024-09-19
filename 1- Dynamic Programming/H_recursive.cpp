#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s, t;
int n, m;
const int N = 3e3;
int dp[N][N];

int go(int i, int j) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max({go(i + 1, j), go(i, j + 1), (s[i] == t[j]) + go(i + 1, j + 1)});
}

string ans;
void trace(int i, int j) {
    if (i == n || j == m) return;
    int move_s = go(i + 1, j);
    int move_t = go(i, j + 1);
    int move_both = (s[i] == t[j]) + go(i + 1, j + 1);
    int mx = max({move_s, move_t, move_both});
    if (mx == move_s) {
        trace(i + 1, j);
        return;
    }
    if (mx == move_t) {
        trace(i, j + 1);
        return;
    }
    if (mx == move_both) {
        if (s[i] == t[j]) ans += s[i];
        trace(i + 1, j + 1);
    }
}

void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    memset(dp, -1, sizeof dp);
    trace(0, 0);
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
