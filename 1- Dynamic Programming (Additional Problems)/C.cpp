#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353 , offset = 90000;
void solve(){
    vector dp(301 , vector(300 * 300 * 2 + 10 , -1ll));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto go = [&](auto && go , int idx , int last)->int{
        if (idx == n - 1) return 1;
        if (~dp[idx][last]) return dp[idx][last];
        ll ans = 0;
        last-=offset;
        if (last == 0) ans = go(go , idx + 1 , a[idx + 1] + offset) % mod;
        else ans = (go(go , idx + 1 , a[idx + 1] + last + offset) % mod + go(go , idx + 1 , a[idx + 1] - last + offset) % mod)%mod;
        return dp[idx][last + offset] = ans;
    };
    cout << go(go , 0 , offset);

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    while(t--)
    solve();
}
