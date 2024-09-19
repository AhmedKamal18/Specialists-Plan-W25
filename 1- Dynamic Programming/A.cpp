#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
#define int long long
void solve(){
    int n , w;
    cin >> n >> w;
    vector<pair<int , int>> a(n);
    for (int i = 0;i < n;i++) cin >> a[i].first >> a[i].second;
    vector dp(n + 10 , vector(1e5 +10 , -1ll));
    auto go = [&](auto && go , int idx , int weight)->int{
        if (idx == n) return 0;
        if (~dp[idx][weight]) return dp[idx][weight];
        int take = 0;
        if (weight + a[idx].first <= w) take = go(go , idx + 1 , weight + a[idx].first) + a[idx].second;
        int leave =  go(go , idx + 1 , weight);
        return dp[idx][weight] = max(take , leave);
    };
    cout << go(go , 0 , 0);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    while(t--)
    solve();
}
