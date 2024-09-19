#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int dp[1000001];
void solve(){
    int n , x;
    cin >> n >> x;
    int a[n];
    for (int i = 0;i<n;i++) cin >> a[i];
    memset(dp , -1 ,sizeof dp);
    function<int(int)> go = [&](int sum)->int{
        if (sum<0) return 0;
        else if (sum == 0) return 1;
        if (~dp[sum]) return dp[sum];
        int ans = 0;
        for (int i =0;i<n;i++){
            ans+=go(sum-a[i]);
            ans%=mod;
        }
        return dp[sum]= ans;
    };
    cout << go(x)<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    while(t--)
        solve();
}
