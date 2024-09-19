#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 1e4, mod = 1e9 + 7;
int dp[N][4][3][2][2], a[N];

int go(int i, int c2, int c3, int c5, int c7) {
    if (i == n) return (c2 == 3 && c3 == 2 && c5 && c7);
    int& ans = dp[i][c2][c3][c5][c7];
    if (ans != -1) return ans;
    ans = go(i + 1, c2, c3, c5, c7);
    vector<int> cnt(8);
    int x = a[i];
    for (int j : {2, 3, 5, 7}) {
        while (x % j == 0) cnt[j]++, x /= j;
    }
    (ans += go(i + 1, min(c2 + cnt[2], 3), min(c3 + cnt[3], 2), min(c5 + cnt[5], 1), min(c7 + cnt[7], 1))) %= mod;
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, 0, 0, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
