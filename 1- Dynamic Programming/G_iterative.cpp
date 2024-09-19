#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 1e4, mod = 1e9 + 7;
int dp[4][3][2][2], ndp[4][3][2][2], a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, 0, sizeof dp);
    memset(ndp, 0, sizeof ndp);
    dp[3][2][1][1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int c2 = 0; c2 <= 3; c2++) {
            for (int c3 = 0; c3 <= 2; c3++) {
                for (int c5 = 0; c5 <= 1; c5++) {
                    for (int c7 = 0; c7 <= 1; c7++) {
                        ndp[c2][c3][c5][c7] = dp[c2][c3][c5][c7];
                        vector<int> cnt(8);
                        int x = a[i];
                        for (int j : {2, 3, 5, 7}) {
                            while (x % j == 0) cnt[j]++, x /= j;
                        }
                        (ndp[c2][c3][c5][c7] += dp[min(c2 + cnt[2], 3)][min(c3 + cnt[3], 2)][min(c5 + cnt[5], 1)][min(c7 + cnt[7], 1)]) %= mod;
                    }
                }
            }
        }
        swap(dp, ndp);
    }
    cout << dp[0][0][0][0];
}
