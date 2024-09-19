#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define int long long
int dp[1000001];
void solve(){
    int n , x;
    cin >> n >> x;
    int a[n];
    for (int i = 0;i<n;i++) cin >> a[i];
    memset(dp , -1 ,sizeof dp);
    function<int(int)> go = [&](int sum)->int{
        if (sum<0) return 1e18;
        else if (sum == 0) return 0;
        if (~dp[sum]) return dp[sum];
        int ans = 1e18;
        for (int i =0;i<n;i++){
            ans=min(ans , go(sum-a[i])  + 1);
        }
        return dp[sum]= ans;
    };
    cout << (go(x) == 1e18 ? - 1 : go(x))<<'\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    while(t--)
        solve();
}
