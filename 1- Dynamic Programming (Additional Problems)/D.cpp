#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

const int N = 2999 + 1;
double dp[N][N];
int n;
double p[N];

double go(int i, int j){
    if (i == n) return j * 2 > n;
    if (dp[i][j] != -1) return dp[i][j];
    double ans = p[i] * go(i + 1, j + 1) + (1 - p[i]) * go(i + 1, j);
    return dp[i][j] = ans;
}

void solve_rec(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = -1;

    cout << fixed << setprecision(10) << go(0, 0) << nl;
}

void solve_iter(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = n; i * 2 > n; --i) dp[n][i] = 1;
    for (int i = n - 1; i >= 0; --i){
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = p[i] * dp[i + 1][j + 1] + (1 - p[i]) * dp[i + 1][j];
        }
    }
    cout << fixed << setprecision(10) << dp[0][0] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve_rec();
}
