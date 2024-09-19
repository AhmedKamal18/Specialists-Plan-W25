#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const char nl = '\n';

const int N = 501, K = 501;
int n, k;
int a[N];
bool dp[N][K][K], vis[N][K][K];

bool go(int i, int sum, int sub_sum){
    if (i == n) return sum == 0 && sub_sum == 0;
    if (vis[i][sum][sub_sum]) return dp[i][sum][sub_sum];
    vis[i][sum][sub_sum] = 1;
    bool ans = go(i + 1, sum , sub_sum); // leave subset
    if (sum >= a[i]){
        if (sum - a[i] >= sub_sum) { // take subset, leave sub-subset
            ans |= go(i + 1, sum - a[i], sub_sum);
        }
        if (sub_sum >= a[i]){ // take subset, take sub-subset
            ans |= go(i + 1, sum - a[i], sub_sum - a[i]);
        }
    }
    return dp[i][sum][sub_sum] = ans;
}

void solve_rec(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    vector<int> sums;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= j; ++l) {
                go(i, j, l);
            }
        }
    }
    for (int i = 0; i <= k; ++i) {
        if (go(0, k, i)) sums.push_back(i);
    }
    cout << sums.size() << nl;
    for(int& sum: sums) cout << sum << " ";
}

void solve_iter(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[n][0][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int sum = 0; sum <= k; ++sum) {
            for (int sub_sum = 0; sub_sum <= sum; ++sub_sum) {
                dp[i][sum][sub_sum] = dp[i + 1][sum][sub_sum]; // leave subset
                if (sum >= a[i]){
                    if (sum - a[i] >= sub_sum) { // take subset, leave sub-subset
                        dp[i][sum][sub_sum] |= dp[i + 1][sum - a[i]][sub_sum];
                    }
                    if (sub_sum >= a[i]){ // take subset, take sub-subset
                        dp[i][sum][sub_sum] |= dp[i + 1][sum - a[i]][sub_sum - a[i]];
                    }
                }
            }
        }
    }
    vector<int> sums;
    for (int i = 0; i <= k; ++i) {
        if (dp[0][k][i]) sums.push_back(i);
    }
    cout << sums.size() << nl;
    for(int& sum: sums) cout << sum << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve_rec();
}
